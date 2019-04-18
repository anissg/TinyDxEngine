#pragma once
#include "EngineWindowsApp.h"


class Engine: public EngineWindowsApp
{

public:
    bool Initialize(HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height);
    void Run();
    void Update();
};

