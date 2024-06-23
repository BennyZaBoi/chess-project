#include "gtest/gtest.h"
#include "../header/displaychessboard.h"
#include "../header/Rook.h"
#include "../header/Queen.h"
#include "../header/Knight.h"
#include "../header/Bishop.h"
#include "../header/Pawn.h"
#include "../header/King.h"

TEST(DisplayChessboardTests, TypeTestKnight){
    Chessboard* newBoard = new Chessboard();
    newBoard->initializeChessboard(magenta, cyan); 
    ChessboardDisplay* showChess = new ChessboardDisplay();
    EXPECT_NO_THROW(showChess->displayBoard(newBoard));
}