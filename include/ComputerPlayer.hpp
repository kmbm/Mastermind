#pragma once

#include "IPlayer.hpp"

namespace mastermind
{
class ComputerPlayer : public IPlayer
{
public:
    ComputerPlayer() noexcept;

    Pattern createPattern(Size) override;
    Guess makeGuess(Size) override;

private:
    Pattern generateRowOfPegs(Size) const;
};
}

