#include "Bullet.h"

#include <TabulaRasa/GLTexture.h>
#include <TabulaRasa/ResourceManager.h>

Bullet::Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int maxLifetime)
        : Actor(pos, "textures/circle.png", .5f, {75, 75, 75, 255}),
          _maxLifetime(maxLifetime),
          _lifetime(0)
{
    _speed = 0.0f;
    _direction = dir;
    _isActive = false;
}

void Bullet::Update()
{
    Actor::Update();
    _lifetime--;
    if (_lifetime <= 0)
        _isActive = false;
}

void Bullet::Activate(const glm::vec2& pos, const glm::vec2 dir, float speed)
{
    _position = pos;
    _direction = dir;
    _speed = speed * (1 / _scale);
    _lifetime = _maxLifetime;
    _isActive = true;
}





