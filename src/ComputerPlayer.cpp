#include "ComputerPlayer.hpp"
#include <random>
#include <algorithm>

namespace
{
auto generateRandomNumber(size_t max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, max);

    return distribution(gen);
}
}

namespace mastermind
{
ComputerPlayer::ComputerPlayer() noexcept :
    IPlayer("Computer")
{}

Pattern ComputerPlayer::createPattern(Size p_rowSize)
{
    return generateRowOfPegs(p_rowSize);
}

Guess ComputerPlayer::makeGuess(Size p_rowSize)
{
    return generateRowOfPegs(p_rowSize);
}

Pattern ComputerPlayer::generateRowOfPegs(Size p_rowSize) const
{
    constexpr size_t numOfPegColors = 5;
    Pattern result;
    result.reserve(p_rowSize);

    for (size_t i = 0; i < p_rowSize; ++i)
    {
        auto peg = generateRandomNumber(numOfPegColors - 1);
        result.push_back(static_cast<CodePeg>(peg));
    }
    return result;
}
}
