#pragma once
#include <wrl/client.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <WICTextureLoader.h>
#include <SpriteBatch.h>
#include <string>

using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;

class Sprite
{
    ID3D11ShaderResourceView* texture;
    XMVECTOR position;
    XMFLOAT2 origin;
    float rotation;
    float scale;
public:
    Sprite();
    Sprite(ID3D11ShaderResourceView* texture);
    ~Sprite();
    void SetTexture(ID3D11ShaderResourceView* texture);
    ID3D11ShaderResourceView* GetTexture();
    void SetPosition(XMVECTOR position);
    XMVECTOR GetPosition();
    void SetOrigin(XMFLOAT2 origin);
    XMFLOAT2 GetOrigin();
    void SetRotation(float angle);
    float GetRotation();
    void SetScale(float scale);
    float GetScale();
    void Render(shared_ptr<SpriteBatch> spriteBatch);
};

