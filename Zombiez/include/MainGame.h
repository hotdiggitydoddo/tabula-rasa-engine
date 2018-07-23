#pragma once

#include <SDL.h>
#include <OpenGL/OpenGL.h>
#include <vector>
#include <TabulaRasa/Sprite.h>
#include <TabulaRasa/GLSLProgram.h>
#include <TabulaRasa/GLTexture.h>
#include <TabulaRasa/Window.h>
#include <TabulaRasa/Camera2D.h>
#include <TabulaRasa/SpriteBatch.h>
#include <TabulaRasa/InputManager.h>
#include <TabulaRasa/Timing.h>
#include <TabulaRasa/Drawable.h>
#include "Bullet.h"
#include "Level.h"

enum class GameState
{
    PLAY, EXIT
};

class MainGame
{
public:
    MainGame(int width = 1024, int height = 768);
    ~MainGame();

    void Run();

private:
    void InitSystems();
    void InitShaders();
    void InitLevels();
    void ProcessInput();
    void Update();
    void Draw();

    GameState _gameState;

    TabulaRasa::Window _window;
    TabulaRasa::GLSLProgram _textureProgram;
    TabulaRasa::InputManager _inputManager;
    TabulaRasa::SpriteBatch _spriteBatch;
    TabulaRasa::FPSLimiter _fpsLimiter;
    TabulaRasa::Camera2D _camera;

    std::vector<Level*> _levels;
    Level* _currentLevel;

    int _screenWidth;
    int _screenHeight;

    float _fps;
    float _maxFps;
    float _time;

    std::vector<Bullet> _bullets;

    TabulaRasa::Drawable _circle;
    TabulaRasa::Drawable _circle2;
};
