#pragma once

#include <string>

#include "player.h"

class Computer: public Player
{
public:
    Computer() {};
    Computer(std::string inName)
    {
        name = inName;
    };

    int make_move(int& max_count_per_move, int& count) override
    {
        int result;
        if (count == 1)
        {
            result = 1;
        } 
        else if (max_count_per_move +1 >= count)
        {
            result = count - 1;
        }
        else
        {
            int best_count = ((count - 1)/ (max_count_per_move + 1)) * (max_count_per_move + 1) + 1;
            if (count > best_count)
            {
                result = count - best_count;
            }
            else
            {
                result = 1;
            }
        }
        std::cout << name << " убрал " << result << std::endl;
        return result;
    }
};