#include "pch.h"
#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height)
{
    return this->renderWindow.InitWindow(this, hInstance, title, windowClass, width, height);
}

void Engine::Run()
{
    while (this->ProcessMessages())
    {
        this->Update();
    }
}

void Engine::Update()
{
    Keyboard::State ks = keyboard->GetState();
    if (ks.Escape)
    {
        this->renderWindow.Quit();
    }

    Mouse::State ms = mouse->GetState();
}

