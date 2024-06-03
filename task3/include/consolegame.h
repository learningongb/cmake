#pragma once

#include <string>
#include <vector>
#include <memory>

#include "game.h"
#include "player.h"
#include "simpleboard.h"
#include "consoleplayer.h"

class ConsoleGame : public IGame
{
public:
    ConsoleGame() = default;
    ConsoleGame(const std::string&, IBoard*);
    ~ConsoleGame() = default;

    virtual std::string name() const override { return m_name;}
    virtual bool setup(IBoard* board) override;
    virtual bool waitForPlayer(uint64_t timeout) override;
    virtual int exec() override;

protected:
    void renderBoard() const;
    int calculateVictory();

private:
    std::string m_name;
    std::vector<IPlayer*> m_players;
    std::unique_ptr<IBoard> m_board; 
};