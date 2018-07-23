#include "MainGame.h"

#include <iostream>
#include <TabulaRasa/TabulaRasa.h>
#include <TabulaRasa/Errors.h>

MainGame::MainGame(int width, int height)
    :
    _screenWidth(width),
    _screenHeight(height),
    _time(0.0f),
    _maxFps(60.0f),
    _currentLevel(nullptr)
{
}

MainGame::~MainGame()
{
    _currentLevel = nullptr;
    for (auto& level : _levels)
        delete level;
}

void MainGame::InitSystems()
{
    TabulaRasa::Init();

    _window.Create("Zombiez!", _screenWidth, _screenHeight, 0);
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    InitShaders();
    _spriteBatch.Init();
    _fpsLimiter.Init(_maxFps);
    _camera.Init(_screenWidth, _screenHeight);

    InitLevels();

    _gameState = GameState::PLAY;
}

void MainGame::InitShaders()
{
    _textureProgram.CompileShaders("shaders/textureShading.vert", "shaders/textureShading.frag");
    _textureProgram.AddAttribute("vertexPosition");
    _textureProgram.AddAttribute("vertexColor");
    _textureProgram.AddAttribute("vertexUV");
    _textureProgram.LinkShaders();
}

void MainGame::Run()
{
    InitSystems();
    Update();
}

void MainGame::ProcessInput()
{
    SDL_Event event;

    const float CAMERA_SPEED = 2.0f;
    const float SCALE_SPEED = 0.1f;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            case SDL_KEYDOWN:
                _inputManager.PressKey(static_cast<unsigned int>(event.key.keysym.sym));
                break;
            case SDL_KEYUP:
                _inputManager.ReleaseKey(static_cast<unsigned int>(event.key.keysym.sym));
                break;
            case SDL_MOUSEBUTTONDOWN:
                _inputManager.PressKey(event.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                _inputManager.ReleaseKey(event.button.button);
                break;
            case SDL_MOUSEMOTION:
                _inputManager.SetMouseCoords(event.motion.x, event.motion.y);
                break;
        }
    }

  /*  if (_inputManager.IsKeyPressed(SDLK_w))
        _camera.SetPosition(_camera.GetPosition() + glm::vec2(0.0f, CAMERA_SPEED));
    else if (_inputManager.IsKeyPressed(SDLK_s))
        _camera.SetPosition(_camera.GetPosition() + glm::vec2(0.0f, -CAMERA_SPEED));

    if (_inputManager.IsKeyPressed(SDLK_a))
        _camera.SetPosition(_camera.GetPosition() + glm::vec2(-CAMERA_SPEED, 0.0f));
    else if (_inputManager.IsKeyPressed(SDLK_d))
        _camera.SetPosition(_camera.GetPosition() + glm::vec2(CAMERA_SPEED, 0.0f));

    if (_inputManager.IsKeyPressed(SDLK_q))
        _camera.SetScale(_camera.GetScale() + SCALE_SPEED);
    else if (_inputManager.IsKeyPressed(SDLK_e))
        _camera.SetScale(_camera.GetScale() - SCALE_SPEED);

    if (_inputManager.IsKeyPressed(SDL_BUTTON_LEFT))
    {
        glm::vec2 mouseCoords = _inputManager.GetMouseCoords();
        mouseCoords = _camera.ScreenToWorld(mouseCoords);

        glm::vec2 playerPos(0.0f);
        glm::vec2 direction = mouseCoords - playerPos;
        direction = glm::normalize(direction);

        _bullets.emplace_back(Bullet(playerPos, direction, 3.0f, 1000));
    }*/
}


void MainGame::Update()
{
    while (_gameState != GameState::EXIT)
    {
        _fpsLimiter.BeginFrame();

        ProcessInput();
        _time += 0.1f;

        _camera.Update();

        for (int i = 0; i < _bullets.size();)
        {
            _bullets[i].Update();
            if (!_bullets[i].IsAlive())
            {
                _bullets[i] = _bullets.back();
                _bullets.pop_back();
            }
            else
            {
                i++;
            }
        }

        //_circle.SetPosition(_circle.GetPosition() + glm::vec2(10,0));
        _currentLevel->Update();
        Draw();

        _fps = _fpsLimiter.EndFrame();

        // print only once every 1000 frames
        static int frameCounter = 0;
        frameCounter++;
        if (frameCounter == 1000)
        {
            std::cout << _fps << std::endl;
            frameCounter = 0;
        }
    }
}

void MainGame::Draw()
{
    // Set the base depth to 1.0
    glClearDepth(1.0);
    // Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Enable the shader
    _textureProgram.Use();

    // We are using texture unit 0
    glActiveTexture(GL_TEXTURE0);

    // Get the uniform location
    GLint textureLocation = _textureProgram.GetUniformLocation("mySampler");
    // Tell the shader that the texture is in texture unit 0
    glUniform1i(textureLocation, 0);

    // Set the camera matrix
    GLint pLocation = _textureProgram.GetUniformLocation("transformationMatrix");
    glm::mat4 projectionMatrix = _camera.GetCameraMatrix();

    glUniformMatrix4fv(pLocation, 1, GL_FALSE, &projectionMatrix[0][0]);

    // Draw stuff!
    _spriteBatch.Begin();

    for (int i = 0; i < _bullets.size(); i++)
    {
        _bullets[i].Draw(_spriteBatch);
    }
    _currentLevel->Draw(_spriteBatch);

    _circle.Draw(_spriteBatch);
    _circle2.Draw(_spriteBatch);
    _spriteBatch.End();
    _spriteBatch.Render();

    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);

    // Disable the shader
    _textureProgram.Unuse();


    _window.SwapBuffer();
}

void MainGame::InitLevels()
{
    _currentLevel = new Level("levels/level1.txt");
    _levels.push_back(_currentLevel);
    _currentLevel->Init();
}


