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
    string whiteColor = "\033[37m"; 
    Color piececolor = white;
    string colorChange = "\033[37m";

    cout << "  0   1   2   3   4   5   6   7  " << endl;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){

            if(board->getSquare(i, j)->getPiece() == nullptr){
                cout << "|  |"; 
            }
            else {
                piececolor = board->getSquare(i, j)->getPiece()->getColor(); 
                if (piececolor == black){
                    colorChange = "\033[30m";
                } 
                else if (piececolor == red){
                    colorChange = "\033[31m";
                }
                else if (piececolor == green){
                    colorChange = "\033[32m";
                }
                else if (piececolor == yellow){
                    colorChange = "\033[33m";
                }
                else if (piececolor == blue){
                    colorChange = "\033[34m";
                }
                else if (piececolor == magenta){
                    colorChange = "\033[35m";
                }
                else if (piececolor == cyan){
                    colorChange = "\033[36m";
                }
                else {
                    colorChange = "\033[37m";
                }
                if(board->getSquare(i, j)->getPiece()->getType() == Pn){
                    cout << "|" << colorChange << "Pn" << whiteColor << "|";
                }
                else if(board->getSquare(i, j)->getPiece()->getType() == Kn){
                    cout << "|" << colorChange << "Kn" << whiteColor << "|";
                }
                else if(board->getSquare(i, j)->getPiece()->getType() == Kg){
                    cout << "|" << colorChange << "Kg" << whiteColor << "|";
                }
                else if(board->getSquare(i, j)->getPiece()->getType() == Qn){
                    cout << "|" << colorChange << "Qn" << whiteColor << "|";
                }
                else if(board->getSquare(i, j)->getPiece()->getType() == Bp){
                    cout << "|" << colorChange << "Bp" << whiteColor << "|";
                }
                else if(board->getSquare(i, j)->getPiece()->getType() == Rk){
                    cout << "|" << colorChange << "Rk" << whiteColor << "|";
                }
                else {
                    cout << "|  |"; 
                }
            }
        }
        cout << " " << i << endl; 
        for (int k = 0; k < 8; ++k){
            cout << " __ ";
        }
        cout << endl; 
    }
}