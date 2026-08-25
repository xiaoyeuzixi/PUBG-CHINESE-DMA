module;
#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cstdint>

// 定义缺失的宏
#ifndef VMMDLL_PID_PROCESS_WITH_KERNELMEMORY
#define VMMDLL_PID_PROCESS_WITH_KERNELMEMORY 0x80000000
#endif

#ifndef VMMDLL_MODULE_FLAG_NORMAL
#define VMMDLL_MODULE_FLAG_NORMAL 0
#endif

#ifndef VMMDLL_FLAG_NOCACHE
#define VMMDLL_FLAG_NOCACHE 0x0001
#endif

export module InputDMA;

import dma;
import Registry;

// 手动声明需要的 VMMDLL 函数
extern "C" {
    typedef void* VMMDLL_HANDLE;
    
    __declspec(dllimport) bool VMMDLL_Map_GetModuleFromNameW(VMMDLL_HANDLE hVMM, DWORD dwPID, LPWSTR wszModuleName, PVMMDLL_MAP_MODULEENTRY *ppModuleMapEntry, DWORD flags);
    __declspec(dllimport) bool VMMDLL_Map_GetEATU(VMMDLL_HANDLE hVMM, DWORD dwPID, LPSTR szModuleName, PVMMDLL_MAP_EAT *ppEatMap);
    __declspec(dllimport) void VMMDLL_MemFree(void *pv);
    __declspec(dllimport) bool VMMDLL_MemReadEx(VMMDLL_HANDLE hVMM, DWORD dwPID, unsigned long long qwA, PBYTE pb, DWORD cb, DWORD *pcbReadOpt, unsigned __int64 flags);
    __declspec(dllimport) bool VMMDLL_PdbLoad(VMMDLL_HANDLE hVMM, DWORD dwPID, unsigned long long vaModuleBase, char *szModuleName);
    __declspec(dllimport) bool VMMDLL_PdbSymbolAddress(VMMDLL_HANDLE hVMM, char *szModuleName, char *szSymbolName, unsigned long long *pvaSymbolAddress);
    __declspec(dllimport) bool VMMDLL_WinReg_QueryValueExU(VMMDLL_HANDLE hVMM, LPSTR szKeyPath, DWORD *pdwType, PBYTE lpData, DWORD *lpcbData);
}

export class InputDMA
{
private:
    uint64_t gafAsyncKeyStateExport = 0;
    std::array<std::uint8_t, 64> key_state_bitmap{ };
    std::array<std::uint8_t, 64> previous_state_bitmap{ };

    int win_logon_pid = 0;
    int win_csrss_pid = 0;
    
    c_registry registry;

    int Winver = 0;

    std::string TranslateEdition(const std::string& edition) {
        if (edition == "Professional") return "专业版";
        if (edition == "Enterprise") return "企业版";
        if (edition == "Home") return "家庭版";
        if (edition == "Education") return "教育版";
        if (edition == "CoreSingleLanguage") return "家庭中文版";
        if (edition == "Core") return "家庭版";
        if (edition == "ServerStandard") return "服务器标准版";
        if (edition == "ServerDatacenter") return "服务器数据中心版";
        return edition;
    }

public:
    InputDMA() = default;
    ~InputDMA() = default;

    static InputDMA& Get() {
        static InputDMA instance;
        return instance;
    }

    bool Init()
    {
        if (!dma::get_hVMM()) return false;

        int ubr = 0;
        DWORD _type = (DWORD)e_registry_type::dword;
        DWORD size = sizeof(ubr);
        VMMDLL_WinReg_QueryValueExU(dma::get_hVMM(), const_cast <LPSTR>("HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\UBR"), &_type, (PBYTE)&ubr, &size);
        
        std::string win = registry.QueryValue("HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\CurrentBuild", e_registry_type::sz);
        if (!win.empty()) {
            try {
                Winver = std::stoi(win);
            }
            catch (...) {
                return false;
            }
        }
        else {
            return false;
        }
        
        this->win_logon_pid = dma::GetPidFromName("winlogon.exe");

        // 获取系统版本信息用于调试输出
        std::string displayVersion = registry.QueryValue("HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\DisplayVersion", e_registry_type::sz);
        std::string editionID = registry.QueryValue("HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\EditionID", e_registry_type::sz);
        
        std::string versionName = "Windows 10";
        if (Winver >= 22000) versionName = "Windows 11";
        if (!editionID.empty()) versionName += " " + TranslateEdition(editionID);

        std::cout << "[DMA Input] 系统: " << versionName << " Build:" << Winver << "." << ubr << std::endl;

        // 尝试初始化 Windows 11
        if (Winver > 22000) 
        {
            if (InitWin11()) return true;
            std::cout << "[DMA Input] Win11 初始化失败，尝试使用 Win10 方法..." << std::endl;
        }

        // 尝试初始化 Windows 10 (或 Win11 失败后的回退)
        if (InitWin10()) return true;

        std::cout << "[DMA Input] 初始化失败" << std::endl;
        return false;
    }

private:
    bool InitWin11()
    {
        auto pids = dma::GetPidListFromName("csrss.exe");
        for (size_t i = 0; i < pids.size(); i++)
        {
            auto pid = pids[i];

            PVMMDLL_MAP_MODULEENTRY win32k_module_info;
            bool found = false;
            if (Winver >= 26100) // Windows 11 24H2+
            {
                found = VMMDLL_Map_GetModuleFromNameW(dma::get_hVMM(), pid, const_cast<LPWSTR>(L"win32k.sys"), &win32k_module_info, VMMDLL_MODULE_FLAG_NORMAL);
            }
            else // Windows 11 22H2
            {
                if (!VMMDLL_Map_GetModuleFromNameW(dma::get_hVMM(), pid, const_cast<LPWSTR>(L"win32ksgd.sys"), &win32k_module_info, VMMDLL_MODULE_FLAG_NORMAL))
                {
                    if (!VMMDLL_Map_GetModuleFromNameW(dma::get_hVMM(), pid, const_cast<LPWSTR>(L"win32k.sys"), &win32k_module_info, VMMDLL_MODULE_FLAG_NORMAL))
                    {
                        continue;
                    }
                }
                found = true;
            }
            
            if (!found) continue;

            uintptr_t win32k_base = win32k_module_info->vaBase;
            size_t win32k_size = win32k_module_info->cbImageSize;

            uintptr_t g_session_ptr = 0;
            if (Winver >= 26100)
            {
                g_session_ptr = dma::FindSignature("48 8B 05 ? ? ? ? FF C9 48 8B 04 C8 C3", win32k_base, win32k_base + win32k_size, pid);
            }
            else
            {
                g_session_ptr = dma::FindSignature("EB ? 8D 48 FF 48 8B ? ? ? ? ? 48 8B 04", win32k_base, win32k_base + win32k_size, pid);
                if (g_session_ptr)
                {
                    g_session_ptr += 5;
                }
                else
                {
                    g_session_ptr = dma::FindSignature("48 8B 05 ? ? ? ? 48 8B 04 C8", win32k_base, win32k_base + win32k_size, pid);
                }
            }

            if (!g_session_ptr) continue;

            int relative = dma::Read<int>(g_session_ptr + 3, pid);
            uintptr_t g_session_global_slots = g_session_ptr + 7 + relative;

            uintptr_t user_session_state = 0;
            for (int j = 0; j < 100; j++)
            {
                user_session_state = dma::Read<uintptr_t>(
                    dma::Read<uintptr_t>(
                        dma::Read<uintptr_t>(g_session_global_slots, pid) + j * 8,
                        pid
                    ),
                    pid
                );
                if (user_session_state > 0x7FFFFFFFFFFF)
                    break;
            }

            if (user_session_state == 0) continue;

            PVMMDLL_MAP_MODULEENTRY win32kbase_module_info;
            if (!VMMDLL_Map_GetModuleFromNameW(dma::get_hVMM(), pid, const_cast<LPWSTR>(L"win32kbase.sys"), &win32kbase_module_info, VMMDLL_MODULE_FLAG_NORMAL))
            {
                return false;
            }
            uintptr_t win32kbase_base = win32kbase_module_info->vaBase;
            size_t win32kbase_size = win32kbase_module_info->cbImageSize;

            uintptr_t ptr = 0;
            uint32_t session_offset = 0;

            if (Winver >= 26100)
            {
                ptr = dma::FindSignature("B9 ? ? ? ? ? ? ? ? ? ? ? ? 41 0F ? ? 66", win32kbase_base, win32kbase_base + win32kbase_size, pid);
                if (ptr) session_offset = dma::Read<uint32_t>(ptr + 9, pid);
            }
            else
            {
                ptr = dma::FindSignature("48 8D 90 ? ? ? ? E8 ? ? ? ? 0F 57 C0", win32kbase_base, win32kbase_base + win32kbase_size, pid);
                if (ptr) session_offset = dma::Read<uint32_t>(ptr + 3, pid);
                else
                {
                    ptr = dma::FindSignature("B9 ? ? ? ? ? ? ? ? ? ? ? ? 41 0F ? ? 66", win32kbase_base, win32kbase_base + win32kbase_size, pid);
                    if (ptr) session_offset = dma::Read<uint32_t>(ptr + 9, pid);
                }
            }

            if (!ptr || session_offset == 0) continue;

            gafAsyncKeyStateExport = user_session_state + session_offset;

            if (gafAsyncKeyStateExport > 0x7FFFFFFFFFFF)
            {
                BYTE keyStateBitmap[255];
                if (VMMDLL_MemReadEx(dma::get_hVMM(), pid, gafAsyncKeyStateExport, (PBYTE)&keyStateBitmap, sizeof(keyStateBitmap), nullptr, VMMDLL_FLAG_NOCACHE))
                {
                    {
                        win_csrss_pid = pid;
                        std::cout << "[DMA Input] 初始化成功 (Win11)" << std::endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool InitWin10()
    {
        PVMMDLL_MAP_EAT eat_map = NULL;
        bool result = VMMDLL_Map_GetEATU(dma::get_hVMM(), win_logon_pid | VMMDLL_PID_PROCESS_WITH_KERNELMEMORY, const_cast<LPSTR>("win32kbase.sys"), &eat_map);
        if (!result) return false;

        for (int i = 0; i < eat_map->cMap; i++)
        {
            auto eat_map_entry = eat_map->pMap + i;
            if (strcmp(eat_map_entry->uszFunction, "gafAsyncKeyState") == 0)
            {
                gafAsyncKeyStateExport = eat_map_entry->vaFunction;
                break;
            }
        }
        VMMDLL_MemFree(eat_map);

        if (gafAsyncKeyStateExport < 0x7FFFFFFFFFFF)
        {
            PVMMDLL_MAP_MODULEENTRY module_info;
            wchar_t moduleName[] = L"win32kbase.sys";
            auto result = VMMDLL_Map_GetModuleFromNameW(
                dma::get_hVMM(),
                win_logon_pid | VMMDLL_PID_PROCESS_WITH_KERNELMEMORY,
                moduleName,
                &module_info,
                VMMDLL_MODULE_FLAG_NORMAL
            );
            if (!result) return false;

            char str[256];
            if (!VMMDLL_PdbLoad(dma::get_hVMM(), win_logon_pid | VMMDLL_PID_PROCESS_WITH_KERNELMEMORY, module_info->vaBase, str))
            {
                return false;
            }

            uintptr_t gafAsyncKeyState;
            if (!VMMDLL_PdbSymbolAddress(dma::get_hVMM(), str, const_cast<LPSTR>("gafAsyncKeyState"), &gafAsyncKeyState))
            {
                return false;
            }
            gafAsyncKeyStateExport = gafAsyncKeyState;
        }

        if (gafAsyncKeyStateExport > 0x7FFFFFFFFFFF) {
            std::cout << "[DMA Input] 初始化成功 (Win10)" << std::endl;
            return true;
        }
        return false;
    }

public:
    void Update()
    {
        if (gafAsyncKeyStateExport == 0) return;

        int pid = 0;
        if (Winver > 22000) {
            pid = this->win_csrss_pid;
        }
        else {
            pid = this->win_logon_pid | VMMDLL_PID_PROCESS_WITH_KERNELMEMORY;
        }

        // 保存上一次的状态用于边沿检测
        std::copy(key_state_bitmap.begin(), key_state_bitmap.end(), previous_state_bitmap.begin());

        VMMDLL_MemReadEx(dma::get_hVMM(), pid, gafAsyncKeyStateExport, (PBYTE)key_state_bitmap.data(), 64, NULL, VMMDLL_FLAG_NOCACHE);
    }

    bool IsKeyDown(int vk)
    {
        if (vk < 0 || vk > 255) return false;
        // 索引计算: vk * 2 / 8 -> vk / 4 (字节索引)
        // 位偏移: vk % 4 * 2 (位索引)
        return key_state_bitmap[(vk * 2 / 8)] & (1 << (vk % 4 * 2));
    }

    bool WasKeyPressed(int vk)
    {
        if (vk < 0 || vk > 255) return false;
        bool current = key_state_bitmap[(vk * 2 / 8)] & (1 << (vk % 4 * 2));
        bool previous = previous_state_bitmap[(vk * 2 / 8)] & (1 << (vk % 4 * 2));
        return current && !previous;
    }
};
