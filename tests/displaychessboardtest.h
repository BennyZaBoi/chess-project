#include "gtest/gtest.h"
#include "../header/displaychessboard.h"

TEST(DisplayChessboardTests, TypeTestKnight){
    Chessboard* newBoard = new Chessboard();
    Queen* newPiece1 = new Queen(white, 1, 1); 
    Knight* newPiece2 = new Knight(green, 2, 2);
    Rook* newPiece3 = new Rook(magenta, 7, 7); 
    newBoard->getSquare(2, 2)->setPiece(newPiece2);
    newBoard->getSquare(1, 1)->setPiece(newPiece1);
    newBoard->getSquare(7, 7)->setPiece(newPiece3);
    ChessboardDisplay* showChess = new ChessboardDisplay();
    EXPECT_NO_THROW(showChess->displayBoard(newBoard));
}