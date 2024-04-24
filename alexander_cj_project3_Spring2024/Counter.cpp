#include "Counter.h"

Counter::Counter() {
    numbers = helper.getNumbers();
}

void Counter::drawCounter(int mines, float rows, sf::RenderWindow &window) {
    bool negative = false;
    if (mines < 0) {
        mines *= -1;
        negative = true;
    }
    string stringMines = helper.formatCounter(mines);
    float x = 33;
    float y = 32 * (rows + 0.5) + 16;
    if (negative) {
        countMines.setTexture(numbers[10]);
        x = 12;
        countMines.setPosition(x,y);
        window.draw((countMines));
        x += 21;
    }
    for (int i = 0; i < stringMines.length(); ++i) {
        countMines.setTexture(numbers[stringMines[i] - '0']);
        countMines.setPosition(x, y);
        window.draw(countMines);
        x += 21;
    }
}
