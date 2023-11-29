#include <iostream>
#include "../header/chesswelcome.h"
using namespace std;

void ChessWelcome::printWelcomeScreen() {
    cout << "*************************************" << endl;
    cout << "*      Welcome to UCR Chess!       *" << endl;
    cout << "*************************************" << endl;
    cout << "*          1. Start Game            *" << endl;
    cout << "*          2. Instructions          *" << endl;
    cout << "*          3. Exit                  *" << endl;
    cout << "*************************************" << endl << endl;

}

int main() {
    int choices;
    do {
        ChessWelcome::printWelcomeScreen();

        cout << "Please enter your choice!" << endl;
        cin >> choices;

        if (choices == 1) {
            cout << "You choose to start the game!" << endl;
        }
        else if (choices == 2) {
            cout << "You pick the instructions!" << endl;
        }
        else if (choices == 3 ) {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid Choice choose again..." << endl;
        }
    } while (choices < 1 || choices > 3);

    return 0;
}