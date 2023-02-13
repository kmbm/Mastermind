#include "Game.hpp"
#include "ConsoleInterface.hpp"

int main()
{
    mastermind::Size numberOfBoardRows = 12;
    mastermind::Size patternSize = 5;

    auto userInterface = std::make_shared<mastermind::ConsoleInterface>();
    mastermind::Game game(userInterface, numberOfBoardRows, patternSize);
    game.start();
    return 0;
}
