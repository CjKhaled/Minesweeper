#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HelperFunctions.h"
#include "Tile.h"
#include "GameBoard.h"
#include "UIComponents.h"
using namespace std;

class Game {
    HelperFunctions helper;
    int width;
    int height;
    int mines;
    bool gameWon = false;
    bool gameLost = false;
    map<string, string> database;
public:
    Game(int columns, int rows, int mines, map<string, string> &database);
};


#endif //MINESWEEPER_GAME_H
