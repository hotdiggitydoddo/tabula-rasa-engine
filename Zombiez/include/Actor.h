#pragma once

#include <glm/glm.hpp>

#include "Updatable.h"
#include <TabulaRasa/Drawable.h>

class Actor : public TabulaRasa::Drawable
{
public:
    Actor(glm::vec2 pos, const std::string& texturePath, float scale = 1, TabulaRasa::Color color = {255, 255, 255, 255});
    virtual void Update() = 0;
    virtual ~Actor() = default;


protected:
    glm::vec2 _direction;
    float _speed;
};
