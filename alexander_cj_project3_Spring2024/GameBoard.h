#ifndef MINESWEEPER_GAMEBOARD_H
#define MINESWEEPER_GAMEBOARD_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "HelperFunctions.h"
#include <vector>
#include <random>
using namespace std;

class GameBoard {
    int columns, rows, mines;
    bool minesShown = false;
    bool gamePaused = false;
    bool gameWon;
    bool gameLost;
    HelperFunctions helper;
    vector<vector<Tile*>> board;
public:
    GameBoard(int columns, int rows, int mines, bool gameWon, bool gameLost);
    ~GameBoard();
    void createBoard();
    void gameActive(sf::RenderWindow &window, Tile *tile, float x, float y);
    void gameNotActive(sf::RenderWindow &window, Tile *tile, float x, float y);
    void drawBoard(sf::RenderWindow &window);
    void handleLeftClick(sf::RenderWindow &window);
    void handleRightClick(sf::RenderWindow &window);
    void placeMines();
    void loadNumbers();
    void resetBoard();
    int countMines();
    void showMines(sf::RenderWindow &window);
    void toggleMinesShown();
    void toggleGamePaused();
    bool returnGameState();
    void handleGameLoss(sf::RenderWindow &window);
    bool returnGameLoss();
    bool returnGameWon();
    void finishGame();
    void justWin(sf::RenderWindow &window);
};


#endif //MINESWEEPER_GAMEBOARD_H
