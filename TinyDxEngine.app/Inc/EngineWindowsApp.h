#pragma once
#include "RenderWindow.h"
#include <d3d11.h>
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
    unique_ptr<GamePad> gamePad;
    unique_ptr<Keyboard> keyboard;
    unique_ptr<Mouse> mouse;
    float pitch;
    float yaw;
public:
    EngineWindowsApp();
    bool ProcessMessages();
};
