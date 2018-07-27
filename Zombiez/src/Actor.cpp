#include "Actor.h"
#include "Level.h"
Actor::Actor(glm::vec2 pos, const std::string& texturePath, float scale, TabulaRasa::Color color)
    : Drawable(pos, texturePath, scale, color), _level(nullptr)
{

}



void Actor::Update()
{
    _position += _direction * _speed;
}

void Actor::Init(Level* level)
{
    _level = level;
}

void Actor::CollideWithLevel()
{
    std::vector<glm::ivec2> collidedTilePositions;
    glm::vec2 origin = GetOrigin();
    CheckTilePosition(collidedTilePositions, _position.x, _position.y);
    CheckTilePosition(collidedTilePositions, _position.x + (origin.x * 2), _position.y);
    CheckTilePosition(collidedTilePositions, _position.x + (origin.x * 2), _position.y + (origin.y * 2));
    CheckTilePosition(collidedTilePositions, _position.x, _position.y + (origin.y * 2));

    for (auto& pos : collidedTilePositions)
        CollideWithTile(pos);
}

void Actor::CheckTilePosition(std::vector<glm::ivec2>& collidedTilePositions, float x, float y)
{

    glm::vec2 posCheck(x, y);
    if (_level->GetTileAtWorldPosition(posCheck) != '.')
        collidedTilePositions.push_back(posCheck);
}

void Actor::CollideWithTile(const glm::vec2& tilePos)
{
    const float TILE_RADIUS = _level->TILE_WIDTH / 2.0f;
    const float MIN_DISTANCE = GetOrigin().x + TILE_RADIUS;

    glm::ivec2 tileGridPos = _level->WorldToTilePos(tilePos);
    glm::vec2 tileCenterPos = _level->TileCenterPosFromGridPos(tileGridPos.x, tileGridPos.y);

    glm::vec2 distVect = (_position + GetOrigin()) - tileCenterPos;

    float xDepth = MIN_DISTANCE - abs(distVect.x);
    float yDepth = MIN_DISTANCE - abs(distVect.y);

    // if this is true, we are colliding
    if (xDepth > 0 || yDepth > 0)
    {
        if (std::max(xDepth, 0.0f) < std::max(yDepth, 0.0f))
        {
            if (distVect.x < 0)
            {
                _position.x -= xDepth;
            }
            else
            {
                _position.x += xDepth;
            }
        }
        else
        {
            if (distVect.y < 0)
            {
                _position.y -= yDepth;
            }
            else
            {
                _position.y += yDepth;
            }
        }
    }
}