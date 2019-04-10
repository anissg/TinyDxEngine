#include "TinyDxEngine.h"
#include "RenderWindow.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	RenderWindow window;
	window.InitWindow(hInstance, L"TinyDxEngine", L"TDEClass", 1280, 720);
	while (window.ProcessMessages())
	{

	}
}