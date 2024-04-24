#ifndef MINESWEEPER_LEADERBOARD_H
#define MINESWEEPER_LEADERBOARD_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HelperFunctions.h"
#include "GameBoard.h"
#include "Pause.h"
using namespace std;

class LeaderBoard {
    HelperFunctions helper;
    sf::Texture leaderTexture;
    sf::Sprite leaderButton;
    map<string, string> playerData;
    vector<string> names;
    vector<string> times;
    bool leaderBoardOpen = false;
public:
    LeaderBoard();
    void drawLeaderBoardButton(float columns, float rows, sf::RenderWindow &window);
    void handleClick(sf::RenderWindow &window, float columns, float rows, GameBoard &board);
    void drawLeaderBoard(float columns, float rows, GameBoard &board);
    void writeLeaderTitle(sf::RenderWindow &window, int width, int height);
    void writeLeaderContent(sf::RenderWindow &window, int width, int height);
    bool checkLeaderBoardState();
    void addToLeaderBoard(const string &name, const string &time);
    int getTotalTime(const string &time);
};


#endif //MINESWEEPER_LEADERBOARD_H
