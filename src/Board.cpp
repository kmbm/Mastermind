#include "Board.hpp"
#include <algorithm>

namespace mastermind
{
Board::Board(
    const std::shared_ptr<IUserInterface>& p_userInterface,
    Size p_numberOfRows,
    Size p_patternSize) noexcept :
        userInterface(p_userInterface),
        numberOfRows(p_numberOfRows),
        patternSize(p_patternSize)
{}

void Board::update(const Row& p_newRow)
{
    rows.push_back(p_newRow);
    userInterface->displayBoard(rows);
}

void Board::clear()
{
    rows.clear();
}

Size Board::getPatternSize() const
{
    return patternSize;
}

Size Board::getNumberOfRows() const
{
    return numberOfRows;
}
}
