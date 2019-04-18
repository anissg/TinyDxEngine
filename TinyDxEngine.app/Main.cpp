#include "Engine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	Engine engine;
	engine.Initialize(hInstance, L"TinyDXEngine", L"TDXEClass", 1280, 720);
    engine.Run();
}