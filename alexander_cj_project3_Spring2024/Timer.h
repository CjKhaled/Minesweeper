#ifndef MINESWEEPER_TIMER_H
#define MINESWEEPER_TIMER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include "HelperFunctions.h"
#include "GameBoard.h"
using namespace chrono;

class Timer {
    map<int, sf::Texture> numbers;
    HelperFunctions helper;
    sf::Sprite minutesImage;
    sf::Sprite secondsImage;
    int min = 0;
    int sec = 0;
    string currentTime;
    bool timerRunning = false;
    chrono::time_point<high_resolution_clock> startTime = chrono::high_resolution_clock::now();
    chrono::time_point<high_resolution_clock> pausedTime = chrono::high_resolution_clock::now();
    long long elapsedPausedTime = chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock ::now() - pausedTime).count();
    int totalTime = 0;
public:
    Timer();
    void drawTimer(float columns, float rows, sf::RenderWindow &window);
    void startTimer();
    void pauseTimer();
    void resetTimer();
    bool getTimerStatus();
    string getTime();

};


#endif //MINESWEEPER_TIMER_H
