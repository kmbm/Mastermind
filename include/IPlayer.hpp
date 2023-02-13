#pragma once

#include "Types.hpp"

namespace mastermind
{
class IPlayer
{
public:
    IPlayer(const Username& p_username) noexcept :
        username(p_username)
    {}

    virtual ~IPlayer() = default;

    virtual Pattern createPattern(Size) = 0;
    virtual Guess makeGuess(Size) = 0;

    void addPoints(int p_points){ points += p_points; }
    Points getPoints()const{ return points; }
    Username getName()const{ return username; }

protected:
    Username username;

private:
    Points points;
};
}
