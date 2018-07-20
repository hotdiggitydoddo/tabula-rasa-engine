#pragma once

namespace TabulaRasa
{

class FPSLimiter
{
public:
    FPSLimiter();
    void Init(float maxFPS);
    void BeginFrame();
    void SetMaxFPS(float maxFPS);
    // Will return the current FPS
    float EndFrame();

private:
    float _fps;
    float _maxFps;
    float _frameTime;
    unsigned int _startTicks;

    void CalculateFPS();
};

}

