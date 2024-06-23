#include "gtest/gtest.h"
#include "../header/Rook.h"

TEST(RookMovementTests, HorizontalEmptyEnd){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    EXPECT_TRUE(myRook->moveValid(4, 5, board));
    EXPECT_TRUE(myRook->moveValid(4, 7, board));
    EXPECT_TRUE(myRook->moveValid(4, 3, board));
    EXPECT_TRUE(myRook->moveValid(4, 0, board));
}

TEST(RookMovementTests, HorizontalAllyEnd){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    board->getSquare(4, 7)->setPiece(new Rook(black, 4, 7));
    board->getSquare(4, 0)->setPiece(new Rook(black, 4, 0));
    EXPECT_FALSE(myRook->moveValid(4, 7, board));
    EXPECT_FALSE(myRook->moveValid(4, 0, board));

    board->getSquare(4, 5)->setPiece(new Rook(black, 4, 5));
    board->getSquare(4, 3)->setPiece(new Rook(black, 4, 3));
    EXPECT_FALSE(myRook->moveValid(4, 5, board));
    EXPECT_FALSE(myRook->moveValid(4, 3, board));
}

TEST(RookMovementTests, HorizontalEnemyEnd){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    board->getSquare(4, 7)->setPiece(new Rook(white, 4, 7));
    board->getSquare(4, 0)->setPiece(new Rook(white, 4, 0));
    EXPECT_TRUE(myRook->moveValid(4, 7, board));
    EXPECT_TRUE(myRook->moveValid(4, 0, board));

    board->getSquare(4, 5)->setPiece(new Rook(white, 4, 5));
    board->getSquare(4, 3)->setPiece(new Rook(white, 4, 3));
    EXPECT_TRUE(myRook->moveValid(4, 5, board));
    EXPECT_TRUE(myRook->moveValid(4, 3, board));
}

TEST(RookMovementTests, VerticalEmptyEnd){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    EXPECT_TRUE(myRook->moveValid(5, 4, board));
    EXPECT_TRUE(myRook->moveValid(7, 4, board));
    EXPECT_TRUE(myRook->moveValid(3, 4, board));
    EXPECT_TRUE(myRook->moveValid(0, 4, board));
}

TEST(RookMovementTests, VerticalAllyEnd){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    board->getSquare(7, 4)->setPiece(new Rook(black, 7, 4));
    board->getSquare(0, 4)->setPiece(new Rook(black, 0, 4));
    EXPECT_FALSE(myRook->moveValid(7, 4, board));
    EXPECT_FALSE(myRook->moveValid(0, 4, board));

    board->getSquare(5, 4)->setPiece(new Rook(black, 5, 4));
    board->getSquare(3, 4)->setPiece(new Rook(black, 3, 4));
    EXPECT_FALSE(myRook->moveValid(5, 4, board));
    EXPECT_FALSE(myRook->moveValid(3, 4, board));
}

TEST(RookMovementTests, VerticalEnemyEnd){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    board->getSquare(7, 4)->setPiece(new Rook(white, 7, 4));
    board->getSquare(0, 4)->setPiece(new Rook(white, 0, 4));
    EXPECT_TRUE(myRook->moveValid(7, 4, board));
    EXPECT_TRUE(myRook->moveValid(0, 4, board));

    board->getSquare(5, 4)->setPiece(new Rook(white, 5, 4));
    board->getSquare(3, 4)->setPiece(new Rook(white, 3, 4));
    EXPECT_TRUE(myRook->moveValid(5, 4, board));
    EXPECT_TRUE(myRook->moveValid(3, 4, board));
}

TEST(RookMovementTests, AllyInWay){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    board->getSquare(6, 4)->setPiece(new Rook(black, 6, 4));
    board->getSquare(2, 4)->setPiece(new Rook(black, 2, 4));
    board->getSquare(4, 6)->setPiece(new Rook(black, 4, 6));
    board->getSquare(4, 2)->setPiece(new Rook(black, 4, 2));
    EXPECT_FALSE(myRook->moveValid(7, 4, board));
    EXPECT_FALSE(myRook->moveValid(0, 4, board));
    EXPECT_FALSE(myRook->moveValid(4, 7, board));
    EXPECT_FALSE(myRook->moveValid(4, 0, board));
}

TEST(RookMovementTests, EnemyInWay){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    board->getSquare(6, 4)->setPiece(new Rook(white, 6, 4));
    board->getSquare(2, 4)->setPiece(new Rook(white, 2, 4));
    board->getSquare(4, 6)->setPiece(new Rook(white, 4, 6));
    board->getSquare(4, 2)->setPiece(new Rook(white, 4, 2));
    EXPECT_FALSE(myRook->moveValid(7, 4, board));
    EXPECT_FALSE(myRook->moveValid(0, 4, board));
    EXPECT_FALSE(myRook->moveValid(4, 7, board));
    EXPECT_FALSE(myRook->moveValid(4, 0, board));
}

TEST(RookMovementTests, invalidGeneralMovement){
    Chessboard* board = new Chessboard();
    Rook* myRook = new Rook(black, 4, 4);
    EXPECT_FALSE(myRook->moveValid(4, 8, board));
    EXPECT_FALSE(myRook->moveValid(4, -1, board));
    EXPECT_FALSE(myRook->moveValid(8, 4, board));
    EXPECT_FALSE(myRook->moveValid(-1, 4, board));
    EXPECT_FALSE(myRook->moveValid(3, 5, board));
    EXPECT_FALSE(myRook->moveValid(5, 5, board));
    EXPECT_FALSE(myRook->moveValid(3, 5, board));
    EXPECT_FALSE(myRook->moveValid(3, 3, board));
}