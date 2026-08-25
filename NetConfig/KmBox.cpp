#include "COM.h"
#include "KmBox.h"
#include <cstdio>
#include <thread>

static _com myserial;

void KmBox::SetFreq(int freq)
{
    char buff[1024];
    snprintf(buff, sizeof(buff), "km.freq(%d)\r\n", freq);
    myserial.write(buff);
}

void KmBox::SetScreen(int w, int h)
{
    char buff[1024];
    snprintf(buff, sizeof(buff), "km.screen(%d, %d)\r\n", w, h);
    myserial.write(buff);
}

void KmBox::Delay(int time)
{
    char buff[1024];
    snprintf(buff, sizeof(buff), "km.delay(%d)\r\n", time);
    myserial.write(buff);
}

bool KmBox::Init(int com)
{
    bool isOpen = myserial.open(com, 115200);
    char ctrlC = 0x03;
    char ctrlD = 0x04;
    myserial.write(&ctrlC, 1);
    Sleep(100);
    SetFreq(1000);
    Sleep(100);
    return isOpen;
}

void KmBox::simulateClick()
{
    char buff[1024];
    snprintf(buff, sizeof(buff), "km.click(0)\r\n");
    myserial.write(buff);
}

void KmBox::PressTheLeft()
{
    char buff[1024];
    snprintf(buff, sizeof(buff), "km.left(1)\r\n");
    myserial.write(buff);
}

void KmBox::PopUpTheLeft()
{
    char buff[1024];
    snprintf(buff, sizeof(buff), "km.left(0)\r\n");
    myserial.write(buff);
}

void KmBox::MortarWheel(int state)
{
    char buff[120];
    snprintf(buff, sizeof(buff), "km.wheel(%d)\r", state);
    myserial.write(buff);
}

void KmBox::Close()
{
    myserial.close();
}

void KmBox::Move(int x, int y)
{
    char buff[1024];
    snprintf(buff, sizeof(buff), "km.move(%d,%d)\r\n", x, y);
    myserial.write(buff);
}

void KmBox::Clear()
{
    char ctrlC = 0x03;
    myserial.write(&ctrlC, 1);
}
