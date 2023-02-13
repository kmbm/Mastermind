#pragma once

#include "Types.hpp"

namespace mastermind
{
class GuessChecker
{
public:
    GuessChecker(const Pattern&) noexcept;

    std::tuple<Result, bool> check(const Guess&) const;
private:
    bool isPatternGuessed(const Result&) const;

    Pattern pattern;
};
}
