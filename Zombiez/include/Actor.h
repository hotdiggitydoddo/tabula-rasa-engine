#pragma once

#include <glm/glm.hpp>
#include "Updatable.h"
#include "Level.h"
#include <TabulaRasa/Drawable.h>



class Actor : public TabulaRasa::Drawable
{
public:
    Actor(glm::vec2 pos, const std::string& texturePath, float scale = 1, TabulaRasa::Color color = {255, 255, 255, 255});
    virtual void Init(Level* level);
    virtual void Update() = 0;
    virtual ~Actor() { _level = nullptr; }
    bool CollideWithActor(Actor* other);
    glm::vec2 GetDirection() { return _direction; }
    float GetSpeed() { return _speed; }
    void Activate() { _isActive = true; }
    void Deactivate() { _isActive = false; }
    bool IsActive() { return _isActive; }
protected:
    bool CollideWithLevel();
    void CheckTilePosition(std::vector<glm::ivec2>& collidedTilePositions, float x, float y);
    void CollideWithTile(const glm::vec2& tilePos);

    glm::vec2 _direction;
    float _speed;
    Level* _level;
    bool _isActive;
};
