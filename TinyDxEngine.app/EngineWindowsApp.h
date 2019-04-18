#pragma once
#include "RenderWindow.h"
#include "Keyboard.h"
#include "Mouse.h"

using namespace std;
using namespace DirectX;

class EngineWindowsApp
{
protected:
    RenderWindow renderWindow;
    unique_ptr<Keyboard> keyboard;
    unique_ptr<Mouse> mouse;
public:
    EngineWindowsApp();
    bool ProcessMessages();
};
