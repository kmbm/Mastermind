#include "GuessChecker.hpp"
#include <algorithm>

namespace mastermind
{
GuessChecker::GuessChecker(const Pattern& p_pattern) noexcept :
    pattern(p_pattern)
{}

std::tuple<Result, bool> GuessChecker::check(const Guess& p_guess) const
{
    Result result;
    std::vector<size_t> guessedPegsIdxs;
    for (size_t idx = 0; idx < p_guess.size(); ++idx)
    {
        if (p_guess[idx] == pattern[idx])
        {
            result.push_back(KeyPeg::black);
            guessedPegsIdxs.push_back(idx);
        }
    }
    for (size_t guessIdx = 0; guessIdx < p_guess.size(); ++guessIdx)
    {
        if (p_guess[guessIdx] != pattern[guessIdx])
        {
            for (size_t patternIdx = 0; patternIdx < pattern.size(); ++patternIdx)
            {
                if (p_guess[guessIdx] == pattern[patternIdx] and
                    std::find(guessedPegsIdxs.begin(), guessedPegsIdxs.end(), patternIdx) == guessedPegsIdxs.end())
                {
                    result.push_back(KeyPeg::white);
                    guessedPegsIdxs.push_back(patternIdx);
                    break;
                }
            }
        }
    }
    return std::tuple<Result, bool>{result, isPatternGuessed(result)};
}

bool GuessChecker::isPatternGuessed(const Result& p_result) const
{
    return p_result.size() == pattern.size() and std::all_of(p_result.begin(),
                                                             p_result.end(),
                                                             [](auto peg){ return peg == KeyPeg::black; });
}
}
