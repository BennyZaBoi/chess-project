#include <iostream>
#include "../header/playGame.h"
#include "../header/displaychessboard.h"
#include "../header/Piece.h"

using namespace std;

void playGame(Player player1, Player player2, Chessboard *&board) {
    cout << player1.returnName() << " goes first" << endl << endl;
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
    Squares *currentSquare = board->getSquare(startRow, startColumn);
    //if statmenet makes sure that u pick a square with a piece on it
    if (!currentSquare->isOccupied()) {
        makeSelectOccupied(board, currentSquare, startRow, startColumn);
    }
    cout << endl;
    //if statement makes sure that u pick a square with your colored piece on it
    if (currentSquare->getPiece()->getColor() != player1.returnColorChoice()) {
        chooseSameColor(board, currentSquare, player1, startRow, startColumn);
    }
    cout << "Choose the row and the column of where you want to move" << endl;
    cout << "Row: " << endl;
    int endRow;
    cin >> endRow;
    cout << "Column: " << endl;
    int endColumn;
    cin >> endColumn;
    cout << endl;
    if ((endRow - startRow == 0) && (endColumn - startColumn == 0)) {
        makeDiffStartAndEnd(endRow, startRow, endColumn, startColumn);
    }

    string pieceType;
    if (currentSquare->getPiece()->getType() == Type::Pn) {
        pieceType = "Pn";
        cout << "You chose to move " << pieceType << " to row " << endRow << " column " << endColumn << "." << endl;
        int movesUp = endRow - startRow;
        Pawn pawnPiece = currentSquare->getPiece()->getType();
        if (pawnPiece.moveValid(endRow, endColumn, board)) {
            Piece *currentPiece = currentSquare->pickUpPiece();
            Squares *newMovePosition = board->getSquare(endRow, endColumn);
            newMovePosition->setPiece(currentPiece);
        }

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
        if (!currentSquare->isOccupied()) {
            makeSelectOccupied(board, currentSquare, startRow, startColumn);            
        }
        currentSquare = board->getSquare(startRow, startColumn);        
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