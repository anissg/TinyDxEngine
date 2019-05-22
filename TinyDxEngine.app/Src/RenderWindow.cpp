#include "EngineWindowsApp.h"


bool RenderWindow::InitWindow(EngineWindowsApp* engineApp, HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height)
{
	this->hInstance = hInstance;
	this->title = title;
	this->windowClass = windowClass;
	this->width = width;
	this->height = height;
    this->engineApp = engineApp;
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

HWND RenderWindow::GetWindow()
{
    return this->handle;
}

void RenderWindow::Quit()
{
    DestroyWindow(handle);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_ACTIVATEAPP:
    {
        Keyboard::ProcessMessage(message, wParam, lParam);
        Mouse::ProcessMessage(message, wParam, lParam);
    }
    break;

    case WM_SIZE:
    {
        // resize
    }
    break;

    case WM_INPUT:
    case WM_MOUSEMOVE:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_RBUTTONDOWN:
    case WM_RBUTTONUP:
    case WM_MBUTTONDOWN:
    case WM_MBUTTONUP:
    case WM_MOUSEWHEEL:
    case WM_XBUTTONDOWN:
    case WM_XBUTTONUP:
    case WM_MOUSEHOVER:
        Mouse::ProcessMessage(message, wParam, lParam);
        break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYUP:
        Keyboard::ProcessMessage(message, wParam, lParam);
        break;

    case WM_HOTKEY:
    {
        switch (wParam)
        {
        case PRINTSCREEN:
        {
            // take a screenshot
        }
        break;
        default:
            break;
        }
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

ATOM RenderWindow::RegisterWindowClass()
{
	WNDCLASSEXW wcex;
	
	wcex.cbSize = sizeof(WNDCLASSEX);
	
	wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = this->hInstance;
	wcex.hIcon = nullptr;
	wcex.hIconSm = nullptr;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = this->windowClass.c_str();
	
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
