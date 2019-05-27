#pragma once
#include <wrl/client.h>
#include <d3d11.h>
#include <SpriteBatch.h>

using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;

class Graphics
{
public:
    bool Initialize(HWND hwnd, int width, int height);
    bool InitializeSpriteBatch();
    void RenderFrame();
    shared_ptr<SpriteBatch> GetSpriteBatch();
    ID3D11Device* GetDevice();
protected:
    bool InitializeDirectX(HWND hwnd, int width, int height);
    bool InitializeShaders();

    ComPtr<ID3D11Device> device;
    ComPtr<ID3D11DeviceContext> deviceContext;
    ComPtr<IDXGISwapChain> swapChain;
    ComPtr<ID3D11RenderTargetView> renderTargetView;
    ComPtr<ID3D11InputLayout> inputLayout;
    ComPtr<ID3D10Blob> vertex_shader_buffer;

    shared_ptr<SpriteBatch> spriteBatch;
};