#include "Debug.h"

Debug::Debug() {
    debugTexture.loadFromFile("files/images/debug.png");
}


void Debug::drawDebug(float columns, float rows, sf::RenderWindow &window) {
    debug.setTexture(debugTexture);
    float x = (columns * 32) - 304;
    float y = 32 * (rows + 0.5);
    debug.setPosition(x, y);
    window.draw(debug);
}

void Debug::toggleMines(sf::RenderWindow &window, GameBoard &board) {
    if (helper.checkClick(debug, window)) {
        board.toggleMinesShown();
    }
}
