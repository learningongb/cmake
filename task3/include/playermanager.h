#pragma once

#include <iostream>

#include "player.h"
#include "consoleplayer.h"

class PlayerManager
{
public:
    static IPlayer* selectPlayer()
    {
        while (true)
        {
            std::cout << "Enter name of players " << std::endl;
            std::string name;
            std::cin >> name;
            if (name.empty())
                continue;

            return new ConsolePlayer(name);
        }
        
    }

};