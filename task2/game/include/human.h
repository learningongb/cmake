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

    int make_move(int& max_count_per_move, int& count) override;
};