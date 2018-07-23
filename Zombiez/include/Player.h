#pragma once

#include <string>
#include <TabulaRasa/Vertex.h>
#include <TabulaRasa/InputManager.h>
#include "Actor.h"

class Player : public Actor
{
public:
    Player(const glm::vec2& pos, TabulaRasa::InputManager* inputManager)
        : Actor(pos, "textures/circle.png", 1.0f, TabulaRasa::Color {34, 36, 200, 255}), _inputManager(inputManager)
    {
        _speed = 6.0f * (1/_scale);
    }

    ~Player();
    void Update() override;

private:
    void HandleInput();

    TabulaRasa::InputManager* _inputManager;
};
