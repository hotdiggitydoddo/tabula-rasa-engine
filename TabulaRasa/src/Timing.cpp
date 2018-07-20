#include "Timing.h"

#include <SDL.h>

namespace TabulaRasa
{

FPSLimiter::FPSLimiter()
{

}

void FPSLimiter::Init(float maxFPS)
{
    SetMaxFPS(maxFPS);
}

void FPSLimiter::BeginFrame()
{
    _startTicks = SDL_GetTicks();
}

float FPSLimiter::EndFrame()
{
    CalculateFPS();

    float frameTicks = SDL_GetTicks() - _startTicks;
    // Limit the FPS to the max FPS
    if (1000.0f / _maxFps > frameTicks)
    {
        SDL_Delay(1000.0f / _maxFps - frameTicks);
    }

    return _fps;
}

void FPSLimiter::SetMaxFPS(float maxFPS)
{
    _maxFps = maxFPS;
}

void FPSLimiter::CalculateFPS()
{
    static const int NUM_SAMPLES = 10;
    static float frameTimes[NUM_SAMPLES];
    static int currentFrame = 0;

    static float prevTicks = SDL_GetTicks();
    float currentTicks;

    currentTicks = SDL_GetTicks();

    _frameTime = currentTicks - prevTicks;
    frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;
    prevTicks = currentTicks;

    int count;

    currentFrame++;
    if (currentFrame < NUM_SAMPLES)
    {
        count = currentFrame;
    }
    else
    {
        count = NUM_SAMPLES;
    }

    float frameTimeAverage = 0;
    for (int i = 0; i < count; i++)
    {
        frameTimeAverage += frameTimes[i];
    }
    frameTimeAverage /= count;

    if (frameTimeAverage > 0)
    {
        _fps = 1000.0f / frameTimeAverage;
    }
    else
    {
        _fps = 70.0f;
    }
}

}

