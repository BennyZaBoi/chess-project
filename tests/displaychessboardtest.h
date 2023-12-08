#include "gtest/gtest.h"
#include "../header/displaychessboard.h"
#include "../source/displaychessboard.cpp"

TEST(DisplayChessboardTests, TypeTestKnight){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece2 = new Knight(white, 2, 2);
    newBoard->getSquare(2, 2)->setPiece(newPiece2);
    ChessboardDisplay* showChess = new ChessboardDisplay();
    showChess->displayBoard(newBoard);
}