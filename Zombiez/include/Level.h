#pragma once

#include <vector>
#include <string>
#include <TabulaRasa/SpriteBatch.h>

#include "Actor.h"

const int TILE_WIDTH = 64;

class Level
{
public:
    Level();
    Level(const std::string& mapPath);
    ~Level();
    void Init();
    void Update();
    void Draw(TabulaRasa::SpriteBatch& spriteBatch);
private:
    std::vector<Actor*> _actors;
    std::vector<std::string> _map;
    int _numHumans;
    glm::ivec2 _playerSpawnPos;
    std::vector<glm::ivec2> _zombieSpawnPositions;
    TabulaRasa::SpriteBatch _spriteBatch;
};