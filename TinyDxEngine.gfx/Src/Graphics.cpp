#include "Graphics.h"

bool Graphics::Initialize(HWND hwnd, int width, int height)
{
    if (!Initialize(hwnd, width, height))
        return false;
    return true;
}

bool Graphics::InitializeDirectX(HWND hwnd, int width, int height)
{


    return false;
}