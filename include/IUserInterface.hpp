#pragma once

#include "Types.hpp"
#include <memory>

namespace mastermind
{
class IUserInterface
{
public:
    virtual Username insertUsername() const = 0;
    virtual Pattern insertPattern(Size) const = 0;
    virtual Guess insertGuess(Size) const = 0;
    virtual NumberOfRounds insertNumberOfRounds() const = 0;
    virtual GameMode selectGameMode() const = 0;
    virtual void displayBoard(const Rows&) const = 0;
    virtual void displayText(const std::string&) const = 0;

    virtual ~IUserInterface() = default;
};
}
