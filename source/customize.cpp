#include <iostream>
#include "../header/customize.h"
#include "../header/Player.h"
using namespace std;

Color customizeScreen(string colorChoice) {
    if (colorChoice == "black") {
        return black;
    }
    else if (colorChoice == "red") {
        return red;
    }
    else if (colorChoice == "green") {
         return green;
    }
    else if (colorChoice == "yellow") {
         return yellow;
    }
    else if (colorChoice == "blue") {
         return blue;
    }
    else if (colorChoice == "magenta") {
         return magenta;
    }
    else if (colorChoice == "cyan") {
         return cyan;
    }
    else if (colorChoice == "white") {
        return white;
    }
    return white;
}