#pragma once

#include "IUserInterface.hpp"

namespace mastermind
{
class ConsoleInterface : public IUserInterface
{
public:
    Username insertUsername() const override;
    GameMode selectGameMode() const override;
    Pattern insertPattern(Size) const override;
    Guess insertGuess(Size) const override;
    NumberOfRounds insertNumberOfRounds() const override;
    void displayBoard(const Rows&) const override;
    void displayText(const std::string&) const override;

private:
    template <typename T, typename F>
    T insertData(F) const;

    template <typename T, typename = std::enable_if_t<std::is_enum<T>::value>>
    T insertData() const;

    Guess insertRowOfPegs(Size) const;
    void inputValidationFailure() const;
};
}
