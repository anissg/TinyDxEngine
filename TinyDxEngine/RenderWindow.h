#pragma once
#include "TinyDxEngine.h"
#include "Logger.h"

using namespace std;

class RenderWindow
{
public:
	bool InitWindow(HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height);
	bool ProcessMessages();
	~RenderWindow();
private:
	ATOM RegisterWindowClass();
	HWND handle = nullptr;
	HINSTANCE hInstance = nullptr;                                
	wstring title;      
	wstring windowClass;
	int width;
	int height;

};
