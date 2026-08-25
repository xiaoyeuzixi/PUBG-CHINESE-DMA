module;
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <vector>
#include <string>

export module InputUtils;

import InputDMA;

export namespace InputUtils {
    void UpdateInput() {
        InputDMA::Get().Update();
    }

    bool InitInputDMA() {
        return InputDMA::Get().Init();
    }

    bool check_single_key(int vk_key) {
        if (vk_key == 0) return false;
        //  检测副机按键
        if (GetAsyncKeyState(vk_key) & 0x8000) return true;

        // 检测 DMA 主机按键
        if (InputDMA::Get().IsKeyDown(vk_key)) return true;

        return false;
    }

    bool is_key_pressed(int vk_key) {
        if (vk_key == 0) return false;
        //  检测 副机
        if (GetAsyncKeyState(vk_key) & 1) return true;

        //  检测 DMA 主机
        if (InputDMA::Get().WasKeyPressed(vk_key)) return true;

        return false;
    }
}
