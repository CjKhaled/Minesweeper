#include "Tile.h"

Tile::Tile() {
    tileTexture.loadFromFile("files/images/tile_hidden.png");
    revealedTileTexture.loadFromFile("files/images/tile_revealed.png");
    flagTexture.loadFromFile("files/images/flag.png");
    mineTexture.loadFromFile("files/images/mine.png");

    for (int i = 1; i < 9; ++i) {
        sf::Texture newNumber;
        string filePath = (string)"files/images/number_" + to_string(i) + ".png";
        newNumber.loadFromFile(filePath);
        numberTextures.push_back(newNumber);
    }
}

void Tile::drawTile(sf::RenderWindow &window) {
    if (hidden) {
        tile.setTexture(tileTexture);
        window.draw(tile);
    }

    else {
        window.draw(revealedTile);
        if (!hasMine) {
            window.draw(numbers[numberShown]);
        }
        else {
            drawMine(window);
        }
    }
}

void Tile::drawRevealedTile(sf::RenderWindow &window) {
    revealedTile.setTexture(revealedTileTexture);
    window.draw(revealedTile);
}

bool Tile::showTile(sf::RenderWindow &window) {
    if (helper.checkClick(tile, window)) {
        openEmptyTiles(window);
        for (int i = 1; i < 9; ++i) {
            sf::Sprite number;
            number.setTexture(numberTextures[i - 1]);
            numbers[i] = number;
        }
        return true;
    }

    else return false;
}

void Tile::drawFlag(sf::RenderWindow &window) {
    flag.setTexture(flagTexture);
    window.draw(flag);
}

void Tile::setFlag(sf::RenderWindow &window) {
    if (helper.checkClick(tile, window)) {
        hasFlag = !hasFlag;
    }
}

bool Tile::checkFlag() {
    return hasFlag;
}

void Tile::moveTile(float x, float y) {
    tile.setPosition(x, y);
    flag.setPosition(x, y);
    mine.setPosition(x, y);
    revealedTile.setPosition(x, y);
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        iter->second.setPosition(x, y);
    }
}

bool Tile::checkMine() {
    return hasMine;
}

void Tile::placeMine() {
    hasMine = true;
}

void Tile::drawMine(sf::RenderWindow &window) {
    mine.setTexture(mineTexture);
    window.draw(mine);
}

void Tile::addAdjacentTile(Tile *&tilePassed) {
    if (tilePassed != nullptr) {
        adjacentTiles.push_back(tilePassed);
        if (tilePassed->checkMine()) numberShown++;
    }
}

bool Tile::hiddenOrNot() {
    return hidden;
}

void Tile::openEmptyTiles(sf::RenderWindow &window) {
    revealedTile.setTexture(revealedTileTexture);
    hidden = false;
    if (numberShown == 0) {
        for (auto &adjTile : adjacentTiles) {
            if (adjTile->hiddenOrNot() && adjTile->getNumberShown() == 0 && !adjTile->hasMine && !adjTile->checkFlag()) {
                adjTile->openEmptyTiles(window);
            }
        }
    }
}

int Tile::getNumberShown() {
    return numberShown;
}




