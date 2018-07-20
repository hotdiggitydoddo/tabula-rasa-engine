#include "Errors.h"

#include <iostream>
#include <SDL.h>
#include <cstdlib>

namespace TabulaRasa
{
void FatalError(std::string errorStr)
{
    std::cout << errorStr << std::endl;
    std::cout << "Enter any key to quit...";
    std::cin.get();
    SDL_Quit();
    exit(69);
}
}
