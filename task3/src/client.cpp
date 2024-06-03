
#include <memory>
#include <iostream>

#include "gamemanager.h"

int main()
{
    GameManager gameManager;
    while (true)
    {
        std::unique_ptr<IGame> game;
        std::cout << "Create local game?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int answer = 0;
        std::cin >> answer;
        switch (answer)
        {
            case 1:
            {
                std::cout << "Creating game" << std::endl;
                game.reset(gameManager.createGame("console_game"));
            }
            
                break;
            case 2:
                return 0;
            default: break;
        }

        if (game)
        {
            std::cout << "game created" << std::endl;
            if (game->waitForPlayer(30000))
                game->exec();
        }
        else
        {
            std::cout << "game NOT created" << std::endl;
        }
    }
    return 0;
}