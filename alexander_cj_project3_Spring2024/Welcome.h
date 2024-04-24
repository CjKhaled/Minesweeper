#ifndef MINESWEEPER_WELCOME_H
#define MINESWEEPER_WELCOME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HelperFunctions.h"
using namespace std;


class Welcome {
    HelperFunctions helper;
    int width;
    int height;
    bool success = false;
    map<string, string> database;
public:
    Welcome(int columns, int rows, map<string, string> &database);
    void writeWelcomeTitle(sf::RenderWindow &window);
    void writeDirections(sf::RenderWindow &window);
    void writeUserInput(sf::RenderWindow &window, const string &userInput);
    bool checkSucess();
};


#endif //MINESWEEPER_WELCOME_H
