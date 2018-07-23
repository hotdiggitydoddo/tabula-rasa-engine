#include "GameObject.h"

void GameObject::SetPosition(glm::vec2 newPos)
{
    _position = newPos;
}

void GameObject::SetPosition(float x, float y)
{
    _position = glm::vec2(x, y);
}