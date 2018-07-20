#include "TabulaRasa.h"
#include <SDL.h>
#include <OpenGL/gl3.h>

namespace TabulaRasa
{
int Init()
{
    // init SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    return 0;
}
}

