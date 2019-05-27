#pragma once
#include "RenderWindow.h"
#include "Timer.h"
#include <d3d11.h>
#include "Graphics.h"
#include "SimpleMath.h"
#include "GamePad.h"
#include "Keyboard.h"
#include "Mouse.h"

using namespace std;
using namespace DirectX;

class EngineWindowsApp
{
protected:
    RenderWindow renderWindow;
    Timer timer;
    Graphics gfx;
    unique_ptr<GamePad> gamePad;
    unique_ptr<Keyboard> keyboard;
    unique_ptr<Mouse> mouse;
    float pitch;
    float yaw;
public:
    EngineWindowsApp();
    bool ProcessMessages();
};
