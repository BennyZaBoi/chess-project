#include "gtest/gtest.h"
#include "../header/displaychessboard.h"

TEST(DisplayChessboardTests, TypeTestKnight){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece2 = new Knight(white, 2, 2);
    newBoard->getSquare(2, 2)->setPiece(newPiece2);
    EXPECT_NO_THROW(displayBoard(newBoard)); 
}