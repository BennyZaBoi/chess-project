#include "gtest/gtest.h"
#include "../header/Knight.h"

TEST(KnightMovementTests, U2L1Empty){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(2, 3, board));
}

TEST(KnightMovementTests, U2L1Ally){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(2, 3)->setPiece(new Knight(black, 2, 3));
    EXPECT_FALSE(myKnight->moveValid(2, 3, board));
}

TEST(KnightMovementTests, U2L1Enemy){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(2, 3)->setPiece( new Knight(white, 2, 3));
    EXPECT_TRUE(myKnight->moveValid(2, 3, board));
}

TEST(KnightMovementTests, U2R1Empty){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(2, 5, board));
}

TEST(KnightMovementTests, U2R1Ally){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(2, 5)->setPiece(new Knight(black, 2, 5));
    EXPECT_FALSE(myKnight->moveValid(2, 5, board));
}

TEST(KnightMovementTests, U2R1Enemy){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(2, 5)->setPiece(new Knight(white, 2, 5));
    EXPECT_TRUE(myKnight->moveValid(2, 5, board));
}

TEST(KnightMovementTests, U1L2Empty){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(3, 2, board));
}

TEST(KnightMovementTests, U1L2Ally){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(3, 2)->setPiece(new Knight(black, 3, 2));
    EXPECT_FALSE(myKnight->moveValid(3, 2, board));
}

TEST(KnightMovementTests, U1L2Enemy){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(3, 2)->setPiece(new Knight(white, 3, 2));
    EXPECT_TRUE(myKnight->moveValid(3, 2, board));
}

TEST(KnightMovementTests, U1R2Empty){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(3, 6, board));
}

TEST(KnightMovementTests, U1R2Ally){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(3, 6)->setPiece(new Knight(black, 3, 6));
    EXPECT_FALSE(myKnight->moveValid(3, 6, board));
}

TEST(KnightMovementTests, U1R2Enemy){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(3, 6)->setPiece(new Knight(white, 3, 6));
    EXPECT_TRUE(myKnight->moveValid(3, 6, board));
}

TEST(KnightMovementTests, D2L1Empty){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(6, 3, board));
}

TEST(KnightMovementTests, D2L1Ally){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(6, 3)->setPiece(new Knight(black, 6, 3));
    EXPECT_FALSE(myKnight->moveValid(6, 3, board));
}

TEST(KnightMovementTests, D2L1Enemy){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(6, 3)->setPiece(new Knight(white, 6, 3));
    EXPECT_TRUE(myKnight->moveValid(6, 3, board));
}

TEST(KnightMovementTests, D2R1Empty){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(6, 5, board));
}

TEST(KnightMovementTests, D2R1Ally){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(6, 5)->setPiece(new Knight(black, 6, 5));
    EXPECT_FALSE(myKnight->moveValid(6, 5, board));
}

TEST(KnightMovementTests, D2R1Enemy){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(6, 5)->setPiece(new Knight(white, 6, 5));
    EXPECT_TRUE(myKnight->moveValid(6, 5, board));
}

TEST(KnightMovementTests, D1L2Empty){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(5, 2, board));
}

TEST(KnightMovementTests, D1L2Ally){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(5, 2)->setPiece(new Knight(black, 5, 2));
    EXPECT_FALSE(myKnight->moveValid(5, 2, board));
}

TEST(KnightMovementTests, D1L2Enemy){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(5, 2)->setPiece(new Knight(white, 5, 2));
    EXPECT_TRUE(myKnight->moveValid(5, 2, board));
}

TEST(KnightMovementTests, D1R2Empty){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(5, 6, board));
}

TEST(KnightMovementTests, D1R2Ally){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(5, 6)->setPiece(new Knight(black, 5, 6));
    EXPECT_FALSE(myKnight->moveValid(5, 6, board));
}

TEST(KnightMovementTests, D1R2Enemy){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 4, 4);
    board->getSquare(5,6)->setPiece(new Knight(white, 5, 6));
    EXPECT_TRUE(myKnight->moveValid(5, 6, board));
}

TEST(KnightMovementTests, invalidMovement){
    Chessboard* board = new Chessboard();
    Knight* myKnight = new Knight(black, 1, 1);
    EXPECT_FALSE(myKnight->moveValid(0, -1, board));
    EXPECT_FALSE(myKnight->moveValid(-1, 0, board));
    EXPECT_FALSE(myKnight->moveValid(1, 0, board));
    EXPECT_FALSE(myKnight->moveValid(1, 1, board));
    EXPECT_FALSE(myKnight->moveValid(2, 2, board));
}