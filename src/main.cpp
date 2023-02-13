#include "Game.hpp"
#include "ConsoleInterface.hpp"

int main()
{
    mastermind::Size numberOfBoardRows = 12;
    mastermind::Size sizeOfBoardRow = 5;

    auto userInterface = std::make_shared<mastermind::ConsoleInterface>();
    mastermind::Game game(userInterface, numberOfBoardRows, sizeOfBoardRow);
    game.start();
    return 0;
}
