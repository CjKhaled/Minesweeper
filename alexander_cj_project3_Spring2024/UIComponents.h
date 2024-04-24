#ifndef MINESWEEPER_UICOMPONENTS_H
#define MINESWEEPER_UICOMPONENTS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Face.h"
#include "Counter.h"
#include "HelperFunctions.h"
#include "GameBoard.h"
#include "Debug.h"
#include "Pause.h"
#include "LeaderBoard.h"
#include "Timer.h"
using namespace std;

class UIComponents {
    float columns, rows;
    int mines;
    HelperFunctions helper;
    Face face;
    Counter counter;
    Debug debug;
    Pause pause;
    Timer timer;
    int updatedTime;
    int endTime;
    LeaderBoard leaderBoard;
    map<string, string> database;
    string name;

public:
    UIComponents(float columns, float rows, int mines, map<string, string> &database);
    void drawUI(sf::RenderWindow &window, GameBoard &board, bool gameLost, bool gameWon);
    void handleClick(sf::RenderWindow &window, GameBoard &board, bool gameLost);
    bool leaderBoardStatus();
};


#endif //MINESWEEPER_UICOMPONENTS_H
