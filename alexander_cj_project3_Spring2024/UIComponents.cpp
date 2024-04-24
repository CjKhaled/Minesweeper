#include "UIComponents.h"

UIComponents::UIComponents(float columns, float rows, int mines, map<string, string> &database) {
    this->columns = columns;
    this->rows = rows;
    this->mines = mines;
    this->database = database;
    auto iter = this->database.begin();
    this->name = iter->first;
}

void UIComponents::drawUI(sf::RenderWindow &window, GameBoard &board, bool gameLost, bool gameWon) {
    if (gameLost) {
        face.gameLose(window);
        timer.pauseTimer();
    }

    if (gameWon) {
        face.gameWin(window);
        timer.pauseTimer();
        string time = timer.getTime();
        time = time.insert(2, ":");
        leaderBoard.addToLeaderBoard(name, time);
        leaderBoard.drawLeaderBoard(columns, rows, board);
    }

    mines = board.countMines();
    face.drawFace(columns, rows, window);
    counter.drawCounter(mines, rows, window);
    debug.drawDebug(columns, rows, window);
    pause.drawButton(columns, rows, window);
    leaderBoard.drawLeaderBoardButton(columns, rows, window);
    timer.drawTimer(columns, rows, window);
}

void UIComponents::handleClick(sf::RenderWindow &window, GameBoard &board, bool gameLost) {
    face.resetGame(window, board, pause, timer);
    if (!gameLost) {
        if (!pause.returnPausedStatus()) {
            debug.toggleMines(window, board);
        }
        pause.pauseGame(window, board, timer);
        leaderBoard.handleClick(window, columns, rows, board);
    }

}

bool UIComponents::leaderBoardStatus() {
    return leaderBoard.checkLeaderBoardState();
}

