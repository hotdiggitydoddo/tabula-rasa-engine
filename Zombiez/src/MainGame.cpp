#include "MainGame.h"

#include <iostream>
#include <TabulaRasa/TabulaRasa.h>
#include <TabulaRasa/Errors.h>
#include "RNG.h"


RNG MainGame::RandomEngine(0);

MainGame::MainGame(int width, int height, unsigned int seed)
    :
    _screenWidth(width),
    _screenHeight(height),
    _time(0.0f),
    _maxFps(60.0f),
    _currentLevelIndex(-1)
{
}

MainGame::~MainGame()
{
    for (auto& level : _levels)
        delete level;
}

void MainGame::InitSystems()
{
    TabulaRasa::Init();

    RandomEngine.seed(1);
    _window.Create("Zombiez!", _screenWidth, _screenHeight, 0);
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    InitShaders();
    _spriteBatch.Init();
    _fpsLimiter.Init(_maxFps);
    _camera.Init(_screenWidth, _screenHeight);
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
    InitLevels();
    _currentLevelIndex = 0;
    _gameState = GameState::PLAY;
    Update();
}

void MainGame::ProcessInput()
{
    SDL_Event event;

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
}

void MainGame::Update()
{
    while (_gameState != GameState::EXIT)
    {
        _fpsLimiter.BeginFrame();

        ProcessInput();
        _time += 0.1f;
        _levels[_currentLevelIndex]->Update();
        _camera.Update();

        Draw();

        _fps = _fpsLimiter.EndFrame();

        // print only once every 10 frames
        static int frameCounter = 0;
        frameCounter++;
        if (frameCounter == 10)
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

    _levels[_currentLevelIndex]->Draw(_spriteBatch);

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
    _levels.push_back(new Level("levels/level1.txt"));
    _currentLevelIndex = 0;
    _levels[_currentLevelIndex]->Init(&_inputManager, &_camera);
}


