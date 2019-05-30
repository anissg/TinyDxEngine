#include "stdafx.h"
#include "TestApp.h"

using namespace std;

bool TestApp::Initialize(HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height)
{
    Engine::Initialize(hInstance, title, windowClass, width, height);
    gfx.InitializeSpriteBatch();

    ComPtr<ID3D11Resource> resource;
    HRESULT hr;
    hr = CreateWICTextureFromFile(gfx.GetDevice(), L"cat.png", resource.GetAddressOf(), texture.ReleaseAndGetAddressOf());
    if (FAILED(hr))
    {
        Logger::get().Log("Failed to create texture.", ERR);
        return false;
    }

    spriteBatch = gfx.GetSpriteBatch();

    ComPtr<ID3D11Texture2D> cat;
    resource.As(&cat);
    sprite.SetTexture(texture.Get(), cat.Get());
   
    sprite.SetScale(1);
    sprite.SetRotation(0);
    sprite.SetPosition(XMVectorSet(100, 100, 0, 0));

    return true;
}

void TestApp::Update(double elapsedTime)
{
    Engine::Update(elapsedTime);
}

void TestApp::Render()
{
    gfx.Clear(Colors::BlueViolet);

    spriteBatch->Begin(SpriteSortMode_Deferred, gfx.GetStates()->NonPremultiplied());
    
    sprite.Render(spriteBatch);

    spriteBatch->End();

    gfx.Present();
}
