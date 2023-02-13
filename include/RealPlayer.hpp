#pragma once

#include "IPlayer.hpp"
#include "IUserInterface.hpp"
#include <memory>

namespace mastermind
{
class RealPlayer : public IPlayer
{
public:
    RealPlayer(
        const std::shared_ptr<IUserInterface>&,
        const Username&) noexcept;

    Pattern createPattern(Size) override;
    Guess makeGuess(Size) override;

private:
    std::shared_ptr<IUserInterface> userInterface;
};
}
