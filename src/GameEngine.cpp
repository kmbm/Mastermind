#include "GameEngine.hpp"
#include "GuessChecker.hpp"

namespace mastermind
{
GameEngine::GameEngine(
    const std::shared_ptr<IUserInterface>& p_userInterface,
    const std::shared_ptr<Board>& p_board,
    const std::shared_ptr<IPlayer>& p_player1,
    const std::shared_ptr<IPlayer>& p_player2) noexcept :
        userInterface(p_userInterface),
        board(p_board),
        codemaker(p_player1),
        codebreaker(p_player2)
{}

void GameEngine::run()
{
    auto numberOfRounds = userInterface->insertNumberOfRounds();
    for (size_t roundIdx = 0; roundIdx < numberOfRounds; ++roundIdx)
    {
        playRound();
        changePlayerRoles();
        board->clear();
    }
    checkGameResult();
}

void GameEngine::playRound()
{
    displayRoundInfo();

    auto pattern = codemaker->createPattern(board->getRowSize());
    auto guessChecker = GuessChecker(pattern);

    bool isPatternGuessed = false;
    size_t numberOfTries = 0;
    while (not isPatternGuessed and numberOfTries < board->getNumberOfRows())
    {
        ++numberOfTries;
        auto guess = codebreaker->makeGuess(board->getRowSize());
        Result result;
        tie(result, isPatternGuessed) = guessChecker.check(guess);
        board->update(Row(guess, result));
    }

    addCodemakerPoints(isPatternGuessed, numberOfTries);
    displayGuessResult(isPatternGuessed, numberOfTries);
}

void GameEngine::displayRoundInfo() const
{
    userInterface->displayText(codemaker->getName() + " is codemaker");
    userInterface->displayText(codebreaker->getName() + " is codebreaker");
}

void GameEngine::displayGuessResult(bool p_isPatternGuessed, size_t p_numberOfTries) const
{
    p_isPatternGuessed ? userInterface->displayText("Pattern found in " + std::to_string(p_numberOfTries) + " tries")
                       : userInterface->displayText("Pattern not guessed, codemaker receives double points");
}

void GameEngine::addCodemakerPoints(bool p_isPatternGuessed, size_t p_numberOfTries)
{
    p_isPatternGuessed ? codemaker->addPoints(p_numberOfTries)
                       : codemaker->addPoints(2 * p_numberOfTries);
}

void GameEngine::checkGameResult() const
{
    auto codemakerPoints = codemaker->getPoints();
    auto codebreakerPoints = codebreaker->getPoints();

    if (codemakerPoints == codebreakerPoints)
    {
        userInterface->displayText("Draw");
    }
    else if (codemakerPoints > codebreakerPoints)
    {
        userInterface->displayText(codemaker->getName() + " wins the game!");
    }
    else
    {
        userInterface->displayText(codebreaker->getName() + " wins the game!");
    }
}

void GameEngine::changePlayerRoles()
{
    auto tmp = std::move(codemaker);
    codemaker = std::move(codebreaker);
    codebreaker = std::move(tmp);
}
}
