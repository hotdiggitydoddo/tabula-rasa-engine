#include "Bullet.h"

#include <TabulaRasa/GLTexture.h>
#include <TabulaRasa/ResourceManager.h>

Bullet::Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifetime)
    : _position(pos),
      _direction(dir),
      _speed(speed),
      _lifetime(lifetime)
{

}

bool Bullet::Update()
{
    _position += _direction * _speed;
    _lifetime--;

    return _lifetime <= 0;
}

void Bullet::Draw(TabulaRasa::SpriteBatch& spriteBatch)
{
    static TabulaRasa::GLTexture texture = TabulaRasa::ResourceManager::GetTexture("textures/ball.png");
    glm::vec4 pos(_position.x, _position.y, texture.width * .35f, texture.height * .35f);
    glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
    TabulaRasa::Color color = {255, 255, 255, 255};

    spriteBatch.Draw(pos, uv, texture.id, 0.0f, color);
}

