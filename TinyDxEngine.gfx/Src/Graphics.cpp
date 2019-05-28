#include "Graphics.h"
#include "Adapters.h"

bool Graphics::Initialize(HWND hwnd, int width, int height)
{
    if (!InitializeDirectX(hwnd, width, height))
        return false;
    return true;
}

void Graphics::RenderFrame()
{
    FLOAT clear_color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };/*clearColor*/
    this->deviceContext->ClearRenderTargetView(this->renderTargetView.Get(), clear_color);
    this->Present();
}

shared_ptr<SpriteBatch> Graphics::GetSpriteBatch()
{
    return spriteBatch;
}

ID3D11Device* Graphics::GetDevice()
{
    return this->device.Get();
}

shared_ptr<CommonStates> Graphics::GetStates()
{
    return this->states;
}

bool Graphics::InitializeDirectX(HWND hwnd, int width, int height)
{
    vector<AdapterData> adapters = Adapters::get().GetAdapters();

    if (adapters.size() < 1)
    {
        Logger::get().Log("No DXGI adapters found.", ERR);
        return false;
    }

    static const D3D_FEATURE_LEVEL s_featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
        D3D_FEATURE_LEVEL_9_3,
        D3D_FEATURE_LEVEL_9_2,
        D3D_FEATURE_LEVEL_9_1,
    };

    DXGI_SWAP_CHAIN_DESC scd;
    ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));
    
    scd.BufferDesc.Width = width;
    scd.BufferDesc.Height = height;
    scd.BufferDesc.RefreshRate.Numerator = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

    scd.SampleDesc.Count = 1;
    scd.SampleDesc.Quality = 0;

    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.BufferCount = 1;
    scd.OutputWindow = hwnd;
    scd.Windowed = TRUE;
    scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    D3D_FEATURE_LEVEL m_d3dFeatureLevel;

    HRESULT hr;
    hr = D3D11CreateDeviceAndSwapChain(
        adapters[0].pAdapter,
        D3D_DRIVER_TYPE_UNKNOWN,    //unspecified
        0,                       //for soft driver type
        D3D11_CREATE_DEVICE_BGRA_SUPPORT,
        s_featureLevels,
        6,
        D3D11_SDK_VERSION,
        &scd,                       //swapchain desc
        this->swapChain.ReleaseAndGetAddressOf(),
        this->device.ReleaseAndGetAddressOf(),
        &m_d3dFeatureLevel,
        this->deviceContext.ReleaseAndGetAddressOf()
    );

    if (FAILED(hr))
    {
        Logger::get().Log("Failed to create device and swapchain.", ERR);
        return false;
    }

    ComPtr<ID3D11Texture2D> backBuffer;
    hr = this->swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(backBuffer.GetAddressOf()));
    if (FAILED(hr))
    {
        Logger::get().Log("GetBuffer Failed.", ERR);
        return false;
    }
    
    hr = this->device->CreateRenderTargetView(backBuffer.Get(), NULL, this->renderTargetView.GetAddressOf());
    if (FAILED(hr))
    {
        Logger::get().Log("Failed to create render target view.", ERR);
        return false;
    }

    this->deviceContext->OMSetRenderTargets(1, this->renderTargetView.GetAddressOf(), NULL);

    CD3D11_VIEWPORT screenViewport(
        0.0f,
        0.0f,
        static_cast<float>(width),
        static_cast<float>(height)
    );

    this->deviceContext->RSSetViewports(1, &screenViewport);

    return true;
}

bool Graphics::InitializeSpriteBatch()
{
    spriteBatch = make_shared<SpriteBatch>(deviceContext.Get());
    states = make_shared<CommonStates>(device.Get());
    return true;
}

void Graphics::Present()
{
    this->swapChain->Present(1, 0);
}

bool Graphics::InitializeShaders()
{
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        {"POSITION", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  },
    };

    UINT numElements = ARRAYSIZE(layout);

    HRESULT hr = this->device->CreateInputLayout(
        layout, 
        numElements, 
        this->vertex_shader_buffer->GetBufferPointer(), 
        this->vertex_shader_buffer->GetBufferSize(), 
        this->inputLayout.GetAddressOf()
    );
    if (FAILED(hr))
    {
        Logger::get().Log("Failed to create input layout.", ERR);
        return false;
    }

    return true;
}
