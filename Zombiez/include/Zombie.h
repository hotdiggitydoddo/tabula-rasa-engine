#pragma once

#include "Actor.h"
#include "TabulaRasa/Vertex.h"

class Zombie : public Actor
{
public:
    Zombie(const glm::vec2& pos, const glm::vec2& dir = glm::vec2(1, 0), float speed = 4.0f)
        : Actor(pos, "textures/circle.png", 1.0f, TabulaRasa::Color{0, 160, 0, 255})
    {
        _direction = dir,
            _speed = speed;
        _maxFramesToKeepDirection = 20;
        _currentFrame = 0;
        _closestTarget = nullptr;
    }

    void Update() override;

private:
    int _maxFramesToKeepDirection;
    int _currentFrame;
    Actor* _closestTarget;
};
