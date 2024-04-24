#ifndef MINESWEEPER_HELPERFUNCTIONS_H
#define MINESWEEPER_HELPERFUNCTIONS_H
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <random>

using namespace std;


class HelperFunctions {
public:
    HelperFunctions() = default;
    map<string, int> readConfigFile(const string &file);
    map<string, string> readLeaderBoardFile(const string &file);
    void moveTextOrigin(sf::Text &text, float x, float y);
    void validateUserInput(sf::RenderWindow &window, map<string, string> &database, string &userInput,
                           unsigned int character, bool &success);
    void deleteLastCharacter(string &userInput);
    void submitToDatabase(sf::RenderWindow &window, map<string, string> &database, const string &input, bool &success);
    bool checkClick(sf::Sprite &sprite, sf::RenderWindow &window);
    int randomTile(int columns, int rows);
    map<int, sf::Texture> getNumbers();
    string formatCounter(int mines);
    string formatTimer(int minutes, int seconds);
    string formatLeaderBoardString(vector<string> &names, vector<string> &times);
};


#endif //MINESWEEPER_HELPERFUNCTIONS_H
