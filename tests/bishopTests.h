#include "gtest/gtest.h"
#include "../header/Bishop.h"

TEST(BishopMovementTests, ULandDREmptyEnd){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 4);
    EXPECT_TRUE(myBishop->moveValid(7, 7, board));
    EXPECT_TRUE(myBishop->moveValid(5, 5, board));
    EXPECT_TRUE(myBishop->moveValid(0, 0, board));
    EXPECT_TRUE(myBishop->moveValid(3, 3, board));
}

TEST(BishopMovementTests, ULandDRAllyEnd){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 4);
    board->getSquare(7, 7)->setPiece(new Bishop(black, 7, 7));
    board->getSquare(0, 0)->setPiece(new Bishop(black, 0, 0));
    EXPECT_FALSE(myBishop->moveValid(7, 7, board));
    EXPECT_FALSE(myBishop->moveValid(0, 0, board));

    board->getSquare(5, 5)->setPiece(new Bishop(black, 5, 5));
    board->getSquare(3, 3)->setPiece(new Bishop(black, 3, 3));
    EXPECT_FALSE(myBishop->moveValid(5, 5, board));
    EXPECT_FALSE(myBishop->moveValid(3, 3, board));
}

TEST(BishopMovementTests, ULandDREnemyEnd){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 4);
    board->getSquare(7, 7)->setPiece(new Bishop(white, 7, 7));
    board->getSquare(0, 0)->setPiece(new Bishop(white, 0, 0));
    EXPECT_TRUE(myBishop->moveValid(7, 7, board));
    EXPECT_TRUE(myBishop->moveValid(0, 0, board));

    board->getSquare(5, 5)->setPiece(new Bishop(white, 5, 5));
    board->getSquare(3, 3)->setPiece(new Bishop(white, 3, 3));
    EXPECT_TRUE(myBishop->moveValid(5, 5, board));
    EXPECT_TRUE(myBishop->moveValid(3, 3, board));
}

TEST(BishopMovementTests, URandDLEmptyEnd){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 3);
    EXPECT_TRUE(myBishop->moveValid(0, 7, board));
    EXPECT_TRUE(myBishop->moveValid(7, 0, board));
    EXPECT_TRUE(myBishop->moveValid(3, 4, board));
    EXPECT_TRUE(myBishop->moveValid(5, 2, board));
}

TEST(BishopMovementTests, URandDLAllyEnd){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 3);
    board->getSquare(0, 7)->setPiece(new Bishop(black, 0, 7));
    board->getSquare(7, 0)->setPiece(new Bishop(black, 7, 0));
    EXPECT_FALSE(myBishop->moveValid(0, 7, board));
    EXPECT_FALSE(myBishop->moveValid(7, 0, board));

    board->getSquare(3, 4)->setPiece(new Bishop(black, 3, 4));
    board->getSquare(5, 2)->setPiece(new Bishop(black, 5, 2));
    EXPECT_FALSE(myBishop->moveValid(3, 4, board));
    EXPECT_FALSE(myBishop->moveValid(5, 2, board));
}

TEST(BishopMovementTests, URandDLYEnemyEnd){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 3);
    board->getSquare(0, 7)->setPiece(new Bishop(white, 0, 7));
    board->getSquare(7, 0)->setPiece(new Bishop(white, 7, 0));
    EXPECT_TRUE(myBishop->moveValid(0, 7, board));
    EXPECT_TRUE(myBishop->moveValid(7, 0, board));

    board->getSquare(3, 4)->setPiece(new Bishop(white, 3, 4));
    board->getSquare(5, 2)->setPiece(new Bishop(white, 5, 2));
    EXPECT_TRUE(myBishop->moveValid(3, 4, board));
    EXPECT_TRUE(myBishop->moveValid(5, 2, board));
}

TEST(BishopMovementTests, AllyInWay){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 4);
    board->getSquare(6, 6)->setPiece(new Bishop(black, 6, 6));
    board->getSquare(1, 1)->setPiece(new Bishop(black, 1, 1));
    board->getSquare(2, 6)->setPiece(new Bishop(black, 2, 6));
    board->getSquare(6, 2)->setPiece(new Bishop(black, 6, 2));
    EXPECT_FALSE(myBishop->moveValid(7, 7, board));
    EXPECT_FALSE(myBishop->moveValid(0, 0, board));
    EXPECT_FALSE(myBishop->moveValid(1, 7, board));
    EXPECT_FALSE(myBishop->moveValid(7, 1, board));
}

TEST(BishopMovementTests, EnemyInWay){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 4);
    board->getSquare(6, 6)->setPiece(new Bishop(white, 6, 6));
    board->getSquare(1, 1)->setPiece(new Bishop(white, 1, 1));
    board->getSquare(2, 6)->setPiece(new Bishop(white, 2, 6));
    board->getSquare(6, 2)->setPiece(new Bishop(white, 6, 2));
    EXPECT_FALSE(myBishop->moveValid(7, 7, board));
    EXPECT_FALSE(myBishop->moveValid(0, 0, board));
    EXPECT_FALSE(myBishop->moveValid(1, 7, board));
    EXPECT_FALSE(myBishop->moveValid(7, 1, board));
}

TEST(BishopMovementTests, invalidGeneralMovement){
    Chessboard* board = new Chessboard();
    Bishop* myBishop = new Bishop(black, 4, 4);
    EXPECT_FALSE(myBishop->moveValid(8, 8, board));
    EXPECT_FALSE(myBishop->moveValid(-1, -1, board));
    EXPECT_FALSE(myBishop->moveValid(0, 8, board));
    EXPECT_FALSE(myBishop->moveValid(8, 0, board));
    EXPECT_FALSE(myBishop->moveValid(4, 5, board));
    EXPECT_FALSE(myBishop->moveValid(5, 4, board));
    EXPECT_FALSE(myBishop->moveValid(3, 4, board));
    EXPECT_FALSE(myBishop->moveValid(4, 3, board));
}