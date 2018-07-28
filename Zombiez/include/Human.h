#pragma once

#include <TabulaRasa/Vertex.h>
#include "Actor.h"
#include "MainGame.h"

class Human: public Actor
{
public:
    Human(const glm::vec2& pos, const glm::vec2& dir = glm::vec2(1, 0), float speed = 4.0f)
        : Actor(pos, "textures/circle.png", 1.0f, TabulaRasa::Color{250, 80, 222, 255})
    {
        _direction = dir,
        _speed = speed;
        _maxFramesToKeepDirection = 20;
        _currentFrame = 0;

    }

    void Update() override;

private:
    int _maxFramesToKeepDirection;
    int _currentFrame;
};