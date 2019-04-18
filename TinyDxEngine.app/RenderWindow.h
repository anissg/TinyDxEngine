#pragma once
#include "pch.h"
#include "Logger.h"

using namespace std;

class EngineWindowsApp;

enum Hotkeys
{
    UNUSED = 0,
    PRINTSCREEN = 1,
};

class RenderWindow
{
public:
	bool InitWindow(EngineWindowsApp* enginApp, HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height);
	bool ProcessMessages();
    HWND GetWindow();
    void Quit();
	~RenderWindow();
private:
	ATOM RegisterWindowClass();

	HWND handle = nullptr;
	HINSTANCE hInstance = nullptr;                                
	wstring title;      
	wstring windowClass;
	int width = 800;
	int height = 600;
    EngineWindowsApp* engineApp = nullptr;
};

