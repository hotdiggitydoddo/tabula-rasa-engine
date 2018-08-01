#include <SDL2/SDL_keycode.h>
#include <algorithm>
#include <iostream>
#include "Level.h"
#include "Player.h"


void Player::Update()
{
    Actor::Update();
    CollideWithLevel();
    _gun.Update();
}

void Player::HandleInput()
{
    _direction = glm::vec2(0);
    if (_inputManager->IsKeyPressed(SDLK_w))
        _direction.y = -1;
    else if (_inputManager->IsKeyPressed(SDLK_s))
        _direction.y = 1;
    if (_inputManager->IsKeyPressed(SDLK_a))
        _direction.x = -1;
    else if (_inputManager->IsKeyPressed(SDLK_d))
        _direction.x = 1;

    if (_inputManager->IsKeyPressed(SDLK_SPACE))
        _gun.Fire(_position, _direction);
}

Player::~Player()
{
    _inputManager = nullptr;
}

void Player::Init(Level* level)
{
    Actor::Init(level);
    _gun.Init(level);
}



