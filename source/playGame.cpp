#include <iostream>
#include <vector>
#include "../header/playGame.h"
#include "../header/displaychessboard.h"
#include "../header/Piece.h"
#include "../header/chessvictory.h"

using namespace std;

void playGame(Player player1, Player player2, Chessboard *&board, ChessboardDisplay *showChess) {
    vector<Player> playerList;
    playerList.push_back(player1);
    playerList.push_back(player2);
    int i = 0;
    cout << playerList.at(i).returnName() << " goes first" << endl << endl;
    bool gameState = false;
    Piece *currentPiece = nullptr;
    Squares *newMovePosition = nullptr;
    Squares *currentSquare = nullptr;
    SpecialPiece *specialPiece = nullptr;
    string pieceType;
    while (!gameState) {
        cout << "It is currently " << playerList.at(i).returnName() << "'s turn to move" << endl;
        cout << "**********************************************************************" << endl << endl;
        cout << "Choose the row and the column of the piece you want to move" << endl;
        cout << "Row: " << endl;
        int startRow;
        cin >> startRow;
        cout << "Column: " << endl;
        int startColumn;
        cin >> startColumn;
        //if statement makes sure that the rows and columns are valid
        if(startRow < 0 || startRow > 7 || startColumn < 0 || startColumn > 7) {
            makeBetween0And7(startRow, startColumn);
        }
        currentSquare = board->getSquare(startRow, startColumn);
        //if statmenet makes sure that u pick a square with a piece on it
        if (!currentSquare->isOccupied()) {
            makeSelectOccupied(board, currentSquare, startRow, startColumn);
        }
        cout << endl;
        //if statement makes sure that u pick a square with your colored piece on it
        if (currentSquare->getPiece()->getColor() != playerList.at(i).returnColorChoice()) {
            chooseSameColor(board, currentSquare, playerList.at(i), startRow, startColumn);
        }
        cout << "Choose the row and the column of where you want to move" << endl;
        cout << "Row: " << endl;
        int endRow;
        cin >> endRow;
        cout << "Column: " << endl;
        int endColumn;
        cin >> endColumn;
        cout << endl;
        //make sure that the start and end squares are the same 
        if ((endRow - startRow == 0) && (endColumn - startColumn == 0)) {
            makeDiffStartAndEnd(endRow, startRow, endColumn, startColumn); 
        }
        if (!currentSquare->getPiece()->moveValid(endRow, endColumn, board)) {
            makeValidMove(playerList.at(i), currentSquare, endRow, endColumn, startRow, startColumn, board);
        }

        outputPieceMoved(currentSquare, pieceType, endRow, endColumn); //outputs what piece moved where
        //moving the pieces

        currentPiece = currentSquare->pickUpPiece();
        newMovePosition = board->getSquare(endRow, endColumn);
        if (!currentPiece->attackingAlly(endRow, endColumn, board)) {
            newMovePosition->removePiece();
        }
        newMovePosition->setPiece(currentPiece);
        if (currentPiece->getType() == Pn || currentPiece->getType() == Kg || currentPiece->getType() == Rk){
            specialPiece = dynamic_cast<SpecialPiece*>(currentPiece);
            specialPiece->setMoved();
            specialPiece = nullptr;
        }
        showChess->displayBoard(board);
        gameState = isKingCaptured(board, playerList);
        currentPiece = nullptr;
        newMovePosition = nullptr;
        currentSquare = nullptr;
        if (i == 0) {
            i++;
        }
        else {
            i--;
        }
    }
}


/* ------------------- helper functions ------------------------------ */
void makeBetween0And7(int &startRow, int &startColumn) {
    while (startRow < 0 || startRow > 7 || startColumn < 0 || startColumn > 7) {
        cout << "please choose valid row and column" << endl;
        cout << "Choose the row and the column of the piece you want to move" << endl;
        cout << "Row: " << endl;
        cin >> startRow;
        cout << "Column: " << endl;
        cin >> startColumn;
    }
}

void makeSelectOccupied(Chessboard *board, Squares *&currentSquare, int &startRow, int &startColumn) {
    while (!currentSquare->isOccupied()) {
        cout << "BRO CHOOSE A SQUARE WHERE THERES A PIECE ON IT U APE" << endl << endl;
        cout << "Choose the row and the column of the piece you want to move" << endl;
        cout << "Row: " << endl;
        cin >> startRow;
        cout << "Column: " << endl;
        cin >> startColumn;
        makeBetween0And7(startRow, startColumn);
        currentSquare = board->getSquare(startRow, startColumn);    
    }
}

void chooseSameColor(Chessboard *board, Squares *&currentSquare, Player player, int &startRow, int &startColumn) {
    while (currentSquare->getPiece()->getColor() != player.returnColorChoice()) {
        cout << "please select your own color piece to move" << endl << endl;
        cout << "Choose the row and the column of the piece you want to move" << endl;
        cout << "Row: " << endl;
        int startRow;
        cin >> startRow;
        cout << "Column: " << endl;
        int startColumn;
        cin >> startColumn;
        currentSquare = board->getSquare(startRow, startColumn);
        if (!currentSquare->isOccupied()) {
            makeSelectOccupied(board, currentSquare, startRow, startColumn);            
        } 
    }
}

void makeDiffStartAndEnd(int &endRow, int startRow, int &endColumn, int startColumn) {
    while ((endRow - startRow == 0) && (endColumn - startColumn == 0)) {
        cout << "Invalid input: Choose the row and the column of where you want to move" << endl;
        cout << "Row: " << endl;
        cin >> endRow;
        cout << "Column: " << endl;
        cin >> endColumn;
    }
}

void makeValidMove(Player player, Squares *&currentSquare, int &endRow, int &endColumn, int &startRow, int &startColumn, Chessboard *board) {
    while (!currentSquare->getPiece()->moveValid(endRow, endColumn, board)) {
        cout << "Invalid move: That piece can not move there, pick a different start piece" << endl;
        cout << "Choose the row and the column of the piece you want to move" << endl;
        cout << "Row: " << endl;
        cin >> startRow;
        cout << "Column: " << endl;
        cin >> startColumn;
        //if statement makes sure that the rows and columns are valid
        if(startRow < 0 || startRow > 7 || startColumn < 0 || startColumn > 7) {
            makeBetween0And7(startRow, startColumn);
        }
        currentSquare = board->getSquare(startRow, startColumn);
        //if statmenet makes sure that u pick a square with a piece on it
        if (!currentSquare->isOccupied()) {
            makeSelectOccupied(board, currentSquare, startRow, startColumn);
        }
        cout << endl;
        //if statement makes sure that u pick a square with your colored piece on it
        if (currentSquare->getPiece()->getColor() != player.returnColorChoice()) {
            chooseSameColor(board, currentSquare, player, startRow, startColumn);
        }
        cout << "Choose the row and the column of where you want to move" << endl << endl;
        cout << "Row: " << endl;
        cin >> endRow;
        cout << "Column: " << endl;
        cin >> endColumn;
        cout << endl;
        if ((endRow - startRow == 0) && (endColumn - startColumn == 0)) {
            makeDiffStartAndEnd(endRow, startRow, endColumn, startColumn);
        }
        cout << startRow << startColumn << endRow << endColumn << endl; 
    }
}

void outputPieceMoved(Squares *currentSquare, string pieceType, int endRow, int endColumn) {
    if (currentSquare->getPiece()->getType() == Type::Pn) {
    pieceType = "Pn";
    cout << "You chose to move " << pieceType << " to row " << endRow << " column " << endColumn << "." << endl;
    }
    else if (currentSquare->getPiece()->getType() == Type::Bp) {
        pieceType = "Bp";
        cout << "You chose to move " << pieceType << " to row " << endRow << " column " << endColumn << "." << endl;
    }
    else if (currentSquare->getPiece()->getType() == Type::Kn) {
        pieceType = "Kn";
        cout << "You chose to move " << pieceType << " to row " << endRow << " column " << endColumn << "." << endl;
    }
    else if (currentSquare->getPiece()->getType() == Type::Rk) {
        pieceType = "Rk";
        cout << "You chose to move " << pieceType << " to row " << endRow << " column " << endColumn << "." << endl;
    }
    else if (currentSquare->getPiece()->getType() == Type::Qn) {
        pieceType = "Qn";
        cout << "You chose to move " << pieceType << " to row " << endRow << " column " << endColumn << "." << endl;
    }
    else if (currentSquare->getPiece()->getType() == Type::Kg) {
        pieceType = "Kg";
        cout << "You chose to move " << pieceType << " to row " << endRow << " column " << endColumn << "." << endl;
    }
}

bool isKingCaptured(Chessboard *board, vector<Player> playerList) {
    int kingCount = 0;
    Color kingColor;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board->getSquare(i, j)->isOccupied() && board->getSquare(i, j)->getPiece()->getType() == Type::Kg) {
                kingColor = board->getSquare(i, j)->getPiece()->getColor();
                kingCount++;
            }
        }
    }
    if (kingCount == 2) {
        return false;
    }
    if (kingCount == 1 && kingColor == playerList.at(0).returnColorChoice()) {
        displayVictoryScreen(playerList.at(0).returnName());
        cout << endl;
    }
    else if (kingCount == 1 && kingColor == playerList.at(1).returnColorChoice()) {
        displayVictoryScreen(playerList.at(1).returnName());
        cout << endl;
    }
    return true;
}   