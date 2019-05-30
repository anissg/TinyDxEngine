#include "Sprite.h"

Sprite::Sprite() : origin(0, 0), rotation(0), scale(1)
{
    position = XMVectorSet(0, 0, 0, 0);
}

Sprite::Sprite(ID3D11ShaderResourceView* texture) : Sprite()
{
    this->texture = texture;
}

Sprite::~Sprite()
{
}

void Sprite::SetTexture(ID3D11ShaderResourceView* texture, ID3D11Texture2D* resource)
{
    this->texture = texture;
    CD3D11_TEXTURE2D_DESC catDesc;
    resource->GetDesc(&catDesc);
    this->SetOrigin(XMFLOAT2(catDesc.Width / 2, catDesc.Height / 2));
    this->size = XMFLOAT2(catDesc.Width, catDesc.Height);
}

ID3D11ShaderResourceView* Sprite::GetTexture()
{
    return this->texture;
}

void Sprite::SetPosition(XMVECTOR position)
{
    this->position = position;
}

XMVECTOR Sprite::GetPosition()
{
    return position;
}

void Sprite::SetOrigin(XMFLOAT2 origin)
{
    this->origin = origin;
}

XMFLOAT2 Sprite::GetOrigin()
{
    return origin;
}

void Sprite::SetRotation(float angle)
{
    rotation = angle;
}

float Sprite::GetRotation()
{
    return rotation;
}

void Sprite::SetScale(float scale)
{
    this->scale = scale;
}

float Sprite::GetScale()
{
    return scale;
}

XMFLOAT2 Sprite::GetSize()
{
    return this->size;
}

void Sprite::Render(shared_ptr<SpriteBatch> spriteBatch)
{
    XMFLOAT2 position(XMVectorGetX(position), XMVectorGetY(position));
    spriteBatch->Draw(texture, position, nullptr, Colors::White, rotation, origin, scale);
}


