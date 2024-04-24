#include "Face.h"

Face::Face() {
    faceTexture.loadFromFile("files/images/face_happy.png");
}

void Face::drawFace(float columns, float rows, sf::RenderWindow &window) {
    faceButton.setTexture(faceTexture);
    float x = ((columns / 2) * 32) - 32;
    float y = 32 * (rows + 0.5);
    faceButton.setPosition(x, y);
    window.draw(faceButton);
}

void Face::gameLose(sf::RenderWindow &window) {
    faceTexture.loadFromFile("files/images/face_lose.png");
}

void Face::gameWin(sf::RenderWindow &window) {
    faceTexture.loadFromFile(("files/images/face_win.png"));
}

bool Face::resetGame(sf::RenderWindow &window, GameBoard &board, Pause &pauseButton, Timer &timer) {
    if (helper.checkClick(faceButton, window)) {
        faceTexture.loadFromFile("files/images/face_happy.png");
        board.resetBoard();
        pauseButton.playFromReset();
        timer.resetTimer();
        return true;
    }

    else return false;
}


