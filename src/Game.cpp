#include "Game.hpp"
#include "RealPlayer.hpp"
#include "ComputerPlayer.hpp"

namespace mastermind
{
Game::Game(const std::shared_ptr<IUserInterface>& p_userInterface,
           Size p_numberOfRows,
           Size p_patternSize) noexcept :
    userInterface(p_userInterface),
    board(std::make_shared<Board>(p_userInterface, p_numberOfRows, p_patternSize))
{}

void Game::start()
{
    auto gameEngine = createGameEngine();
    gameEngine->run();
}

std::unique_ptr<IGameEngine> Game::createGameEngine() const
{
    auto gameMode = userInterface->selectGameMode();
    auto player1 = createRealPlayer();
    auto player2 = (gameMode == GameMode::single) ? createComputerPlayer()
                                                  : createRealPlayer();

    return std::make_unique<GameEngine>(userInterface, board, player1, player2);
}

std::shared_ptr<IPlayer> Game::createRealPlayer() const
{
    auto username = userInterface->insertUsername();
    return std::make_shared<RealPlayer>(userInterface, username);
}

std::shared_ptr<IPlayer> Game::createComputerPlayer() const
{
    return std::make_shared<ComputerPlayer>();
}
}
