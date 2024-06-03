#pragma once

#include <string>

#include "board.h"

class IGame
{
public:
    virtual ~IGame() = default;
    virtual std::string name() const {return "";}
    virtual bool setup(IBoard* board) = 0;
    virtual bool waitForPlayer(uint64_t timeout) = 0;
    virtual int exec() = 0;
};