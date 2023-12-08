#include "gtest/gtest.h"
#include "../header/displaychessboard.h"

TEST(DisplayChessboardTests, TypeTestKnight){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece2 = new Knight(white, 2, 2);
    newBoard->getSquare(0, 0)->setPiece(newPiece2);
    ChessboardDisplay* showChess = new ChessboardDisplay();
    EXPECT_NO_THROW(showChess->displayBoard(newBoard));
}