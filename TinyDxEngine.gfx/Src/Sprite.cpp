#include "Sprite.h"

Sprite::Sprite() : position(0, 0), origin(0, 0), rotation(0), scale(1)
{
}

Sprite::Sprite(ID3D11ShaderResourceView* texture) : Sprite()
{
    this->texture = texture;
}

Sprite::~Sprite()
{
}

void Sprite::SetTexture(ID3D11ShaderResourceView* texture)
{
    this->texture = texture;
}

ID3D11ShaderResourceView* Sprite::GetTexture()
{
    return this->texture;
}

void Sprite::SetPosition(XMFLOAT2 position)
{
    this->position = position;
}

XMFLOAT2 Sprite::GetPosition()
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

void Sprite::Render(shared_ptr<SpriteBatch> spriteBatch)
{
    spriteBatch->Draw(texture, position, nullptr, Colors::White, rotation, origin, scale);
}


