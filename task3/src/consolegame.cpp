
#include <iostream>

#include "consolegame.h"
#include "consoleplayer.h"
#include "playermanager.h"

ConsoleGame::ConsoleGame(const std::string& name, IBoard* board) : m_name(name)
{
    setup(board);
} 

bool ConsoleGame::setup(IBoard* board)
{
    if (m_players.empty())
        m_board.reset(board);
    return true;    
}

bool ConsoleGame::waitForPlayer(uint64_t timeout)
{
    while (m_players.size() < 2)
    {
        m_players.emplace_back(PlayerManager::selectPlayer(m_players.size()));
    }
    return true;    
}

void ConsoleGame::renderBoard() const
{
    auto dimension = m_board->dimention();
    const auto& xmin = dimension.first.x;
    const auto& ymin = dimension.first.y;
    const auto& xmax = dimension.second.x;
    const auto& ymax = dimension.second.y;

    IBoard::PositionType pos;
    for (auto y = ymin; y < ymax; y++)
    {
        pos.y = y;
        for (auto x = xmin; x < xmax; x++)
        {
            pos.x = x;
            auto mark = m_board->mark(pos);
            std::string outSymbol = ".";
            switch (mark)
            {
            case IBoard::MARK_X:
                outSymbol = "X";
                break;
            case IBoard::MARK_O:
                outSymbol = "O";
                break;
            
            default:
                break;
            }
            std::cout << "|" << outSymbol << "|";

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


int ConsoleGame::calculateVictory()
{
    auto dimension = m_board->dimention();
    const auto& xmin = dimension.first.x;
    const auto& ymin = dimension.first.y;
    const auto& xmax = dimension.second.x;
    const auto& ymax = dimension.second.y;

    IBoard::PositionType pos;
    IBoard::Mark mark;
    // check gorizontal
    for (int y = ymin; y < ymax; y++)
    {
        pos.y = y;
        pos.x = xmin;
        mark = m_board->mark(pos);
        if (mark == IBoard::Mark::MARK_O || mark == IBoard::Mark::MARK_X)
        {
            bool victory = true;
            for (int x = xmin + 1; x < xmax; x++)
            {
                pos.x = x;
                if (m_board->mark(pos) != mark)
                {
                    victory = false;
                    break;
                }
            }
            if (victory)
                return true;
        }
    }
    // check vertical
    for (int x = xmin; x < xmax; x++)
    {
        pos.x = x;
        pos.y = ymin;
        mark = m_board->mark(pos);
        if (mark == IBoard::Mark::MARK_O || mark == IBoard::Mark::MARK_X)
        {
            bool victory = true;
            for (int y = ymin + 1; y < ymax; y++)
            {
                pos.y = y;
                if (m_board->mark(pos) != mark)
                {
                    victory = false;
                    break;
                }
            }
            if (victory)
                return true;
        }
    }
    // check diagonal 1
    pos.x = xmin;
    pos.y = ymin;
    mark = m_board->mark(pos);
    if (mark == IBoard::Mark::MARK_O || mark == IBoard::Mark::MARK_X)
    {
        bool victory = true;
        for (int i = xmin + 1; i < xmax; i++)
        {
            pos.x = i;
            pos.y = i;
            if (m_board->mark(pos) != mark)
            {
                victory = false;
                break;
            }
        }
        if (victory)
            return true;
    }
    // check diagonal 2
    pos.x = xmin;
    pos.y = ymax - 1;
    mark = m_board->mark(pos);
    if (mark == IBoard::Mark::MARK_O || mark == IBoard::Mark::MARK_X)
    {
        bool victory = true;
        for (int i = xmin + 1; i < xmax; i++)
        {
            pos.x = i;
            pos.y = ymax -1 - i;
            if (m_board->mark(pos) != mark)
            {
                victory = false;
                break;
            }
        }
        if (victory)
            return true;
    }

    return false;
}

int ConsoleGame::exec()
{
    int iplayer = 0;
    while (true)
    {
        renderBoard();
        auto& player = m_players[iplayer];
        bool moveAccepted = false;
        while (!moveAccepted) 
        {
            auto move = player->getMove();
            if (!move)
                return -1;

            auto currentMark = m_board->mark(move.value());
            if (currentMark == IBoard::MARK_EMPTY)
                moveAccepted = m_board->setMark(move.value(), iplayer == 0 ? IBoard::MARK_X : IBoard::MARK_O);
        }
        if (calculateVictory() > 0)
        {
            renderBoard();
            std::cout << "Player " << std::to_string(iplayer+1) << " win" << std::endl;
            return iplayer;
        }
        if (!m_board->hasEmptyPlace())
        {
            renderBoard();
            std::cout << "Draw" << std::endl;
            break;
        }

        iplayer = (iplayer + 1) % 2;
    }
    return -1;

}