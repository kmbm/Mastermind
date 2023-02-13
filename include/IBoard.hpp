#pragma once

#include "Types.hpp"

namespace mastermind
{
class IBoard
{
public:
    virtual void update(const Row&) = 0;
    virtual void clear() = 0;
    virtual Size getPatternSize() const = 0;
    virtual Size getNumberOfRows() const = 0;

    virtual ~IBoard() = default;
};
}
