#include "TinyDxEngine.h"
#include "RenderWindow.h"


bool RenderWindow::InitWindow(HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height)
{
	this->hInstance = hInstance;
	this->title = title;
	this->windowClass = windowClass;
	this->width = width;
	this->height = height;

	this->RegisterWindowClass();

	this->handle = CreateWindowW(
		this->windowClass.c_str(),
		this->title.c_str(),
		WS_OVERLAPPEDWINDOW,
		0, 
		0, 
		this->width, 
		this->height, 
		nullptr, 
		nullptr, 
		this->hInstance, 
		nullptr
	);

	if (!this->handle)
	{
		Logger::get().Log("CreateWindowsEX Failed", ERR);
		return false;
	}

	ShowWindow(this->handle, SW_SHOW);
	UpdateWindow(this->handle);

	return true;
}

bool RenderWindow::ProcessMessages()
{
	MSG msg;
	
	if (GetMessage(&msg, this->handle, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	if (msg.message == WM_NULL)
	{
		if (!IsWindow(this->handle))
		{
			//message processing destroy the window
			//we don't have to call DestroyWindow
			this->handle = nullptr;
			UnregisterClass(this->windowClass.c_str(), this->hInstance);
			return false;
		}
	}

	return true;
}

ATOM RenderWindow::RegisterWindowClass()
{
	WNDCLASSEXW wcex;
	
	wcex.cbSize = sizeof(WNDCLASSEX);
	
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = DefWindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = this->hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TINYDXENGINE));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = this->windowClass.c_str();
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	
	return RegisterClassExW(&wcex);
}

RenderWindow::~RenderWindow()
{
	if (this->handle != nullptr)
	{
		UnregisterClass(this->windowClass.c_str(), this->hInstance);
		DestroyWindow(this->handle);
	}
}
