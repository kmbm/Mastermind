#pragma once

#include "IUserInterface.hpp"
#include "IBoard.hpp"
#include <memory>

namespace mastermind
{
class Board : public IBoard
{
public:
    Board(const std::shared_ptr<IUserInterface>&, Size, Size) noexcept;

    void update(const Row&) override;
    void clear() override;
    Size getPatternSize() const override;
    Size getNumberOfRows() const override;

private:
    std::shared_ptr<IUserInterface> userInterface;
    Rows rows;
    Size numberOfRows;
    Size patternSize;
};
}
