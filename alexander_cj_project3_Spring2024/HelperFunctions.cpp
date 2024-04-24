#include "HelperFunctions.h"

map<string, int> HelperFunctions::readConfigFile(string const &file) {
    map<string, int> data;
    ifstream inputFile(file);
    string columns;
    string rows;
    string mines;
    getline(inputFile, columns);
    getline(inputFile, rows);
    getline(inputFile, mines);
    data["columns"] = stoi(columns);
    data["rows"] = stoi(rows);
    data["mines"] = stoi(mines);
    return data;
}

map<string, string> HelperFunctions::readLeaderBoardFile(const string &file) {
    map<string, string> data;
    ifstream inputFile(file);
    string line;
    int count = 0;

    while (getline(inputFile, line) && count < 5) {
        int commaPosition = line.find(',');
        string time = line.substr(0, commaPosition);
        string name = line.substr(commaPosition + 2);
        data[name] = time;
        count++;
    }

    return data;
}

void HelperFunctions::moveTextOrigin(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void HelperFunctions::validateUserInput(sf::RenderWindow &window, map<string, string> &database,
                                        string &userInput, unsigned int character, bool &success) {
    if (character >= 97 && character <= 122 && userInput.length() < 10) {
        if (userInput.empty()) {
            character = toupper((int)character);
        }
        userInput += (char)character;
    }

    if (character == 8) {
        deleteLastCharacter(userInput);
    }

    if (character == 13 && !userInput.empty()) {
        submitToDatabase(window, database, userInput, success);
    }
}

void HelperFunctions::deleteLastCharacter(string &userInput) {
    if (!userInput.empty()) {
        string newInput;
        for (int i = 0; i < userInput.length() - 1; i++) {
            newInput += userInput[i];
        }
        userInput = newInput;
    }
}

void HelperFunctions::submitToDatabase(sf::RenderWindow &window, map<string, string> &database,
                                       const string &input, bool &success) {
    database[input] = "0";
    success = true;
    window.close();
}

bool HelperFunctions::checkClick(sf::Sprite &sprite, sf::RenderWindow &window) {
    float mouseX = (float)sf::Mouse::getPosition(window).x;
    float mouseY = (float)sf::Mouse::getPosition(window).y;
    if (sprite.getGlobalBounds().contains(mouseX, mouseY)) {
        return true;
    }
    return false;
}

int HelperFunctions::randomTile(int columns, int rows) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, columns * rows);
    return dis(gen);
}

map<int, sf::Texture> HelperFunctions::getNumbers() {
    map<int, sf::Texture> numbers;
    for (int i = 0; i < 11; ++i) {
        int left = 21 * i;
        sf::Texture newDigit;
        numbers[i] = newDigit;
        numbers[i].loadFromFile("files/images/digits.png",
                                sf::IntRect(left,0,21, 32));
    }
    return numbers;
}

string HelperFunctions::formatCounter(int mines) {
    string stringMines = to_string(mines);
    if (mines < 0) mines *= -1;
    if (mines > 10) stringMines = "0" + to_string(mines);
    if (mines < 10) stringMines = "00" + to_string(mines);
    if (mines == 0) stringMines = "000";
    return stringMines;
}

string HelperFunctions::formatTimer(int minutes, int seconds) {
    string timer;
    string min = to_string(minutes);
    string sec = to_string(seconds);
    if (minutes < 10) min = "0" + to_string(minutes);
    if (seconds < 10) sec = "0" + to_string(seconds);
    timer = min + sec;
    return timer;
}

string HelperFunctions::formatLeaderBoardString(vector<string> &names, vector<string> &times) {
    string leaderBoardString = "";
    int count = 0;
    for (int i = 0; i < names.size(); i++) {
        count++;
        leaderBoardString += to_string(count) + "\t" + times[i] + "\t" + names[i] + "\n\n";
    }

    return leaderBoardString;
}


