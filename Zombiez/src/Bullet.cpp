#include "Bullet.h"

#include <TabulaRasa/GLTexture.h>
#include <TabulaRasa/ResourceManager.h>

Bullet::Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifetime)
    : Actor(pos, "textures/circle.png", .25f, {0, 0, 0, 255}), _lifetime(lifetime)
{
    _speed = speed;
    _direction = dir;
}

void Bullet::Update()
{
  //  _scale -= .01f;
   Actor::Update();
    //_lifetime--;
}



