#pragma once

#include <SDL.h>
#include <OpenGL/gl3.h>
#include <string>

namespace TabulaRasa
{
enum WindowFlags
{
    INVISIBLE = 0x1, FULL_SCREEN = 0x2, BORDERLESS = 0x4
};

class Window
{
public:
    int Create(const std::string& windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
    int GetScreenWidth() { return _screenWidth; }
    int GetScreenHeight() { return _screenHeight; }
    void SwapBuffer();
private:
    SDL_Window* _sdlWindow;
    int _screenWidth, _screenHeight;
};
}


