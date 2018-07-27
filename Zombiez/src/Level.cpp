#include <fstream>
#include <TabulaRasa/Errors.h>
#include <iostream>
#include <TabulaRasa/ResourceManager.h>
#include "Level.h"

void Level::Init(TabulaRasa::InputManager* inputManager, TabulaRasa::Camera2D* camera)
{
    _camera = camera;
    _player = new Player(glm::vec2(256, 256), inputManager);
    _player->Init(this);
    _camera->SetTarget(_player);
    _camera->SetBounds(_upperBounds);

    _actors.push_back(_player);
//    for (int i = 0; i < 1; i++)
//    {
//        Bullet* b = new Bullet(glm::vec2(0.0, 0.0f), glm::vec2(3.0f, 3.0f), 1.0f, 10000);
//        _actors.push_back(b);
//    }
    std::cout << GetTileAtWorldPosition({0,0})  << " " << WorldToTilePos({0, 0}).x << "," << WorldToTilePos({0, 0}).y << std::endl;
    std::cout << GetTileAtWorldPosition({63,0})  << " " << WorldToTilePos({63, 0}).x << "," << WorldToTilePos({63, 0}).y << std::endl;
    std::cout << GetTileAtWorldPosition({72,12})  << " " << WorldToTilePos({72, 12}).x << "," << WorldToTilePos({72, 12}).y << std::endl;

}
void Level::Update()
{
    _player->HandleInput();

    for (auto* actor : _actors)
    {
        actor->Update();
    }
}
void Level::Draw(TabulaRasa::SpriteBatch& spriteBatch)
{
    _spriteBatch.Render();

    for (auto* actor : _actors)
    {
        actor->Draw(spriteBatch);
    }
}

Level::Level(const std::string& mapPath)
{
    std::ifstream file;
    file.open(mapPath);

    if (!file.is_open())
        TabulaRasa::FatalError("Unable to open level data: " + mapPath);

    std::string tmp = "";
    file >> tmp >> _numHumans;

    // throw away the rest of the first line
    std::getline(file, tmp);

    // read level data
    while (std::getline(file, tmp))
    {
        _map.push_back(tmp);
    }

    file.close();
    _spriteBatch.Init();
    _spriteBatch.Begin();

    glm::vec4 uvRect(0, 0, 1.0f, 1.0f);
    TabulaRasa::Color whiteColor = {255, 255, 255, 255};

    //Render all the tiles
        int x = 0;
        int y = 0;
    for (y = 0; y < _map.size(); y++)
    {
        for (x = 0; x < _map[y].size(); x++)
        {
            char tile = _map[y][x];
            glm::vec4 destRect(x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH);
            switch (tile)
            {
                case 'R':
                case 'B':
                    _spriteBatch.Draw(destRect,
                                      uvRect,
                                      TabulaRasa::ResourceManager::GetTexture("textures/red_bricks.png").id,
                                      0.0f,
                                      whiteColor);
                    break;
                case 'G':
                    _spriteBatch.Draw(destRect,
                                      uvRect,
                                      TabulaRasa::ResourceManager::GetTexture("textures/glass.png").id,
                                      0.0f,
                                      whiteColor);
                    break;
                case 'L':
                    _spriteBatch.Draw(destRect,
                                      uvRect,
                                      TabulaRasa::ResourceManager::GetTexture("textures/light_bricks.png").id,
                                      0.0f,
                                      whiteColor);
                    break;

                case '@':
                    _playerSpawnPos.x = x * TILE_WIDTH;
                    _playerSpawnPos.y = y * TILE_WIDTH;
                    break;

                case 'Z':
                    _zombieSpawnPositions.emplace_back(x * TILE_WIDTH, y * TILE_WIDTH);
                    break;

                case '.':
                case '\r':
                case '\n':
                    break;

                default:
                    std::printf("Unexpected symbol %c at (%d,%d)", tile, x, y);
                    break;
            }
        }
    }
    _spriteBatch.End();
    _upperBounds = glm::ivec4(0.0f, 0.0f, x * TILE_WIDTH, y * TILE_WIDTH);
    _camera = nullptr;

}

Level::~Level()
{
    _camera = nullptr;
    for (auto& actor : _actors)
    {
        delete actor;
    }
}

char Level::GetTileAtWorldPosition(const glm::vec2& worldPos)
{
    int y = static_cast<int>(floor(worldPos.y / (TILE_WIDTH * _camera->GetScale())));
    int x = static_cast<int>(floor(worldPos.x / (TILE_WIDTH * _camera->GetScale())));
    std::cout << "position: " << worldPos.x << "," << worldPos.y << std::endl;
    std::cout << "tile " << "(" << std::to_string(x) << ", " << std::to_string(y) << ")" << " is " << _map[y][x] << std::endl;
    return _map[y][x];
}

glm::ivec2 Level::WorldToTilePos(const glm::vec2& worldPos)
{
    return glm::ivec2(worldPos.x / (TILE_WIDTH * _camera->GetScale()), worldPos.y / (TILE_WIDTH * _camera->GetScale()));
}

glm::vec2 Level::TileCenterPosFromGridPos(int x, int y)
{
    return glm::vec2(x * TILE_WIDTH + (TILE_WIDTH / 2), y * TILE_WIDTH + (TILE_WIDTH / 2));
}



