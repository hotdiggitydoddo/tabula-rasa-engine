#include "Human.h"

#include <glm/gtx/rotate_vector.hpp>
void Human::Update()
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

    Actor::Update();

    if (CollideWithLevel())
    {
        float rotation(MainGame::RandomEngine.getFloat(-40.0f, 40.0f));
        _direction = glm::rotate(_direction, 0.1f);
        _currentFrame = 0;
    }
}
