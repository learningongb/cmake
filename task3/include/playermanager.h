#pragma once

#include <iostream>

#include "player.h"
#include "consoleplayer.h"
#include "computerplayer.h"

class PlayerManager
{
public:
    static IPlayer* selectPlayer(int count)
    {
        int answer = 0;
        while (true)
        {
            std::cout << "1. Human" << std::endl;
            std::cout << "2. Computer" << std::endl;
            std::cin >> answer;
            switch (answer)
            {  
            case 1:
                while (true)
                {
                    std::cout << "Enter name of player" << std::endl;
                    std::string name;
                    std::cin >> name;
                    if (name.empty())
                        continue;

                    return new ConsolePlayer(name);
                }
            case 2:
                return new ComputerPlayer("Player " + (count + 1));
            }
        }
        
    }

};