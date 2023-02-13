#pragma once

#include <string>
#include <vector>

namespace mastermind
{
enum class GameMode
{
    single,
    multi
};

enum class CodePeg
{
    red,
    blue,
    green,
    yellow,
    purple
};

enum class KeyPeg
{
    white,
    black
};

bool isInRange(GameMode);
bool isInRange(CodePeg);
bool isInRange(KeyPeg);

using Pattern = std::vector<CodePeg>;
using Guess = std::vector<CodePeg>;
using Result = std::vector<KeyPeg>;

struct Row
{
    Row(Guess p_guess, Result p_result) :
        guess(p_guess),
        result(p_result)
    {}

    Guess guess;
    Result result;
};
using Rows = std::vector<Row>;

using Username = std::string;
using NumberOfRounds = uint32_t;
using Size = uint32_t;
using Points = uint32_t;
}
