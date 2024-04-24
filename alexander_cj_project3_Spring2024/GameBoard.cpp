#include "GameBoard.h"

GameBoard::GameBoard(int columns, int rows, int mines, bool gameWon, bool gameLost) {
    this->columns = columns;
    this->rows = rows;
    this->mines = mines;
    this->gameWon = gameWon;
    this->gameLost = gameLost;
}

void GameBoard::createBoard() {
    board.resize(rows);
    for (int i = 0; i < rows; ++i) {
        board[i].resize(columns);
        for (int j = 0; j < columns; ++j) {
            board[i][j] = new Tile();
        }
    }

    placeMines();
    loadNumbers();
}

GameBoard::~GameBoard() {
    for (auto &row : board) {
        for (Tile* &tile : row) {
            delete tile;
        }
    }
}

void GameBoard::gameActive(sf::RenderWindow &window, Tile *tile, float x, float y) {
    tile->moveTile(x, y);
    tile->drawTile(window);
    if (tile->checkFlag()) tile->drawFlag(window);
}

void GameBoard::gameNotActive(sf::RenderWindow &window, Tile *tile, float x, float y) {
    tile->moveTile(x, y);
    tile->drawRevealedTile(window);
}

void GameBoard::drawBoard(sf::RenderWindow &window) {
    float x = 0;
    float y = -32;
    for (auto &row : board) {
        x = 0;
        y += 32;
        for (Tile* &tile : row) {
            if (gamePaused) gameNotActive(window, tile, x, y);
            else gameActive(window, tile, x, y);
            x += 32;
        }
    }

    if (minesShown) {
        showMines(window);
    }

    if (gameLost) {
        handleGameLoss(window);
    }

    if (gameWon) {
        handleGameLoss(window);
    }
}

void GameBoard::handleLeftClick(sf::RenderWindow &window) {
    int winCondition = (columns * rows) - mines;
    int count = 0;
    for (auto &row : board) {
        for (Tile* &tile : row) {
            if (!tile->checkFlag()) {
                tile->showTile(window);
                if (tile->checkMine() && tile->showTile(window)) {
                    gameLost = true;
                }
                if (!tile->hiddenOrNot() && !tile->checkMine()) {
                    count++;
                }
                if (count == winCondition) {
                    gameWon = true;
                }
            }

        }
    }
}

void GameBoard::handleRightClick(sf::RenderWindow &window) {
    for (auto &row : board) {
        for (Tile* &tile : row) {
            tile->setFlag(window);
        }
    }
}

void GameBoard::loadNumbers() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i > 0) board[i][j]->addAdjacentTile(board[i - 1][j]);
            if (i < rows - 1) board[i][j]->addAdjacentTile(board[i + 1][j]);
            if (j > 0) board[i][j]->addAdjacentTile(board[i][j - 1]);
            if (j < columns - 1) board[i][j]->addAdjacentTile(board[i][j + 1]);
            if (i > 0 && j > 0) board[i][j]->addAdjacentTile(board[i - 1][j - 1]);
            if (i > 0 && j < columns - 1) board[i][j]->addAdjacentTile(board[i - 1][j + 1]);
            if (i < rows - 1 && j > 0) board[i][j]->addAdjacentTile(board[i + 1][j - 1]);
            if (i < rows - 1 && j < columns - 1) board[i][j]->addAdjacentTile(board[i + 1][j + 1]);
        }
    }
}

void GameBoard::placeMines() {
    int placedMines = 0;

    while (placedMines < mines) {
        int tileNumber = helper.randomTile(columns, rows);
        int counter = 0;
        bool mineAttempted = false;

        for (auto &row : board) {
            if (mineAttempted) break;
            for (Tile* &tile : row) {
                counter++;
                if (counter == tileNumber) {
                    mineAttempted = true;
                    if (tile->checkMine()) break;
                    else {
                        tile->placeMine();
                        placedMines++;
                        break;
                    }
                }
            }
        }
    }
}

void GameBoard::resetBoard() {
    for (auto &row : board) {
        for (Tile* &tile : row) {
            delete tile;
            tile = new Tile();
        }
    }

    placeMines();
    loadNumbers();
    if (gamePaused) gamePaused = false;
    if (gameLost) gameLost = false;
    if (gameWon) gameWon = false;
}

int GameBoard::countMines() {
    int mineCount = 0;
    for (auto &row : board) {
        for (Tile* &tile : row) {
            if (tile->checkMine()) {
                mineCount++;
            }

            if (tile->checkFlag()) {
                mineCount--;
            }
        }
    }

    return mineCount;
}

void GameBoard::showMines(sf::RenderWindow &window) {
    for (auto &row : board) {
        for (Tile* &tile : row) {
            if (tile->checkMine()) {
                tile->drawMine(window);
            }
        }
    }
}

void GameBoard::toggleMinesShown() {
    minesShown = !minesShown;
}

void GameBoard::toggleGamePaused() {
    gamePaused = !gamePaused;
}

void GameBoard::handleGameLoss(sf::RenderWindow &window) {
    for (auto &row : board) {
        for (Tile* &tile : row) {
            if (tile->checkMine()) {
                tile->drawRevealedTile(window);
                tile->drawMine(window);
            }
        }
    }
}

bool GameBoard::returnGameLoss() {
    return gameLost;
}

bool GameBoard::returnGameWon() {
    return gameWon;
}

void GameBoard::justWin(sf::RenderWindow &window) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns - 1; ++j) {
            if (!board[i][j]->checkMine()) {
                board[i][j]->drawRevealedTile(window);
            }
        }
    }
}

void GameBoard::finishGame() {
    gameWon = false;
}

bool GameBoard::returnGameState() {
    return gamePaused;
}
