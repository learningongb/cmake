#pragma once

#include "player.h"

class ConsolePlayer : public IPlayer
{
public:
    ConsolePlayer() = default;
    ConsolePlayer(const std::string& name) : m_name(name) {}
    ~ConsolePlayer() = default;

    virtual std::string name() const override;
    virtual std::optional<IBoard::PositionType> getMove(uint64_t timeout = -1) const override;

private:
    std::string m_name;

};