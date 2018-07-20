#pragma once

#include <glm/glm.hpp>
#include <TabulaRasa/SpriteBatch.h>

class Bullet
{
public:
    Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifetime);

    // Returns whether lifetime is over
    bool Update();
    void Draw(TabulaRasa::SpriteBatch& spriteBatch);
private:
    glm::vec2 _position;
    glm::vec2 _direction;
    float _speed;
    int _lifetime;
};

