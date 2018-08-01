#pragma once

#include <string>
#include <TabulaRasa/Vertex.h>
#include <TabulaRasa/InputManager.h>
#include "Actor.h"
#include "Gun.h"
#include "Level.h"

class Player : public Actor
{
public:
    Player(const glm::vec2& pos, TabulaRasa::InputManager* inputManager)
        : Actor(pos, "textures/circle.png", 1.0f, TabulaRasa::Color {34, 36, 200, 255}),
          _inputManager(inputManager),
          _gun("Pistol", 30, 1, 10, 20, 0.0f, 20)
    {
        _speed = 6.0f * (1/_scale);
    }

    ~Player();
    void Init(Level* level) override;
    void Update() override;
    void HandleInput();
private:
    TabulaRasa::InputManager* _inputManager;
    Gun _gun;
};
