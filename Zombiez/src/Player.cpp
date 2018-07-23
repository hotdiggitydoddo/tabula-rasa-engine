#include <SDL_keycode.h>
#include "Player.h"


void Player::Update()
{
    HandleInput();
    Actor::Update();
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
}
Player::~Player()
{
    _inputManager = nullptr;
}
