#pragma once

#include <glm/glm.hpp>
#include "Updatable.h"
#include <TabulaRasa/Drawable.h>

class Level;

class Actor : public TabulaRasa::Drawable
{
public:
    Actor(glm::vec2 pos, const std::string& texturePath, float scale = 1, TabulaRasa::Color color = {255, 255, 255, 255});
    void Init(Level* level);
    virtual void Update() = 0;
    virtual ~Actor() { _level = nullptr; }


protected:
    void CollideWithLevel();
    void CheckTilePosition(std::vector<glm::ivec2>& collidedTilePositions, float x, float y);
    void CollideWithTile(const glm::vec2& tilePos);

    glm::vec2 _direction;
    float _speed;
    Level* _level;
};
