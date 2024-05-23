#include "game.h"

int main()
{
    Game game;
    game.init();
    while (!game.is_end())
    {
        game.next_move();
    }
    
}

