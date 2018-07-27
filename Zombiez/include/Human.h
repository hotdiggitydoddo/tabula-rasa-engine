#pragma once

#include <TabulaRasa/Vertex.h>
#include "Actor.h"

class Human : public Actor
{
public:
    Human(const glm::vec2& pos, const glm::vec2& dir = glm::vec2(1, 0), float speed = 4.0f)
        : Actor(pos, "textures/circle.png", 1.0f, TabulaRasa::Color {38, 184, 9, 255})

    {
        _direction = dir,
            _speed = speed;
    }

    void Update() override;
private:

};