#include "gtest/gtest.h"
#include "../header/chessboard.h"
#include "../header/squares.h"
#include "../header/Knight.h"

TEST(ChessboardTests, DefaultConstructor){
    EXPECT_NO_THROW(Chessboard* newBoard = new Chessboard());
}

TEST(ChessboardTests, StraightDiffRowsColumns){
    Chessboard* newBoard = new Chessboard(); 
    Knight* newPiece1 = new Knight(black, 5, 7);
    Knight* newPiece2 = new Knight(white, 4, 5);
    Squares* newSquare1 = new Squares(5, 7, newPiece1);
    Squares* newSquare2 = new Squares(4, 5, newPiece2); 
    EXPECT_FALSE(newBoard->pathClearStraight(newSquare1, newSquare2));
}

TEST(ChessboardTests, StraightSameSpot){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 7);
    Squares* newSquare1 = new Squares(5, 7, newPiece1);
    EXPECT_FALSE(newBoard->pathClearStraight(newSquare1, newSquare1));
}

TEST(ChessboardTests, StraightPiecesNextToEachOtherRowDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 7);
    Knight* newPiece2 = new Knight(white, 4, 7);
    Squares* newSquare1 = new Squares(5, 7, newPiece1);
    Squares* newSquare2 = new Squares(4, 7, newPiece2);
    EXPECT_TRUE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightPiecesNextToEachOtherRowAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 4, 7);
    Knight* newPiece2 = new Knight(white, 5, 7);
    Squares* newSquare1 = new Squares(4, 7, newPiece1);
    Squares* newSquare2 = new Squares(5, 7, newPiece2);
    EXPECT_TRUE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightPiecesNextToEachOtherColumnAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 6);
    Knight* newPiece2 = new Knight(white, 5, 7);
    Squares* newSquare1 = new Squares(5, 6, newPiece1);
    Squares* newSquare2 = new Squares(5, 7, newPiece2);
    EXPECT_TRUE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightPiecesNextToEachOtherColumnDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 7);
    Knight* newPiece2 = new Knight(white, 5, 6);
    Squares* newSquare1 = new Squares(5, 7, newPiece1);
    Squares* newSquare2 = new Squares(5, 6, newPiece2);
    EXPECT_TRUE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightPiecesFarApartRowDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 7);
    Knight* newPiece2 = new Knight(white, 1, 7);
    Squares* newSquare1 = new Squares(5, 7, newPiece1);
    Squares* newSquare2 = new Squares(1, 7, newPiece2);
    EXPECT_TRUE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightPiecesFarApartRowAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 1, 7);
    Knight* newPiece2 = new Knight(white, 5, 7);
    Squares* newSquare1 = new Squares(1, 7, newPiece1);
    Squares* newSquare2 = new Squares(5, 7, newPiece2);
    EXPECT_TRUE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightPiecesFarApartColumnAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 1);
    Knight* newPiece2 = new Knight(white, 5, 7);
    Squares* newSquare1 = new Squares(5, 1, newPiece1);
    Squares* newSquare2 = new Squares(5, 7, newPiece2);
    EXPECT_TRUE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightPiecesFarApartColumnDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 7);
    Knight* newPiece2 = new Knight(white, 5, 1);
    Squares* newSquare1 = new Squares(5, 7, newPiece1);
    Squares* newSquare2 = new Squares(5, 1, newPiece2);
    EXPECT_TRUE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, getSquareSet){
    Chessboard* newBoard = new Chessboard(); 
    Knight* newPiece1 = new Knight(black, 5, 4);
    EXPECT_NO_THROW(newBoard->getSquare(5, 4)->setPiece(newPiece1)); 
}

TEST(ChessboardTests, StraightInterferenceDiffColumnDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 7);
    Knight* newPiece2 = new Knight(white, 5, 1);
    Knight* newPiece3 = new Knight(white, 5, 4); 
    Squares* newSquare1 = new Squares(5, 7, newPiece1);
    Squares* newSquare2 = new Squares(5, 1, newPiece2);
    newBoard->getSquare(5, 4)->setPiece(newPiece3);
    EXPECT_FALSE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightInterferenceDiffColumnAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 1);
    Knight* newPiece2 = new Knight(white, 5, 7);
    Knight* newPiece3 = new Knight(white, 5, 4); 
    Squares* newSquare1 = new Squares(5, 1, newPiece1);
    Squares* newSquare2 = new Squares(5, 7, newPiece2);
    newBoard->getSquare(5, 4)->setPiece(newPiece3);
    EXPECT_FALSE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightInterferenceDiffRowDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 7, 5);
    Knight* newPiece2 = new Knight(white, 1, 5);
    Knight* newPiece3 = new Knight(white, 4, 5); 
    Squares* newSquare1 = new Squares(7, 5, newPiece1);
    Squares* newSquare2 = new Squares(1, 5, newPiece2);
    newBoard->getSquare(4, 5)->setPiece(newPiece3);
    EXPECT_FALSE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, StraightInterferenceDiffRowAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 1, 5);
    Knight* newPiece2 = new Knight(white, 7, 5);
    Knight* newPiece3 = new Knight(white, 4, 5); 
    Squares* newSquare1 = new Squares(1, 5, newPiece1);
    Squares* newSquare2 = new Squares(7, 5, newPiece2);
    newBoard->getSquare(4, 5)->setPiece(newPiece3);
    EXPECT_FALSE(newBoard->pathClearStraight(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalSameColumns){
    Chessboard* newBoard = new Chessboard(); 
    Knight* newPiece1 = new Knight(black, 3, 7);
    Knight* newPiece2 = new Knight(white, 4, 7);
    Squares* newSquare1 = new Squares(3, 7, newPiece1);
    Squares* newSquare2 = new Squares(4, 7, newPiece2); 
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2));
}

TEST(ChessboardTests, DiagonalSameRows){
    Chessboard* newBoard = new Chessboard(); 
    Knight* newPiece1 = new Knight(black, 4, 7);
    Knight* newPiece2 = new Knight(white, 4, 5);
    Squares* newSquare1 = new Squares(4, 7, newPiece1);
    Squares* newSquare2 = new Squares(4, 5, newPiece2); 
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2));
}

TEST(ChessboardTests, DiagonalSameSpot){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 5, 7);
    Squares* newSquare1 = new Squares(5, 7, newPiece1);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare1));
}

TEST(ChessboardTests, DiagonalNondiagonalPieceTopLeft){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 1, 1);
    Knight* newPiece2 = new Knight(white, 3, 4); 
    Squares* newSquare1 = new Squares(1, 1, newPiece1);
    Squares* newSquare2 = new Squares(3, 4, newPiece2);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalPieceTopLeftAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 1, 1);
    Knight* newPiece2 = new Knight(white, 3, 3); 
    Squares* newSquare1 = new Squares(1, 1, newPiece1);
    Squares* newSquare2 = new Squares(3, 3, newPiece2);
    EXPECT_TRUE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalInterferenceTopLeftAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 1, 1);
    Knight* newPiece2 = new Knight(white, 2, 2);
    Knight* newPiece3 = new Knight(white, 3, 3); 
    Squares* newSquare1 = new Squares(1, 1, newPiece1);
    Squares* newSquare2 = new Squares(3, 3, newPiece3);
    newBoard->getSquare(2, 2)->setPiece(newPiece2);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalNondiagonalPieceTopRight){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 1, 7);
    Knight* newPiece2 = new Knight(white, 3, 4); 
    Squares* newSquare1 = new Squares(1, 7, newPiece1);
    Squares* newSquare2 = new Squares(3, 4, newPiece2);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalPieceTopRightAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 1, 7);
    Knight* newPiece2 = new Knight(white, 3, 5); 
    Squares* newSquare1 = new Squares(1, 7, newPiece1);
    Squares* newSquare2 = new Squares(3, 5, newPiece2);
    EXPECT_TRUE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalInterferenceTopRightAscending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 1, 7);
    Knight* newPiece2 = new Knight(white, 2, 6);
    Knight* newPiece3 = new Knight(white, 3, 5); 
    Squares* newSquare1 = new Squares(1, 7, newPiece1);
    Squares* newSquare2 = new Squares(3, 5, newPiece3);
    newBoard->getSquare(2, 6)->setPiece(newPiece2);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}


TEST(ChessboardTests, DiagonalNondiagonalPieceBottomLeft){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 7, 1);
    Knight* newPiece2 = new Knight(white, 5, 0); 
    Squares* newSquare1 = new Squares(7, 1, newPiece1);
    Squares* newSquare2 = new Squares(5, 0, newPiece2);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalPieceBottomLeftDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 7, 1);
    Knight* newPiece2 = new Knight(white, 3, 5); 
    Squares* newSquare1 = new Squares(7, 1, newPiece1);
    Squares* newSquare2 = new Squares(3, 5, newPiece2);
    EXPECT_TRUE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalInterferenceBottomLeftDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 7, 1);
    Knight* newPiece2 = new Knight(white, 4, 4);
    Knight* newPiece3 = new Knight(white, 3, 5); 
    Squares* newSquare1 = new Squares(7, 1, newPiece1);
    Squares* newSquare2 = new Squares(3, 5, newPiece3);
    newBoard->getSquare(4, 4)->setPiece(newPiece2);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalNondiagonalPieceBottomRight){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 7, 7);
    Knight* newPiece2 = new Knight(white, 1, 6); 
    Squares* newSquare1 = new Squares(7, 7, newPiece1);
    Squares* newSquare2 = new Squares(1, 6, newPiece2);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalPieceBottomRightDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 7, 7);
    Knight* newPiece2 = new Knight(white, 1, 1); 
    Squares* newSquare1 = new Squares(7, 7, newPiece1);
    Squares* newSquare2 = new Squares(1, 1, newPiece2);
    EXPECT_TRUE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}

TEST(ChessboardTests, DiagonalInterferenceBottomRightDescending){
    Chessboard* newBoard = new Chessboard();
    Knight* newPiece1 = new Knight(black, 7, 7);
    Knight* newPiece2 = new Knight(white, 2, 2);
    Knight* newPiece3 = new Knight(white, 1, 1); 
    Squares* newSquare1 = new Squares(7, 7, newPiece1);
    Squares* newSquare2 = new Squares(1, 1, newPiece3);
    newBoard->getSquare(2, 2)->setPiece(newPiece2);
    EXPECT_FALSE(newBoard->pathClearDiagonal(newSquare1, newSquare2)); 
}