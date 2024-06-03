#pragma once

#include "game.h"

class GameManager
{
public:
    IGame* createGame(const std::string& name) const;
};