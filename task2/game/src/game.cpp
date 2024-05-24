#include <iostream>

#include "game.h"

void Game::init()
{
    std::cout << "Введите количество спичек:\n";
    std::cin >> count;
    std::cout << "Введите максимальное количество спичек, убираемых за 1 ход:\n";
    std::cin >> max_count_per_move;

    player1 = new Human("Player1");
    player2 = new Computer("Computer");
}

void Game::next_move()
{
    whos_move = !whos_move;
    int move_count;
    int max_count = std::min(max_count_per_move, count);
    if (whos_move)
        move_count = player1->make_move(max_count_per_move, count);
    else
        move_count = player2->make_move(max_count_per_move, count);
    count -= move_count;
    std::cout << "Осталось спичек " << count << std::endl;
    if (count == 0)
    {
        Player* winner = whos_move ? player2 : player1;
        std::cout << winner->name << " победил!" << std::endl;
    }
}

bool Game::is_end()
{
    return (count < 1);
}
