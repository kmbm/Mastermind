#include "ConsoleInterface.hpp"
#include <limits>
#include <ios>
#include <iostream>

namespace mastermind
{
Username ConsoleInterface::insertUsername() const
{
    displayText("Insert your name");
    auto inputValidator = [](const Username&){ return true; };
    return insertData<Username>(inputValidator);
}

GameMode ConsoleInterface::selectGameMode() const
{
    displayText("Select game mode: singleplayer[0] multiplayer[1]");
    return insertData<GameMode>();
}

Pattern ConsoleInterface::insertPattern(Size rowSize) const
{
    displayText("Insert pattern");
    return insertRowOfPegs(rowSize);
}

Guess ConsoleInterface::insertGuess(Size rowSize) const
{
    displayText("Insert your guess");
    return insertRowOfPegs(rowSize);
}

NumberOfRounds ConsoleInterface::insertNumberOfRounds() const
{
    displayText("Insert how many rounds do you want to play [should be even] ");
    auto inputValidator = [](NumberOfRounds num){ return num % 2 == 0; };
    return insertData<NumberOfRounds>(inputValidator);
}

void ConsoleInterface::displayBoard(const Rows& p_rows) const
{
    displayText("Board");
    for (size_t i = 0; i < p_rows.size(); ++i)
    {
        for (auto peg : p_rows[i].guess)
        {
            std::cout << static_cast<std::underlying_type_t<CodePeg>>(peg) << " ";
        }
        std::cout << "    ";
        for (auto peg : p_rows[i].result)
        {
            std::cout << static_cast<std::underlying_type_t<KeyPeg>>(peg) << " ";
        }
        std::cout << std::endl;
    }
}

void ConsoleInterface::displayText(const std::string& p_text) const
{
    std::cout << p_text << std::endl;
}

template <typename T, typename F>
T ConsoleInterface::insertData(F inputValidator) const
{
    T input;
    for (;;)
    {
        if (std::cin >> input and inputValidator(input))
        {
            break;
        }
        else
        {
            inputValidationFailure();
        }
    }
    return input;
}

template <typename T, typename = std::enable_if_t<std::is_enum<T>::value>>
T ConsoleInterface::insertData() const
{
    std::underlying_type_t<T> input;
    for (;;)
    {
        if (std::cin >> input and isInRange(static_cast<T>(input)))
        {
            break;
        }
        else
        {
            inputValidationFailure();
        }
    }
    return static_cast<T>(input);
}

void ConsoleInterface::inputValidationFailure() const
{
    displayText("Invalid value");
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Guess ConsoleInterface::insertRowOfPegs(Size p_rowSize) const
{
    Guess guess;
    guess.reserve(p_rowSize);

    for (size_t i = 0; i < p_rowSize; ++i)
    {
        guess.push_back(insertData<CodePeg>());
    }
    return guess;
}
}
