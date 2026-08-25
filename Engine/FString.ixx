module;
#include <Windows.h>
#include <cwchar>

export module FString;
import TArray;
import std;
import dma;

export class FString :public TArray<wchar_t> {
public:
    using TArray::TArray;

    std::string read_string_utf8();

    std::string read_string_ansi();

    std::string read_string_gbk();

    std::wstring read_wstring();

};

std::string FString::read_string_utf8()
{

    std::wstring wstr = read_wstring();
    if (wstr.empty()) {
        return "";
    }

    int buffer_size = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), -1, nullptr, 0, nullptr, nullptr);

    if (buffer_size <= 0) {
        return "";
    }
    std::string result(buffer_size, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.data(), -1, result.data(), buffer_size, nullptr, nullptr);
    return result;
}

std::string FString::read_string_ansi()
{
    std::wstring wstr = read_wstring();
    if (wstr.empty()) {
        return "";
    }

    int buffer_size = WideCharToMultiByte(CP_ACP, 0, wstr.data(), -1, nullptr, 0, nullptr, nullptr);
    std::string result(buffer_size, 0);
    WideCharToMultiByte(CP_ACP, 0, wstr.data(), -1, result.data(), buffer_size, nullptr, nullptr);

    result.pop_back();
    return result;
}


std::string FString::read_string_gbk()
{
    if (NumElements <= 0 || NumElements > 1000) {
        return "";
    }

    // 读取原始ANSI数据
    std::vector<char> buffer(NumElements + 1, 0);
    dma::Read(Data, buffer.data(), NumElements);

    // 如果是控制台程序，可能需要转换代码页
    std::string result(buffer.data());

    // 如果是GBK编码，可以直接返回
    return result;
}


std::wstring FString::read_wstring()
{

    if (NumElements <= 0 || NumElements > 1000) {  // 增加上限
        return L"";
    }

    std::wstring result;
    result.resize(NumElements);
    dma::Read(Data, result.data(), NumElements * sizeof(wchar_t));
    return result;
}
