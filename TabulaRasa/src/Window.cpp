#include "Window.h"
#include "Errors.h"

namespace TabulaRasa
{
int Window::Create(const std::string& windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
{
    Uint32 flags = SDL_WINDOW_OPENGL;

    if (currentFlags & INVISIBLE)
    {
        flags |= SDL_WINDOW_HIDDEN;
    }
    if (currentFlags & FULL_SCREEN)
    {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    if (currentFlags & BORDERLESS)
    {
        flags |= SDL_WINDOW_BORDERLESS;
    }

    // Open a SDL window
    _sdlWindow = SDL_CreateWindow(windowName.c_str(),
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  screenWidth,
                                  screenHeight,
                                  flags);
    if (_sdlWindow == nullptr)
    {
        FatalError("SDL window could not be created!");
    }


    SDL_GLContext glCtx = SDL_GL_CreateContext(_sdlWindow);
    if (glCtx == nullptr)
    {
        FatalError("SDL_GL context could not be created!");
    }

    GLuint vertexArrayID = 0;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);

    int glVersionMajor;
    int glVersionMinor;
    glGetIntegerv(GL_MAJOR_VERSION, &glVersionMajor);
    glGetIntegerv(GL_MINOR_VERSION, &glVersionMinor);
    printf("\n=== OpenGL Implementation ===\n");
    printf("Vendor:                   %s\n", glGetString(GL_VENDOR));
    printf("GL Version:               %s\n", glGetString(GL_VERSION));
    printf("GL Version (Strict):      %d.%d\n", glVersionMajor, glVersionMinor);
    printf("GLSL Version:             %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    glClearColor(0.392f, 0.584f, 0.929f, 1.0f);

    // Set v-sync
    SDL_GL_SetSwapInterval(1);

    // Enable alpha blend
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);;

    return 0;
}

void Window::SwapBuffer()
{
    SDL_GL_SwapWindow(_sdlWindow);
}
}

