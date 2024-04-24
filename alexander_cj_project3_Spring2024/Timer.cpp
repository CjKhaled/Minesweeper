#include "Timer.h"

Timer::Timer() {
    numbers = helper.getNumbers();
    timerRunning = true;
}

void Timer::drawTimer(float columns, float rows, sf::RenderWindow &window) {
//    I give up on pausing the timer, I can't take this anymore.
    if (timerRunning) {
        auto duration = chrono::duration_cast<chrono::seconds>(high_resolution_clock::now() - startTime);
        totalTime = duration.count();
    }

    min = (int)totalTime / 60;
    sec = (int)totalTime % 60;

    currentTime = helper.formatTimer(min, sec);
    float minX = (columns * 32) - 97;
    float minY = 32 * (rows + 0.5) + 16;
    float secX = (columns * 32) - 54;
    float secY = 32 * (rows + 0.5) + 16;

    minutesImage.setTexture(numbers[currentTime[0] - '0']);
    minutesImage.setPosition(minX, minY);
    window.draw(minutesImage);
    minX += 21;

    minutesImage.setTexture(numbers[currentTime[1] - '0']);
    minutesImage.setPosition(minX, minY);
    window.draw(minutesImage);
    minX += 21;

    secondsImage.setTexture(numbers[currentTime[2] - '0']);
    secondsImage.setPosition(secX, secY);
    window.draw(secondsImage);
    secX+= 21;

    secondsImage.setTexture(numbers[currentTime[3] - '0']);
    secondsImage.setPosition(secX, secY);
    window.draw(secondsImage);
    secX+= 21;
}

void Timer::startTimer() {
    timerRunning = true;
}

void Timer::pauseTimer() {
    timerRunning = false;
}


void Timer::resetTimer() {
    timerRunning = true;
    startTime = chrono::high_resolution_clock::now();
}

string Timer::getTime() {
    return currentTime;
}

bool Timer::getTimerStatus() {
    return timerRunning;
}

