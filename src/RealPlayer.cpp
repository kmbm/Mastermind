#include "RealPlayer.hpp"

namespace mastermind
{
RealPlayer::RealPlayer(
    const std::shared_ptr<IUserInterface>& p_userInterface,
    const Username& p_username) noexcept :
        IPlayer(p_username),
        userInterface(p_userInterface)
{}

Pattern RealPlayer::createPattern(Size p_rowSize)
{
    return userInterface->insertPattern(p_rowSize);
}

Guess RealPlayer::makeGuess(Size p_rowSize)
{
    return userInterface->insertGuess(p_rowSize);
}
}
