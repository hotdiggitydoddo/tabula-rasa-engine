#pragma once

#include <vector>
#include <string>
#include <TabulaRasa/SpriteBatch.h>

#include "Actor.h"
#include "Player.h"

const int TILE_WIDTH = 64;

class Level
{
public:
    Level();
    Level(const std::string& mapPath);
    ~Level();
    void Init(TabulaRasa::InputManager* inputManager);
    void Update();
    void Draw(TabulaRasa::SpriteBatch& spriteBatch);

    glm::ivec2 GetUpperWorldBounds() { return _upperBounds; }

    Actor* GetBullet() { return _actors[0];}

private:
    std::vector<Actor*> _actors;
    std::vector<std::string> _map;
    int _numHumans;
    glm::ivec2 _playerSpawnPos;
    std::vector<glm::ivec2> _zombieSpawnPositions;
    TabulaRasa::SpriteBatch _spriteBatch;
    glm::ivec2 _upperBounds;
};