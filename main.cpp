#include <iostream>
#include "header/chessboard.h"
#include "header/chessvictory.h"
#include "header/chesswelcome.h"
#include "header/chessInstructions.h"
#include "header/customize.h"
#include "header/displaychessboard.h"
#include "header/playGame.h"
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
            string p1Name;
            string p1Color;

            cout << "Enter Player 1 name:" << endl;
            cin >> p1Name;
            p1.setName(p1Name);
            cout << "Enter Player 1 color:" << endl;
            cout << "You can choose from: \033[30m black, \033[31m red, \033[32m green, \033[33m yellow, \033[34m blue, \033[35m magenta, \033[36m cyan, \033[37m white" << endl;
            cin >> p1Color;
            p1.setColorChoice(customizeScreen(p1Color));

            Player p2;
            string p2Name;
            string p2Color;
            
            cout << "Enter Player 2 name:" << endl;
            cin >> p2Name;
            p2.setName(p2Name);
            cout << "Enter Player 2 color:" << endl;
            cout << "You can choose from: \033[30m black, \033[31m red, \033[32m green, \033[33m yellow, \033[34m blue, \033[35m magenta, \033[36m cyan, \033[37m white" << endl;
            cin >> p2Color;
            p2.setColorChoice(customizeScreen(p2Color));
            p2.setFirstMove(false);

            Chessboard* newBoard = new Chessboard();
            newBoard->initializeChessboard(p1.returnColorChoice(), p2.returnColorChoice()); 
            ChessboardDisplay* showChess = new ChessboardDisplay();
            showChess->displayBoard(newBoard);
            playGame(p1, p2, newBoard);
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