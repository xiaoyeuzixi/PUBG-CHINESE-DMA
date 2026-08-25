#include "kmboxBplus.h"

// 查找Kmbox（遍历COM1-COM20）
std::string KmboxBPlus::findKmbox() {
    for (int i = 1; i <= 20; i++) {
        std::string portName = "COM" + std::to_string(i);
        std::string devicePath = "\\\\.\\" + portName;

        HANDLE hTest = CreateFileA(
            devicePath.c_str(),
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            NULL
        );

        if (hTest != INVALID_HANDLE_VALUE) {
            DCB dcb = { 0 };
            dcb.DCBlength = sizeof(DCB);
            GetCommState(hTest, &dcb);
            dcb.BaudRate = CBR_115200;
            dcb.ByteSize = 8;
            dcb.Parity   = NOPARITY;
            dcb.StopBits = ONESTOPBIT;
            SetCommState(hTest, &dcb);

            COMMTIMEOUTS to = { 0 };
            to.ReadIntervalTimeout         = MAXDWORD;
            to.ReadTotalTimeoutMultiplier  = 0;
            to.ReadTotalTimeoutConstant    = 100;
            SetCommTimeouts(hTest, &to);

            DWORD bytesWritten;
            const char* testCmd = "km.version()\r\n";
            WriteFile(hTest, testCmd, (DWORD)strlen(testCmd), &bytesWritten, NULL);

            char buffer[256] = { 0 };
            DWORD bytesRead = 0;
            ReadFile(hTest, buffer, sizeof(buffer) - 1, &bytesRead, NULL);

            CloseHandle(hTest);

            std::string response(buffer, bytesRead);
            if (response.find(">>>") != std::string::npos ||
                response.find("km") != std::string::npos) {
                return portName;
            }
        }
    }
    return "";
}

KmboxBPlus::KmboxBPlus(const std::string& comPort)
    : m_hCom(INVALID_HANDLE_VALUE) {
    std::string port = comPort;
    if (port.empty()) {
        port = findKmbox();
        if (port.empty()) return;
    }
    openPort(port);
}

KmboxBPlus::~KmboxBPlus() {
    closePort();
}

bool KmboxBPlus::openPort(const std::string& comPort) {
    m_comPort = comPort;
    std::string devicePath = "\\\\.\\" + m_comPort;
    m_hCom = CreateFileA(
        devicePath.c_str(),
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (m_hCom == INVALID_HANDLE_VALUE) return false;

    DCB dcb = { 0 };
    dcb.DCBlength = sizeof(DCB);
    GetCommState(m_hCom, &dcb);
    dcb.BaudRate = CBR_115200;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    SetCommState(m_hCom, &dcb);

    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    SetCommTimeouts(m_hCom, &timeouts);

    return true;
}

bool KmboxBPlus::sendCommand(const std::string& cmd) {
    if (!isConnected()) return false;

    std::string fullCmd = cmd + "\r\n";
    DWORD bytesWritten;

    BOOL result = WriteFile(
        m_hCom,
        fullCmd.c_str(),
        fullCmd.length(),
        &bytesWritten,
        NULL
    );

    if (!result || bytesWritten != fullCmd.length()) return false;

    // 等待命令执行
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return true;
}

std::string KmboxBPlus::readResponse(int timeoutMs) {
    if (!isConnected()) return "";
    char buffer[256] = { 0 };
    DWORD bytesRead;
    if (ReadFile(m_hCom, buffer, sizeof(buffer) - 1, &bytesRead, NULL))
        return std::string(buffer, bytesRead);
    return "";
}

void KmboxBPlus::closePort() {
    if (m_hCom != INVALID_HANDLE_VALUE) {
        CloseHandle(m_hCom);
        m_hCom = INVALID_HANDLE_VALUE;
    }
}

bool KmboxBPlus::mouseMove(int x, int y) {
    std::ostringstream oss;
    oss << "km.move(" << x << ", " << y << ")";
    return sendCommand(oss.str());
}

bool KmboxBPlus::mouseMoveRelative(int dx, int dy) {
    std::ostringstream oss;
    oss << "km.moveR(" << dx << ", " << dy << ")";
    return sendCommand(oss.str());
}
