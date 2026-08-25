#include "MoBox.h"
#include <cstdio>

static HMODULE kmdll = nullptr;
typedef void (*SetScreenScale)(int, int);
typedef int  (*OpenDevice)(const char*);
typedef void (*EnableAccurateDelay)();
typedef void (*CloseDevice)();
typedef void (*MoveR)(int, int);

static OpenDevice           MoOpenDevice = nullptr;
static SetScreenScale       MoSetScreenScale = nullptr;
static EnableAccurateDelay  MoEnableAccurateDelay = nullptr;
static CloseDevice          MoCloseDevice = nullptr;
static MoveR                MoMoveR = nullptr;

bool MoBox::Init(int com)
{
    kmdll = LoadLibrary(L"ddll64.dll");
    if (!kmdll) return false;

    MoOpenDevice        = (OpenDevice)GetProcAddress(kmdll, "OpenDevice");
    MoSetScreenScale    = (SetScreenScale)GetProcAddress(kmdll, "SetScreenScale");
    MoEnableAccurateDelay = (EnableAccurateDelay)GetProcAddress(kmdll, "EnableAccurateDelay");
    MoCloseDevice       = (EnableAccurateDelay)GetProcAddress(kmdll, "Close");
    MoMoveR             = (MoveR)GetProcAddress(kmdll, "MoveR");

    if (!MoOpenDevice || !MoSetScreenScale || !MoEnableAccurateDelay || !MoCloseDevice || !MoMoveR)
        return false;

    char comStr[10];
    snprintf(comStr, sizeof(comStr), "COM%d", com);
    int ret = MoOpenDevice(comStr);
    if (!ret) return false;

    // Use typical 1920x1080 as default screen
    MoSetScreenScale(1920, 1080);
    MoEnableAccurateDelay();
    return true;
}

void MoBox::Move(int x, int y) { if (MoMoveR) MoMoveR(x, y); }
void MoBox::simulateClick() {}
void MoBox::PressTheLeft() {}
void MoBox::PopUpTheLeft() {}
void MoBox::Close() { if (MoCloseDevice) MoCloseDevice(); }
