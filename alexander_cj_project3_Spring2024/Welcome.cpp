#include "Welcome.h"

#define DELETE_KEY 8
#define ENTER_KEY 13


Welcome::Welcome(int columns, int rows, map<string, string> &database) {
    this->width = columns*32;
    this->height = (rows*32) + 100;
    this->database = database;
    sf::RenderWindow window(sf::VideoMode(width, height),
                            "Minesweeper", sf::Style::Default);
    string userInput;
    while(window.isOpen()) {
        sf::Event event{};
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                helper.validateUserInput(window, database, userInput, event.text.unicode, success);
            }
        }

        window.clear(sf::Color::Blue);
        writeWelcomeTitle(window);
        writeDirections(window);
        writeUserInput(window, userInput);
        window.display();
    }
}

void Welcome::writeWelcomeTitle(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("files/font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("WELCOME TO MINESWEEPER!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    float positionX = float(width) / 2;
    float positionY = (float(height) / 2) - 150;
    helper.moveTextOrigin(text, positionX, positionY);
    window.draw(text);
}

void Welcome::writeDirections(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("files/font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("Enter your name:");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    float positionX = float(width) / 2;
    float positionY = (float(height) / 2) - 75;
    helper.moveTextOrigin(text, positionX, positionY);
    window.draw(text);
}

void Welcome::writeUserInput(sf::RenderWindow &window, const string &userInput) {
    sf::Font font;
    font.loadFromFile("files/font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(userInput + "|");
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    float positionX = float(width) / 2;
    float positionY = (float(height) / 2) - 45;
    helper.moveTextOrigin(text, positionX, positionY);
    window.draw(text);
}

bool Welcome::checkSucess() {
    return success;
}
