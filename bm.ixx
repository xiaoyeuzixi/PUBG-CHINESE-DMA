module;
#include <Windows.h>

export module bm;
import std;

export class bm {
public:
	static std::string bm_wstrTostr_ansi(std::wstring wstr);

	static std::string bm_wstrTostr_utf8(std::wstring wstr);


};

std::string bm::bm_wstrTostr_ansi(std::wstring wstr)
{
    int buffer_size = WideCharToMultiByte(CP_ACP, 0, wstr.data(), -1, nullptr, 0, nullptr, nullptr);
    std::string result(buffer_size, 0);
    WideCharToMultiByte(CP_ACP, 0, wstr.data(), -1, result.data(), buffer_size, nullptr, nullptr);

    result.pop_back();
    return result;
}

std::string bm::bm_wstrTostr_utf8(std::wstring wstr)
{

    int buffer_size = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), -1, nullptr, 0, nullptr, nullptr);

    if (buffer_size <= 0) {
        return "";
    }
    std::string result(buffer_size, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.data(), -1, result.data(), buffer_size, nullptr, nullptr);
    
    result.pop_back();
    return result;
}
