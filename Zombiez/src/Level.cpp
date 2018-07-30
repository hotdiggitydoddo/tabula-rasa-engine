#include <fstream>
#include <TabulaRasa/Errors.h>
#include <iostream>
#include <TabulaRasa/ResourceManager.h>
#include <MainGame.h>
#include "Human.h"
#include "Zombie.h"
#include "Level.h"





void Level::Init(TabulaRasa::InputManager* inputManager, TabulaRasa::Camera2D* camera)
{
    _camera = camera;
    _player = new Player(glm::vec2(256, 256), inputManager);
    _player->Init(this);
    _camera->SetTarget(_player);
    _camera->SetBounds(_upperBounds);

    _actors.push_back(_player);

    for (int i = 0; i < _numHumans; i++)
    {
//        glm::ivec2 pos(
//            MainGame::RandomEngine.getRandomInt(2, GetWidth() - 2),
//            MainGame::RandomEngine.getRandomInt(2, GetHeight() - 2)
//        );

        Human* h = new Human(
            GetRandomFloorPosition() * TILE_WIDTH,
            glm::vec2(MainGame::RandomEngine.getRandomDouble(-1, 1),
                      MainGame::RandomEngine.getRandomDouble(-1, 1)),
            MainGame::RandomEngine.getRandomDouble(0.20f, 4.0f));

        h->Init(this);

        _actors.push_back(h);
    }

    for (auto& pos : _zombieSpawnPositions)
    {
        Zombie* z = new Zombie(
            pos,
            glm::vec2(MainGame::RandomEngine.getRandomDouble(-1, 1),
                      MainGame::RandomEngine.getRandomDouble(-1, 1)),
            MainGame::RandomEngine.getRandomDouble(1.0f, 4.0f));

        z->Init(this);

        _actors.push_back(z);
    }
}

void Level::Update()
{
    _player->HandleInput();

    for (auto* actor : _actors)
    {
        actor->Update();
    }

//    for (int i = 0; i < _actors.size(); i++)
//    {
//        for (int j = 0; j < _actors.size(); j++)
//        {
//            if (i == j)
//                continue;
//            if (_actors[i]->CollideWithActor(_actors[j]))
//            {
//                if (auto* zombie = dynamic_cast<Zombie*>(_actors[j]))
//                {
//                    if (dynamic_cast<Human*>(_actors[i]) == nullptr)
//                        continue;
//
//                    _actors[i] = (new Zombie(_actors[i]->GetPosition(), {1, 1}));
//                    _actors[i]->Init(this);
//                    //delete _actors[i];
//                    //_actors[i] = _actors.back();
//                }
//            }
//        }
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
                    tile = '.';
                    break;

                case 'Z':
                    _zombieSpawnPositions.emplace_back(x * TILE_WIDTH, y * TILE_WIDTH);
                    tile = '.';
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
    //std::cout << "position: " << worldPos.x << "," << worldPos.y << std::endl;
    //std::cout << "tile " << "(" << std::to_string(x) << ", " << std::to_string(y) << ")" << " is " << _map[y][x] << std::endl;
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

glm::ivec2 Level::GetRandomFloorPosition()
{
    while (true)
    {
        glm::ivec2 pos(
            MainGame::RandomEngine.getRandomInt(3, GetWidth() - 3),
            MainGame::RandomEngine.getRandomInt(3, GetHeight() - 3)
        );

        if (_map[pos.y][pos.x] != '.')
            continue;
        return pos;
    }
}



