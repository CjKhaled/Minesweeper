#ifndef MINESWEEPER_DEBUG_H
#define MINESWEEPER_DEBUG_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "HelperFunctions.h"
using namespace std;

class Debug {
    sf::Texture debugTexture;
    sf::Sprite debug;
    HelperFunctions helper;
public:
    Debug();
    void drawDebug(float columns, float rows, sf::RenderWindow &window);
    void toggleMines(sf::RenderWindow &window, GameBoard &board);
};


#endif //MINESWEEPER_DEBUG_H
