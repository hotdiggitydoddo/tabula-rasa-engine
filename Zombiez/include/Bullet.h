#pragma once

#include <glm/glm.hpp>
#include <TabulaRasa/SpriteBatch.h>
#include "Actor.h"

class Bullet : public Actor
{
public:
    Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int maxLifetime);
    void Update() override;
    bool IsAlive() { return _lifetime > 0 ; }
    void Activate(const glm::vec2& pos, const glm::vec2 dir, float speed);
private:
    int _lifetime;
    int _maxLifetime;
};

