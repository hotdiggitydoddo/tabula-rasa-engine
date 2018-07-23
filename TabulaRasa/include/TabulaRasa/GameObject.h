#pragma once

#include <glm/glm.hpp>

namespace TabulaRasa
{
class GameObject
{
public:
    glm::vec2 GetPosition() const { return _position; }

    void SetPosition(float x, float y);
    void SetPosition(glm::vec2 newPos);
protected:
    glm::vec2 _position;
};
}

