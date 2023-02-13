#pragma once

#include "GameEngine.hpp"

namespace mastermind
{
class Game
{
public:
    Game(const std::shared_ptr<IUserInterface>&, Size, Size) noexcept;
    void start();

private:
    std::unique_ptr<IGameEngine> createGameEngine() const;
    std::shared_ptr<IPlayer> createRealPlayer() const;
    std::shared_ptr<IPlayer> createComputerPlayer() const;

    std::shared_ptr<IUserInterface> userInterface;
    std::shared_ptr<Board> board;
};
}
