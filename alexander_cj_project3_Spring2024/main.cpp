#include <iostream>
#include <SFML/Graphics.hpp>
#include "Welcome.h"
#include "HelperFunctions.h"
#include "Game.h"
#include <map>


int main() {
    HelperFunctions helper;
    map<string, int> config = helper.readConfigFile("files/config.cfg");
    map<string, string> database;
    Welcome welcomeWindow(config["columns"], config["rows"], database);
    if (welcomeWindow.checkSucess()) Game gameWindow(config["columns"],
                                                     config["rows"], config["mines"], database);

//    Game gameWindow(config["columns"],
//                    config["rows"], config["mines"], database);
    return 0;
}