#pragma once
#include <wrl/client.h>
#include <d3d11.h>


using namespace Microsoft::WRL;

class Graphics
{
public:
    bool Initialize(HWND hwnd, int width, int height);
private:
    bool InitializeDirectX(HWND hwnd, int width, int height);

    ComPtr<ID3D11Device> device;
    ComPtr<ID3D11DeviceContext> deviceContext;
    ComPtr<IDXGISwapChain> swapChain;
    ComPtr<ID3D11RenderTargetView> renderTargetView;
};

