#include "gtest/gtest.h"
#include "../header/King.h"

TEST(KingMovementTests, offBoard){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 7, 7);
    EXPECT_FALSE(myKing->moveValid(8, 8, board));
}

TEST(KingMovementTests, verticalMovementEmpty){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    EXPECT_TRUE(myKing->moveValid(5, 6, board));
    EXPECT_TRUE(myKing->moveValid(7, 6, board));
}

TEST(KingMovementTests, verticalMovementAlly){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    board->getSquare(5, 6)->setPiece(new Knight(black, 5, 6));
    board->getSquare(7, 6)->setPiece(new Knight(black, 7, 6));
    EXPECT_FALSE(myKing->moveValid(5, 6, board));
    EXPECT_FALSE(myKing->moveValid(7, 6, board));
}

TEST(KingMovementTests, verticalMovementEnemy){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    board->getSquare(5, 6)->setPiece(new Knight(white, 5, 6));
    board->getSquare(7, 6)->setPiece(new Knight(white, 7, 6));
    EXPECT_TRUE(myKing->moveValid(5, 6, board));
    EXPECT_TRUE(myKing->moveValid(7, 6, board));
}

TEST(KingMovementTests, horizonalMovementEmpty){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    EXPECT_TRUE(myKing->moveValid(6, 5, board));
    EXPECT_TRUE(myKing->moveValid(6, 7, board));
}

TEST(KingMovementTests, horizonalMovementAlly){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    board->getSquare(6, 5)->setPiece(new Knight(black, 6, 5));
    board->getSquare(6, 7)->setPiece(new Knight(black, 6, 7));
    EXPECT_FALSE(myKing->moveValid(6, 5, board));
    EXPECT_FALSE(myKing->moveValid(6, 7, board));
}

TEST(KingMovementTests, horizonalMovementEnemy){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    board->getSquare(6, 5)->setPiece(new Knight(white, 6, 5));
    board->getSquare(6, 7)->setPiece(new Knight(white, 6, 7));
    EXPECT_TRUE(myKing->moveValid(6, 5, board));
    EXPECT_TRUE(myKing->moveValid(6, 7, board));
}

TEST(KingMovementTests, diagonalMovementEmpty){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    EXPECT_TRUE(myKing->moveValid(7, 7, board));
    EXPECT_TRUE(myKing->moveValid(5, 5, board));
    EXPECT_TRUE(myKing->moveValid(7, 5, board));
    EXPECT_TRUE(myKing->moveValid(5, 7, board));
}

TEST(KingMovementTests, diagonalMovementAlly){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    board->getSquare(7, 7)->setPiece(new Knight(black, 7, 7));
    board->getSquare(5, 5)->setPiece(new Knight(black, 5, 5));
    board->getSquare(7, 5)->setPiece(new Knight(black, 7, 5));
    board->getSquare(5, 7)->setPiece(new Knight(black, 5, 7));
    EXPECT_FALSE(myKing->moveValid(7, 7, board));
    EXPECT_FALSE(myKing->moveValid(5, 5, board));
    EXPECT_FALSE(myKing->moveValid(7, 5, board));
    EXPECT_FALSE(myKing->moveValid(5, 7, board));
}

TEST(KingMovementTests, diagonalMovementEnemy){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    board->getSquare(7, 7)->setPiece(new Knight(white, 7, 7));
    board->getSquare(5, 5)->setPiece(new Knight(white, 5, 5));
    board->getSquare(7, 5)->setPiece(new Knight(white, 7, 5));
    board->getSquare(5, 7)->setPiece(new Knight(white, 5, 7));
    EXPECT_TRUE(myKing->moveValid(7, 7, board));
    EXPECT_TRUE(myKing->moveValid(5, 5, board));
    EXPECT_TRUE(myKing->moveValid(7, 5, board));
    EXPECT_TRUE(myKing->moveValid(5, 7, board));
}

TEST(KingMovementTests, invalidMovement){
    Chessboard* board = new Chessboard();
    King* myKing = new King(black, 6, 6);
    EXPECT_FALSE(myKing->moveValid(4, 6, board));
    EXPECT_FALSE(myKing->moveValid(6, 4, board));
}