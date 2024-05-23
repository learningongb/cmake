#pragma once

#include <string>

class Player
{
public:
    std::string name;
    virtual int make_move(int&, int&) = 0;
};