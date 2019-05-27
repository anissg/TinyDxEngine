#pragma once
#include "EngineWindowsApp.h"

class Engine: public EngineWindowsApp
{

public:
    virtual bool Initialize(HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height);
    void Run();
    void UpdateInputs();
    virtual void Update(double elapsedTime);
    virtual void Render();
};

