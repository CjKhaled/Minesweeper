#ifndef MINESWEEPER_PAUSE_H
#define MINESWEEPER_PAUSE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HelperFunctions.h"
#include "GameBoard.h"
#include "Timer.h"
using namespace std;

class Pause {
    HelperFunctions helper;
    sf::Texture pauseTexture;
    sf::Sprite pauseButton;
    bool paused = false;
public:
    Pause();
    void drawButton(float columns, float rows, sf::RenderWindow &window);
    void pauseGame(sf::RenderWindow &window, GameBoard &board, Timer &timer);
    void playFromReset();
    bool returnPausedStatus();

};


#endif //MINESWEEPER_PAUSE_H
