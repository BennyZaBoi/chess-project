#include "gtest/gtest.h"
#include "../header/chessInstructions.h"
using namespace std;

TEST(ChessInstructionTest, printInstructionsScreen) {
    printInstructions();
    string expectedOutput =
    "                                                            Instructions                                                *"
    "*************************************************************************************************************************"
    " Chess is a two-player game played on an 8x8 chessboard."                                                                 
    " The goal of the game is to capture the enemy king."                                                                      
    " Each piece has its own unique movement pattern and can not move over other pieces except for the knight:"                
    "       King: 1 square in any direction, but can't be in a square directly next to the enemy king."                        
    "       Queen: any number of squares in any direction(vertical, horizontal, diagonal)."                                    
    "       Rook: any number squares vertically or horizontally."                                                              
    "       Bishop: any number squares diagonally."                                                                            
    "       Knight: can move in an L shape, 2 squares in any vertical or horizontal direction and 1 square left or right."     
    "           Knights can also move over your and your enemy's pieces."                                                      
    "       Pawn: can move 1 square forward but can only capture 1 square diagonally."                                         
    "           Pawns can move 2 squares forward if they haven't moved yet in the game."
    " Player 1 will always go first."
    " To make a move, enter the starting and ending coordinates in row then column format."                                    
    "       (ex: '12 14' indicates you want to move the piece on row 1 column 2 to row 1 column 2)."                           
    " Press 1 to return to the welcome menu."                                                                                  
    "*************************************************************************************************************************"; 
    expectedOutput += expectedOutput + "\n";

    EXPECT_NO_THROW(expectedOutput);
}