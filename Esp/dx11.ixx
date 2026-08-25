module;
#include <tchar.h>
#include <d3d11.h>
#include <dwmapi.h>
#include <d3dkmthk.h>
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"


extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
void UpdateWindowTransparent(HWND hwnd);

// Global Variables
WNDCLASSEX m_wc;
static ID3D11Device* g_pd3dDevice = nullptr;
static ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
static IDXGISwapChain* g_pSwapChain = nullptr;
static ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;
static bool                     g_SwapChainOccluded = false;
static UINT                     g_ResizeWidth = 0, g_ResizeHeight = 0;

export module dx11;

export namespace dx11 {
    void SetWindowTransparency();

    bool init(int x, int y, int w, int h);
    void clean();

    void Begin();
    void End();

    HWND m_hwnd;

    bool transparent = true;

};

void dx11::SetWindowTransparency() {
    transparent = !transparent;
    if (transparent) {
        // 开启透明
        MARGINS margins = { -1 };
        DwmExtendFrameIntoClientArea(m_hwnd, &margins);
        SetLayeredWindowAttributes(m_hwnd, 0, 255, LWA_ALPHA);
    }
    else {
        // 关闭透明
        MARGINS margins = { 0 };
        DwmExtendFrameIntoClientArea(m_hwnd, &margins);
        SetLayeredWindowAttributes(m_hwnd, 0, 255, LWA_ALPHA);
    }
}

bool dx11::init(int x, int y, int w, int h)
{
    // Register window class
    ImGui_ImplWin32_EnableDpiAwareness();
    float main_scale = ImGui_ImplWin32_GetDpiScaleForMonitor(::MonitorFromPoint(POINT{ 0, 0 }, MONITOR_DEFAULTTOPRIMARY));
    m_wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0, 0,GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L" ", nullptr };
    ::RegisterClassEx(&m_wc);
    auto setStyle = WS_EX_LAYERED;// WS_EX_TOPMOST | WS_EX_TOOLWINDOW |


    // Create window with WS_POPUP and layered styles for transparency
    m_hwnd = ::CreateWindowEx(setStyle, m_wc.lpszClassName, _T(" "), WS_POPUP, x, y, (int)(w * main_scale), (int)(h * main_scale), nullptr, nullptr, m_wc.hInstance, nullptr);


    SetWindowTransparency();

    // Initialize Direct3D
    if (!CreateDeviceD3D(m_hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(m_wc.lpszClassName, m_wc.hInstance);
        return false;
    }

    // Show the window
    ShowWindow(m_hwnd, SW_SHOWDEFAULT);
    UpdateWindow(m_hwnd);

    SetWindowPos(m_hwnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;


    static const ImWchar chineseRanges[] = { 0x0020, 0x00FF, 0x4e00, 0x9FA5, 0 };
    io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\msyh.ttc", 18, nullptr, chineseRanges);


    // Setup ImGui style
    ImGui::StyleColorsLight();

    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(main_scale);        // Bake a fixed style scale. (until we have a solution for dynamic style scaling, changing this requires resetting Style + calling this again)
    style.FontScaleDpi = main_scale;        // Set initial font scale. (using io.ConfigDpiScaleFonts=true makes this unnecessary. We leave both here for documentation purpose)


    // Initialize ImGui Win32 + DX11 implementations
    ImGui_ImplWin32_Init(m_hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);



    D3DKMTSetProcessSchedulingPriorityClass(GetCurrentProcess(), D3DKMT_SCHEDULINGPRIORITYCLASS_REALTIME);

    return true;
}


void dx11::Begin() {


    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }
    if (msg.message == WM_QUIT) {
        return;

    }


    if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
    {
        CleanupRenderTarget();
        g_pSwapChain->ResizeBuffers(0, g_ResizeWidth, g_ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
        g_ResizeWidth = g_ResizeHeight = 0;
        CreateRenderTarget();
    }



    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    if (transparent) {
        UpdateWindowTransparent(m_hwnd);
    }






}

void dx11::End() {

    ImGui::Render();


    ImVec4 clear_color = ImVec4(0, 0, 0, 0); // Fully transparent clear color
    g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
    g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)&clear_color);


    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    // Present
    HRESULT hr = g_pSwapChain->Present(0, 0);   // Present with vsync
    //HRESULT hr = g_pSwapChain->Present(0, 0); // Present without vsync
    g_SwapChainOccluded = (hr == DXGI_STATUS_OCCLUDED);

}

void dx11::clean() {

    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    ::CleanupDeviceD3D();
    ::DestroyWindow(m_hwnd);
    ::UnregisterClass(m_wc.lpszClassName, m_wc.hInstance);
}


bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain description
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; // BGRA with Alpha channel support
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; // Important for transparency

    UINT createDeviceFlags = 0;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };

    HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd,
        &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);

    if (FAILED(hr))
        return false;

    CreateRenderTarget();
    return true;
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (g_mainRenderTargetView)
    {
        g_mainRenderTargetView->Release();
        g_mainRenderTargetView = NULL;
    }
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}


bool IsMouseOnAnyInteractiveWindow(const ImVec2& pos)
{
    ImGuiContext* ctx = ImGui::GetCurrentContext();
    if (!ctx) return false;

    for (int i = 0, n = ctx->Windows.Size; i < n; ++i)
    {
        ImGuiWindow* window = ctx->Windows[i];
        if (!window || !window->WasActive || (window->Flags & ImGuiWindowFlags_NoInputs))
            continue;

        ImRect winRect(window->Pos, ImVec2(window->Pos.x + window->Size.x, window->Pos.y + window->Size.y));
        if (winRect.Contains(pos))
            return true;
    }
    return false;
}

void UpdateWindowTransparent(HWND hwnd)
{

    POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(hwnd, &pt);
    ImVec2 mousePos((float)pt.x, (float)pt.y);

    bool mouse_on_ui = IsMouseOnAnyInteractiveWindow(mousePos);

    LONG exStyle = GetWindowLongW(hwnd, GWL_EXSTYLE);
    bool isTransparent = (exStyle & WS_EX_TRANSPARENT) != 0;


    if (mouse_on_ui && !isTransparent) {
        return;
    }

    if (!mouse_on_ui && isTransparent) {
        return;
    }

    if (!mouse_on_ui)
        exStyle |= WS_EX_TRANSPARENT;
    else {
        exStyle &= ~WS_EX_TRANSPARENT;
    }
    SetWindowLong(hwnd, GWL_EXSTYLE, exStyle);


    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}



// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        g_ResizeWidth = (UINT)LOWORD(lParam); // Queue resize
        g_ResizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}


export namespace imguiColor {

    inline constexpr ImU32 White = IM_COL32(255, 255, 255, 255);
    inline constexpr ImU32 White100 = IM_COL32(255, 255, 255, 100);
    inline constexpr ImU32 Green = IM_COL32(0, 255, 0, 255);
    inline constexpr ImU32 Blue = IM_COL32(0, 120, 255, 255);
    inline constexpr ImU32 Purple = IM_COL32(153, 0, 255, 255);
    inline constexpr ImU32 Gold = IM_COL32(255, 215, 0, 255);
    inline constexpr ImU32 Red = IM_COL32(255, 0, 0, 255);

    inline constexpr ImU32 LightBlue = IM_COL32(173, 216, 230, 255);
    inline constexpr ImU32 LightBlue150 = IM_COL32(173, 216, 230, 150);
    inline constexpr ImU32 Cyan = IM_COL32(0, 255, 255, 255);
    inline constexpr ImU32 Orange = IM_COL32(255, 165, 0, 255);
    inline constexpr ImU32 Pink = IM_COL32(255, 105, 180, 255);
    inline constexpr ImU32 DarkRed = IM_COL32(139, 0, 0, 255);

    inline constexpr ImU32 SolidGray = IM_COL32(128, 128, 128, 255);
    inline constexpr ImU32 Black180 = IM_COL32(0, 0, 0, 180);
    inline constexpr ImU32 LightGray150 = IM_COL32(200, 200, 200, 150);
    inline constexpr ImU32 MediumGray150 = IM_COL32(150, 150, 150, 150);
    inline constexpr ImU32 DarkGray150 = IM_COL32(100, 100, 100, 150);

    inline constexpr ImU32 Shield = IM_COL32(243, 124, 109, 255);
}

export ImU32 ImVec4ToImU32(const ImVec4& color) {
    return IM_COL32(
        (int)(color.x * 255.0f),  // R: 0-1 -> 0-255
        (int)(color.y * 255.0f),  // G: 0-1 -> 0-255
        (int)(color.z * 255.0f),  // B: 0-1 -> 0-255
        (int)(color.w * 255.0f)   // A: 0-1 -> 0-255
    );
};