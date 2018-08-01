#pragma once

#include <vector>
#include <string>
#include <TabulaRasa/SpriteBatch.h>
#include <TabulaRasa/Camera2D.h>
#include <TabulaRasa/InputManager.h>

class Actor;
class Player;

class Level
{
public:
    Level();
    Level(const std::string& mapPath);
    ~Level();
    void Init(TabulaRasa::InputManager* inputManager, TabulaRasa::Camera2D* camera);
    void Update();
    void Draw(TabulaRasa::SpriteBatch& spriteBatch);

    int GetWidth() { return _map[0].size(); }
    int GetHeight() { return _map.size(); }

    char GetTileAtWorldPosition(const glm::vec2& worldPos);
    glm::ivec2 GetRandomFloorPosition();
    glm::ivec2 WorldToTilePos(const glm::vec2& worldPos);
    glm::vec2 TileCenterPosFromGridPos(int x, int y);
    std::vector<Actor*>* GetActors() { return &_actors; }
    const int TILE_WIDTH = 64;
private:
    TabulaRasa::SpriteBatch _spriteBatch;
    TabulaRasa::Camera2D* _camera;
    std::vector<Actor*> _actors;
    std::vector<std::string> _map;
    int _numHumans;
    glm::ivec2 _playerSpawnPos;
    std::vector<glm::ivec2> _zombieSpawnPositions;
    glm::ivec4 _upperBounds;

    Player* _player;
};