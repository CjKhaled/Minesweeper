#ifndef MINESWEEPER_COUNTER_H
#define MINESWEEPER_COUNTER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HelperFunctions.h"
#include "GameBoard.h"
using namespace std;

class Counter {
    map<int, sf::Texture> numbers;
    HelperFunctions helper;
    sf::Sprite countMines;
public:
    Counter();
    void drawCounter(int mines, float rows, sf::RenderWindow &window);
};


#endif //MINESWEEPER_COUNTER_H
