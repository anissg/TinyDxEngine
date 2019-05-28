#include "Engine.h"

using namespace std;
using namespace DirectX::SimpleMath;

bool Engine::Initialize(HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height)
{
    if (!this->renderWindow.InitWindow(this, hInstance, title, windowClass, width, height))
        return false;
    
    mouse->SetWindow(renderWindow.GetWindow());
    
    if (!gfx.Initialize(renderWindow.GetWindow(), width, height))
        return false;

    timer.Reset();

    return true;
}

void Engine::Run()
{
    while (this->ProcessMessages())
    {
        this->UpdateInputs();
        this->Update(timer.GetElapsedTime());
        this->Render();
    }
}

void Engine::UpdateInputs()
{
    GamePad::State gs = gamePad->GetState(0);

    if (gs.IsConnected())
    {
        yaw -= gs.thumbSticks.rightX;
        pitch -= gs.thumbSticks.rightY;
    }

    Keyboard::State ks = keyboard->GetState();
    if (ks.Escape)
    {
        this->renderWindow.Quit();
    }

    Mouse::State ms = mouse->GetState();
    if (ms.positionMode == Mouse::MODE_RELATIVE)
    {
        Vector3 delta = Vector3(float(ms.x), float(ms.y), 0.f) * 2; // * ROTATION_GAIN

        pitch -= delta.y;
        yaw -= delta.x;
    }

    // limit pitch to straight up or straight down with a little fudge-factor to avoid gimbal lock
    float limit = XM_PI / 2.0f - 0.01f;
    pitch = max(-limit, pitch);
    pitch = min(+limit, pitch);

    // keep longitude in sane range by wrapping
    if (yaw > XM_PI)
    {
        yaw -= XM_PI * 2.0f;
    }
    else if (yaw < -XM_PI)
    {
        yaw += XM_PI * 2.0f;
    }

    mouse->SetMode(ms.leftButton ? Mouse::MODE_RELATIVE : Mouse::MODE_ABSOLUTE);

    // todo move this to logger
    /*string s = "pitch: ";

    s += to_string(pitch);
    s += " , yaw: ";
    s += to_string(yaw);
    s += "\n";
    OutputDebugStringA(s.c_str());*/
}

void Engine::Update(double elapsedTime)
{
}

void Engine::Render()
{
    gfx.RenderFrame();
}

