#include "LeaderBoard.h"

LeaderBoard::LeaderBoard() {
    leaderTexture.loadFromFile("files/images/leaderboard.png");
    playerData = helper.readLeaderBoardFile("files/leaderboard.txt");
    for (auto& pair : playerData) {
        names.push_back(pair.first);
        times.push_back(pair.second);
    }
}

void LeaderBoard::drawLeaderBoardButton(float columns, float rows, sf::RenderWindow &window) {
    leaderButton.setTexture(leaderTexture);
    float x = (columns * 32) - 176;
    float y = 32 * (rows + 0.5);
    leaderButton.setPosition(x, y);
    window.draw(leaderButton);
}

void LeaderBoard::handleClick(sf::RenderWindow &window, float columns, float rows, GameBoard &board) {
    if (helper.checkClick(leaderButton, window)) {
        cout << "hey";
        drawLeaderBoard(columns, rows, board);
    }
}

void LeaderBoard::drawLeaderBoard(float columns, float rows, GameBoard &board) {
    leaderBoardOpen = true;
    int width = (int)columns * 16;
    int height = (int)(rows * 16) + 50;
    sf::RenderWindow window(sf::VideoMode(width, height),
                            "Minesweeper", sf::Style::Default);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                leaderBoardOpen = false;
                board.finishGame();
            }
        }
        window.clear(sf::Color::Blue);
        writeLeaderTitle(window, width, height);
        writeLeaderContent(window, width, height);
        window.display();
    }
}

void LeaderBoard::writeLeaderTitle(sf::RenderWindow &window, int width, int height) {
    sf::Font font;
    font.loadFromFile("files/font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("LEADERBOARD");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    float positionX = float(width) / 2;
    float positionY = (float(height) / 2) - 120;
    helper.moveTextOrigin(text, positionX, positionY);
    window.draw(text);
}

void LeaderBoard::writeLeaderContent(sf::RenderWindow &window, int width, int height) {
    sf::Font font;
    font.loadFromFile("files/font.ttf");
    sf::Text text;
    text.setFont(font);
    string leaderBoardString = helper.formatLeaderBoardString(names, times);
    text.setString(leaderBoardString);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    float positionX = float(width) / 2;
    float positionY = (float(height) / 2) + 20;
    helper.moveTextOrigin(text, positionX, positionY);
    window.draw(text);
}

bool LeaderBoard::checkLeaderBoardState() {
    return leaderBoardOpen;
}

void LeaderBoard::addToLeaderBoard(const string &name, const string &time) {
    int playerTime = getTotalTime(time);
    int minutes = stoi(time.substr(0, 2));
    int seconds = stoi(time.substr(3));
    vector<string> newNames;
    vector<string> newTimes;
    bool replaced = false;
    for (int i = 0; i < names.size(); i++) {
        int opponentTime = getTotalTime(times[i]);
        if (playerTime < opponentTime && !replaced) {
            replaced = true;
            newNames.push_back(name + "*");
            newTimes.push_back(time);
        }

        newNames.push_back(names[i]);
        newTimes.push_back(times[i]);
    }


    names = newNames;
    times = newTimes;
    names.pop_back();
    times.pop_back();
}

int LeaderBoard::getTotalTime(const string &time) {
    int minutes = stoi(time.substr(0, 2));
    int seconds = stoi(time.substr(3));
    int totalTime = (minutes * 60) + seconds;
    return totalTime;
}
