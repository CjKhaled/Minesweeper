#ifndef MINESWEEPER_FACE_H
#define MINESWEEPER_FACE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HelperFunctions.h"
#include "GameBoard.h"
#include "Pause.h"
using namespace std;

class Face {
    HelperFunctions helper;
    sf::Texture faceTexture;
    sf::Sprite faceButton;
public:
    Face();
    void drawFace(float columns, float rows, sf::RenderWindow &window);
    void gameLose(sf::RenderWindow &window);
    void gameWin(sf::RenderWindow &window);
    bool resetGame(sf::RenderWindow &window, GameBoard &board, Pause &pauseButton, Timer &timer);
};


#endif //MINESWEEPER_FACE_H
