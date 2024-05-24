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

    int make_move(int& max_count_per_move, int& count) override;
};