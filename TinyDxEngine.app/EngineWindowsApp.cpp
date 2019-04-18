#include "pch.h"
#include "EngineWindowsApp.h"

EngineWindowsApp::EngineWindowsApp()
{
    keyboard = std::make_unique<Keyboard>();
    mouse = std::make_unique<Mouse>();
    mouse->SetWindow(renderWindow.GetWindow());
}

bool EngineWindowsApp::ProcessMessages()
{
    return this->renderWindow.ProcessMessages();
}
