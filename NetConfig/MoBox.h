#pragma once
#include <windows.h>

class MoBox
{
public:
    static bool Init(int com);
    static void Move(int x, int y);
    static void simulateClick();
    static void PressTheLeft();
    static void PopUpTheLeft();
    static void Close();
};
