#ifndef MINESWEEPER_TILE_H
#define MINESWEEPER_TILE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HelperFunctions.h"
using namespace std;


class Tile {
    bool hidden = true;
    bool hasMine = false;
    bool hasFlag = false;
    vector<Tile*> adjacentTiles;
    vector<sf::Texture> numberTextures;
    map<int, sf::Sprite> numbers;
    int numberShown = 0;
    sf::Texture tileTexture;
    sf::Texture flagTexture;
    sf::Texture mineTexture;
    sf::Texture revealedTileTexture;
    sf::Sprite revealedTile;
    sf::Sprite mine;
    sf::Sprite tile;
    sf::Sprite flag;
    HelperFunctions helper;
public:
    Tile();
    void drawTile(sf::RenderWindow &window);
    bool showTile(sf::RenderWindow &window);
    void drawRevealedTile(sf::RenderWindow &window);
    void drawFlag(sf::RenderWindow &window);
    void setFlag(sf::RenderWindow &window);
    bool checkFlag();
    void moveTile(float x, float y);
    bool checkMine();
    void placeMine();
    void drawMine(sf::RenderWindow &window);
    void addAdjacentTile(Tile* &tilePassed);
    bool hiddenOrNot();
    void openEmptyTiles(sf::RenderWindow &window);
    int getNumberShown();
    void resetTile();
};


#endif //MINESWEEPER_TILE_H
