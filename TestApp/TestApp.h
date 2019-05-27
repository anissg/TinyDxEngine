#pragma once
#include "stdafx.h"

using namespace DirectX;

class TestApp : public Engine
{
    ComPtr<ID3D11ShaderResourceView> texture;
    shared_ptr<SpriteBatch> spriteBatch;
    Sprite sprite;
    
public:
    bool Initialize(HINSTANCE hInstance, wstring title, wstring windowClass, int width, int height) override;
    void Update(double elapsedTime) override;
    void Render() override;
};

