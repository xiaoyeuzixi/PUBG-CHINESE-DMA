module;
#include <windows.h>
#include <string>

export module Registry;

import dma;

export enum class e_registry_type {
    none = 0,
    sz = 1,
    expand_sz = 2,
    binary = 3,
    dword = 4,
    dword_little_endian = 4,
    dword_big_endian = 5,
    link = 6,
    multi_sz = 7,
    resource_list = 8,
    full_resource_descriptor = 9,
    resource_requirements_list = 10,
    qword = 11,
    qword_little_endian = 11
};

// 手动声明需要的 VMMDLL 函数
extern "C" {
    typedef void* VMMDLL_HANDLE;
    __declspec(dllimport) bool VMMDLL_WinReg_QueryValueExU(VMMDLL_HANDLE hVMM, LPSTR szKeyPath, DWORD *pdwType, PBYTE lpData, DWORD *lpcbData);
}

export class c_registry {
public:
    std::string QueryValue(const std::string& path, e_registry_type type) {
        if (!dma::get_hVMM()) return "";

        DWORD _type = (DWORD)type;
        DWORD size = 0;
        
        // 获取大小
        VMMDLL_WinReg_QueryValueExU(dma::get_hVMM(), const_cast<LPSTR>(path.c_str()), &_type, nullptr, &size);
        if (size == 0) return "";

        if (type == e_registry_type::sz || type == e_registry_type::expand_sz) {
            std::string buffer;
            buffer.resize(size);
            if (VMMDLL_WinReg_QueryValueExU(dma::get_hVMM(), const_cast<LPSTR>(path.c_str()), &_type, (PBYTE)buffer.data(), &size)) {
                // 移除末尾的空字符
                while (!buffer.empty() && buffer.back() == '\0') buffer.pop_back();
                return buffer;
            }
        }
        else if (type == e_registry_type::dword) {
            DWORD value = 0;
            if (VMMDLL_WinReg_QueryValueExU(dma::get_hVMM(), const_cast<LPSTR>(path.c_str()), &_type, (PBYTE)&value, &size)) {
                return std::to_string(value);
            }
        }

        return "";
    }
};
