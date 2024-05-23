#pragma once

#include <string>
#include <iostream>

#include "player.h"

class Human: public Player
{
public:
    Human() {};
    Human(std::string inName)
    {
        name = inName;
    };

    int make_move(int& max_count_per_move, int& count) override
    {
        int max_count = std::min(max_count_per_move, count);
        int result = 0;
        do
        {
            std::cout << name << " - cколько спичек убрать (от 1 до " << max_count << ")?" << std::endl;
            std::cin >> result;
        } while (result < 1 || result > max_count);
        
        return result;
    }
};