#pragma once

#include <glm/glm.hpp>
#include <TabulaRasa/SpriteBatch.h>
#include "Actor.h"

class Bullet : public Actor
{
public:
    Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifetime);
    void Update() override;
    bool IsAlive() { return _lifetime > 0 ;}
private:
    int _lifetime;
};

