#include "Board.hpp"
#include <algorithm>

namespace mastermind
{
Board::Board(
    const std::shared_ptr<IUserInterface>& p_userInterface,
    Size p_numberOfRows,
    Size p_rowSize) noexcept :
        userInterface(p_userInterface),
        numberOfRows(p_numberOfRows),
        rowSize(p_rowSize)
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

Size Board::getRowSize() const
{
    return rowSize;
}

Size Board::getNumberOfRows() const
{
    return numberOfRows;
}
}
