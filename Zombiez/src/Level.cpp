#include <Bullet.h>
#include <fstream>
#include <TabulaRasa/Errors.h>
#include <iostream>
#include <TabulaRasa/ResourceManager.h>
#include "Level.h"


void Level::Init()
{
    for (int i = 0; i < 1; i++)
    {
        Bullet* b = new Bullet(glm::vec2(0.0, 0.0f), glm::vec2(1.0f, 0.0f), 1.0f, 10000);
        _actors.push_back(b);
    }
}
void Level::Update()
{
//    for (auto* actor : _actors)
//    {
//        actor->Update();
//    }
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
   // file >> tmp >> _numHumans;

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
    for (int y = 0; y < _map.size(); y++)
    {
        for (int x = 0; x < _map[y].size(); x++)
        {
            char tile = _map[y][x];
            glm::vec4 destRect(x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH);
            switch (tile)
            {
                case 'R':
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
                    break;

                default:
                    std::printf("Unexpected symbol %c at (&d,%d)", tile, x, y);
                    break;
            }
        }
    }
    _spriteBatch.End();
}

Level::~Level()
{
    for (auto& actor : _actors)
    {
        delete actor;
    }
}

