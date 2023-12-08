#include "../header/displaychessboard.h"
#include <iostream> 

using namespace std; 

bool ChessboardDisplay::displayTrue(Chessboard* board){
    if (board->getSquare(0, 0)->getPiece()->getType() == Kn){
        return true; 
    }
    return false; 
}

void ChessboardDisplay::displayBoard(Chessboard* board){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            if(board->getSquare(i, j)->getPiece() == nullptr){
                cout << "|  |"; 
            }
            else if(board->getSquare(i, j)->getPiece()->getType() == Pn){
                cout << "|Pn|";
            }
            else if(board->getSquare(i, j)->getPiece()->getType() == Kn){
                cout << "|Kn|";
            }
            else if(board->getSquare(i, j)->getPiece()->getType() == Kg){
                cout << "|Kg|";
            }
            else if(board->getSquare(i, j)->getPiece()->getType() == Qn){
                cout << "|Qn|";
            }
            else if(board->getSquare(i, j)->getPiece()->getType() == Bp){
                cout << "|Bp|";
            }
            else if(board->getSquare(i, j)->getPiece()->getType() == Rk){
                cout << "|Rk|";
            }
            else {
                cout << "|  |"; 
            }
        }
        cout << endl; 
        for (int k = 0; k < 8; ++k){
            cout << " __ ";
        }
        cout << endl; 
    }
}