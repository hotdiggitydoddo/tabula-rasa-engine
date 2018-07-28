#pragma once

#include <random>

class RNG
{
public:
    RNG(int seed) : gen(seed) {} // Seeds the mt19937.

    int getRandomInt(int min, int max)
    {
        std::uniform_int_distribution<int> dis(min, max);
        int random = dis(gen);
        return random;
    }

    float getFloat(float min, float max)
    {
        std::uniform_real_distribution<float> dis(min, max);
        float random = dis(gen);
        return random;
    }

    double getRandomDouble(double min, double max)
    {
        std::uniform_real_distribution<double> dis(min, max);
        double random = dis(gen);
        return random;
    }

    double getRandom(unsigned int max)
    {
        std::uniform_real_distribution<double> dis(0, max);
        double random = dis(gen);
        return random;
    }

    void seed(unsigned int seed)
    {
        gen.seed(seed);
    }

private:
    std::mt19937 gen;
};