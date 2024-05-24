#pragma once

#include "human.h"
#include "player.h"
#include "computer.h"

class Game
{
public:
    void init();
    void next_move();
    bool is_end();

private:
    Player* player1, *player2;
    int count, max_count_per_move;
    bool whos_move = false;

};