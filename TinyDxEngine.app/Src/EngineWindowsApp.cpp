#include "EngineWindowsApp.h"

EngineWindowsApp::EngineWindowsApp() : pitch(0), yaw(0)
{
    gamePad = std::make_unique<GamePad>();
    keyboard = std::make_unique<Keyboard>();
    mouse = std::make_unique<Mouse>();
}

bool EngineWindowsApp::ProcessMessages()
{
    return this->renderWindow.ProcessMessages();
}
