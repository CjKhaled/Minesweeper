#include "Game.h"

Game::Game(int columns, int rows, int mines, map<string, string> &database) {
    this->width = columns*32;
    this->height = (rows*32) + 100;
    this->database = database;
    sf::RenderWindow window(sf::VideoMode(width, height),
                            "Minesweeper", sf::Style::Default);
    GameBoard board(columns, rows, mines, gameWon, gameLost);
    board.createBoard();
    UIComponents UI(columns, rows, mines, database);


    while(window.isOpen()) {
        sf::Event event{};
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (!board.returnGameLoss() || !UI.leaderBoardStatus() || !board.returnGameWon()) {
                        board.handleLeftClick(window);
                    }
                    UI.handleClick(window, board, board.returnGameLoss());
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    board.handleRightClick(window);
                }
            }
        }
        window.clear(sf::Color::White);
        board.drawBoard(window);
        UI.drawUI(window, board, board.returnGameLoss(), board.returnGameWon());
        window.display();
    }
}
