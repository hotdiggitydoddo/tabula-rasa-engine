#pragma once

#include <glm/glm.hpp>

class GameObject
{
public:
    glm::vec2 GetPosition() { return _position; }

    void SetPosition(float x, float y);
    void SetPosition(glm::vec2 newPos);
protected:
    glm::vec2 _position;
};
