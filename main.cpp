#include <iostream>
#include "header/chessboard.h"
#include "header/chessvictory.h"
#include "header/chesswelcome.h"
#include "header/Color.h"
#include "header/King.h"
#include "header/Knight.h"
#include "header/Pawn.h"
#include "header/Piece.h"
#include "header/Player.h"
#include "header/SpecialPiece.h"
#include "header/squares.h"

using namespace std;

int main() {
    int choices;
    do {
        printWelcomeScreen();

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