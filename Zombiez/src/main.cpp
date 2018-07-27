#include "MainGame.h"

int main(int argc, char** argv)
{
    MainGame game(1024, 768, time(nullptr));
    game.Run();

    return 0;
}