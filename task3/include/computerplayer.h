#pragma once

#include <ctime>

#include "player.h"

class ComputerPlayer : public IPlayer
{
public:
    ComputerPlayer() = default;
    ComputerPlayer(const std::string& name) : m_name(name) {srand(std::time(nullptr));}
    ~ComputerPlayer() = default;

    virtual std::string name() const override;
    virtual std::optional<IBoard::PositionType> getMove(uint64_t timeout = -1) const override;

private:
    std::string m_name;

};