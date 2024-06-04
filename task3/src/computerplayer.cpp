#include "computerplayer.h"

#include <iostream>
#include <optional>

std::string ComputerPlayer::name() const
{ return m_name; }

std::optional<IBoard::PositionType> ComputerPlayer::getMove(uint64_t /*timeout = -1*/) const
{
    int number = rand() % 9;
    IBoard::PositionType pos;
    pos.x = number % 3;
    pos.y = number / 3;

    return pos;
}