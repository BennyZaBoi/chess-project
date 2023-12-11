#include <iostream>
#include "header/chessboard.h"
#include "header/chessvictory.h"
#include "header/chesswelcome.h"
#include "header/chessInstructions.h"
#include "header/customize.h"
#include "header/displaychessboard.h"
#include "header/Color.h"
#include "header/King.h"
#include "header/Knight.h"
#include "header/Pawn.h"
#include "header/Queen.h"
#include "header/Rook.h"
#include "header/Bishop.h"
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
            Player p1;
            Player p2;
            customizeScreen(p1, p2);
            Chessboard* newBoard = new Chessboard();
            newBoard->initializeChessboard(p1.returnColorChoice(), p2.returnColorChoice()); 
            ChessboardDisplay* showChess = new ChessboardDisplay();
            showChess->displayBoard(newBoard);
        }
        else if (choices == 2) {
            printInstructions();
            cin >> choices;
            while (choices != 1) {
                cout << "Press 1 to return to the welcome menu." << endl;
                cin.clear();
                cin.ignore();
                cin >> choices;
            }
            choices = 0;
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