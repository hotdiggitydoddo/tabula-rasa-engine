#include "Zombie.h"
#include "Human.h"
#include "MainGame.h"

#include <glm/gtx/rotate_vector.hpp>

void Zombie::Update()
{
    if (_closestTarget == nullptr)
    {
        if (_currentFrame >= _maxFramesToKeepDirection)
        {
            float rotation(MainGame::RandomEngine.getFloat(-40.0f, 40.0f));
            _direction = glm::rotate(_direction, 0.1f);
            _currentFrame = 0;
        }
        else
        {
            _currentFrame++;
        }
    }
    
    float smallestDist = 9999999.0f;
    _closestTarget = nullptr;

    for (auto& actor : *(_level->GetActors()))
    {
        if (actor == this)
            continue;

        if (dynamic_cast<Zombie*>(actor) == nullptr)
        {
            glm::vec2 distVec = (actor->GetPosition() + actor->GetOrigin()) - (_position + GetOrigin());
            float dist = glm::length(distVec);

            if (dist < smallestDist)
            {
                smallestDist = dist;
                _closestTarget = actor;
            }
        }

        if (CollideWithActor(actor))
        {
            if (auto* human = dynamic_cast<Human*>(actor))
            {
                actor = new Zombie(human->GetPosition(), actor->GetDirection(), actor->GetSpeed());
                actor->Init(_level);
            }
        }
    }

    if (_closestTarget != nullptr)
    {
        glm::vec2 direction = glm::normalize((_closestTarget->GetPosition() + _closestTarget->GetOrigin()) - (_position + GetOrigin()));
        _position += direction * _speed;
    }


    if (CollideWithLevel())
    {
        float rotation(MainGame::RandomEngine.getFloat(-40.0f, 40.0f));
        _direction = glm::rotate(_direction, 0.1f);
        _currentFrame = 0;
    }
}
