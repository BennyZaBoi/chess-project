#include <iostream>
#include "../header/chessInstructions.h"
using namespace std;

void printInstructions() {
    cout << "                                                                   Instructions                                                            " << endl;
    cout << "*******************************************************************************************************************************************" << endl;
    cout << " Chess is a two-player game played on an 8x8 chessboard."                                                                                    << endl;
    cout << " The goal of the game is to capture the enemy king."                                                                                         << endl;
    cout << " Each piece has its own unique movement pattern and can not move over other pieces except for the knight:"                                   << endl;
    cout << "       King: 1 square in any direction, but can't be in a square directly next to the enemy king."                                           << endl;
    cout << "       Queen: any number of squares in any direction(vertical, horizontal, diagonal)."                                                       << endl;
    cout << "       Rook: any number squares vertically or horizontally."                                                                                 << endl;
    cout << "       Bishop: any number squares diagonally."                                                                                               << endl;
    cout << "       Knight: can move in an L shape, 2 squares in any vertical or horizontal direction and 1 square left or right."                        << endl;
    cout << "           Knights can also move over your and your enemy's pieces."                                                                         << endl;
    cout << "       Pawn: can move 1 square forward but can only capture 1 square diagonally."                                                            << endl;
    cout << "           Pawns can move 2 squares forward if they haven't moved yet in the game."                                                          << endl;
    cout << " To make a move, enter the starting and ending coordinates (ex: 'e2 e4' indicates you want to move the piece on e2 to e4)."                  << endl;
    cout << " Press 1 to return to the welcome menu."                                                                                                     << endl;
    cout << "*******************************************************************************************************************************************" << endl;
}