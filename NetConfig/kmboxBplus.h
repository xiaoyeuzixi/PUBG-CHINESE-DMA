#pragma once
/**
 * KmboxBPlus — KmBox B/B+ 串口控制类
 *
 * 协议：ASCII 命令 over 虚拟 COM 口 @ 115200 波特率
 * 格式：km.xxx(args)\r\n （适配 KMBox B/B+ 协议）
 *
 * 依赖：Windows API、C++11 STL
 */

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <windows.h>
#include <string>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <cstring>

class KmboxBPlus {
private:
    HANDLE m_hCom = INVALID_HANDLE_VALUE;
    std::string m_comPort;

public:
    KmboxBPlus() {
        m_hCom = INVALID_HANDLE_VALUE;
    }

    KmboxBPlus(const std::string& comPort);

    ~KmboxBPlus();

    /** 遍历 COM1-20 查找 kmbox 设备，返回端口名 */
    static std::string findKmbox();

    /** 打开指定串口 */
    bool openPort(const std::string& comPort);

    /** 关闭串口 */
    void closePort();

    /** 是否已连接 */
    bool isConnected() const { return m_hCom != INVALID_HANDLE_VALUE; }

    /** 发送命令字符串（自动追加 \r\n） */
    bool sendCommand(const std::string& cmd);

    /** 读取响应 */
    std::string readResponse(int timeoutMs = 50);

    /** 鼠标绝对移动 */
    bool mouseMove(int x, int y);

    /** 鼠标相对移动 */
    bool mouseMoveRelative(int dx, int dy);

    /** 获取当前串口名 */
    const std::string& getPortName() const { return m_comPort; }
};
