#pragma once

class Lurker
{
public:
    static bool Init(int)     { return false; }
    static void Move(int, int) {}
    static void simulateClick() {}
    static void PressTheLeft()  {}
    static void PopUpTheLeft()  {}
    static void Close()         {}
};
