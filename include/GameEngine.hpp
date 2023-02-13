#pragma once

#include "Board.hpp"
#include "IPlayer.hpp"
#include <memory>

namespace mastermind
{

class IGameEngine
{
public:
    virtual void run() = 0;
    ~IGameEngine() = default;
};

class GameEngine : public IGameEngine
{
public:
    GameEngine(
        const std::shared_ptr<IUserInterface>&,
        const std::shared_ptr<Board>&,
        const std::shared_ptr<IPlayer>&,
        const std::shared_ptr<IPlayer>&) noexcept;

    void run() override;

private:
    void playRound();
    void displayRoundInfo() const;
    void displayGuessResult(bool, size_t) const;
    void addCodemakerPoints(bool, size_t);
    void checkGameResult() const;
    void changePlayerRoles();

    std::shared_ptr<IUserInterface> userInterface;
    std::shared_ptr<Board> board;

    std::shared_ptr<IPlayer> codemaker;
    std::shared_ptr<IPlayer> codebreaker;
};
}
