#include <iostream>
#include "../header/chessvictory.h"
using namespace std;

void displayVictoryScreen() {
    cout << "*************************************\n";
    cout << "*        Congratulations!           *\n";
    cout << "*        You've Won the Game!       *\n";
    cout << "*************************************\n";
}

void displayVictoryScreen(Player player) {
    cout << "*************************************" << endl;
    cout << "        Congratulations " << player.returnName() << "!         " << endl;
    cout << "*        You've Won the Game!       *" << endl;
    cout << "*************************************" << endl;
}