#include "Actor.h"

Actor::Actor(glm::vec2 pos, const std::string& texturePath, float scale, TabulaRasa::Color color)
    : Drawable(pos, texturePath, scale, color)
{

}

void Actor::Update()
{
    _position += _direction * _speed;
}

