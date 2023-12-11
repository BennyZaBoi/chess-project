#include <iostream>
#include "../header/playGame.h"
#include "../header/displaychessboard.h"
#include "../header/Piece.h"

using namespace std;

void playGame(Player player1, Player player2, Chessboard *board) {
    cout << player1.returnName() << " goes first" << endl << endl;
    cout << "Choose the row and the column you want to move" << endl;
    cout << "Row: " << endl;
    int _row;
    cin >> _row;
    cout << "Column: " << endl;
    int _column;
    cin >> _column;

    Squares *currentmove = board->getSquare(_row, _column);
    string pieceType;
    if (currentmove->getPiece()->getType() == Type::Pn) {
        pieceType = "Pn";
    }
    else if (currentmove->getPiece()->getType() == Type::Bp) {
        pieceType = "Bp";
    }
    else if (currentmove->getPiece()->getType() == Type::Kn) {
        pieceType = "Kn";
    }
    else if (currentmove->getPiece()->getType() == Type::Rk) {
        pieceType = "Rk";
    }
    else if (currentmove->getPiece()->getType() == Type::Qn) {
        pieceType = "Qn";
    }
    else if (currentmove->getPiece()->getType() == Type::Kg) {
        pieceType = "Kg";
    }
    cout << "You chose to move " << pieceType << " to row " << _row << " column " << _column << "." << endl;



}