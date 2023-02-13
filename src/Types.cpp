#include "Types.hpp"

namespace mastermind
{
bool isInRange(GameMode mode)
{
    switch (mode)
    {
        case GameMode::single:
        case GameMode::multi:
            return true;
    }
    return false;
}

bool isInRange(CodePeg peg)
{
    switch (peg)
    {
        case CodePeg::red:
        case CodePeg::blue:
        case CodePeg::green:
        case CodePeg::yellow:
        case CodePeg::purple:
            return true;
    }
    return false;
}

bool isInRange(KeyPeg peg)
{
    switch (peg)
    {
        case KeyPeg::white:
        case KeyPeg::black:
            return true;
    }
    return false;
}
}
