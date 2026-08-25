#pragma once
#include <windows.h>

class KmBox
{
public:
    static bool Init(int com);
    static void MortarWheel(int state);
    static void Move(int x, int y);
    static void simulateClick();
    static void PressTheLeft();
    static void PopUpTheLeft();
    static void Close();
    static void Clear();
    static void SetFreq(int freq);
    static void SetScreen(int w, int h);
    static void Delay(int time);
};
