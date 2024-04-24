#include "Pause.h"

Pause::Pause() {
    pauseTexture.loadFromFile("files/images/pause.png");
}

void Pause::drawButton(float columns, float rows, sf::RenderWindow &window) {
    pauseButton.setTexture(pauseTexture);
    float x = (columns * 32) - 240;
    float y = 32 * (rows + 0.5);
    pauseButton.setPosition(x, y);
    window.draw(pauseButton);
}

void Pause::pauseGame(sf::RenderWindow &window, GameBoard &board, Timer &timer) {
    if (helper.checkClick(pauseButton, window)) {
        paused = !paused;
        if (paused) {
            pauseTexture.loadFromFile("files/images/play.png");
            timer.pauseTimer();
        }
        else {
            pauseTexture.loadFromFile("files/images/pause.png");
            timer.startTimer();
        }
        board.toggleGamePaused();
    }
}

void Pause::playFromReset() {
    paused = false;
    pauseTexture.loadFromFile("files/images/pause.png");
}

bool Pause::returnPausedStatus() {
    return paused;
}
