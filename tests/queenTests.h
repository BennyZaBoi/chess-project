#include "gtest/gtest.h"
#include "../header/Queen.h"

TEST(QueenMovementTests, HorizontalEmptyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    EXPECT_TRUE(myQueen->moveValid(4, 5, board));
    EXPECT_TRUE(myQueen->moveValid(4, 7, board));
    EXPECT_TRUE(myQueen->moveValid(4, 3, board));
    EXPECT_TRUE(myQueen->moveValid(4, 0, board));
}

TEST(QueenMovementTests, HorizontalAllyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(4, 7)->setPiece(new Queen(black, 4, 7));
    board->getSquare(4, 0)->setPiece(new Queen(black, 4, 0));
    EXPECT_FALSE(myQueen->moveValid(4, 7, board));
    EXPECT_FALSE(myQueen->moveValid(4, 0, board));

    board->getSquare(4, 5)->setPiece(new Queen(black, 4, 5));
    board->getSquare(4, 3)->setPiece(new Queen(black, 4, 3));
    EXPECT_FALSE(myQueen->moveValid(4, 5, board));
    EXPECT_FALSE(myQueen->moveValid(4, 3, board));
}

TEST(QueenMovementTests, HorizontalEnemyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(4, 7)->setPiece(new Queen(white, 4, 7));
    board->getSquare(4, 0)->setPiece(new Queen(white, 4, 0));
    EXPECT_TRUE(myQueen->moveValid(4, 7, board));
    EXPECT_TRUE(myQueen->moveValid(4, 0, board));

    board->getSquare(4, 5)->setPiece(new Queen(white, 4, 5));
    board->getSquare(4, 3)->setPiece(new Queen(white, 4, 3));
    EXPECT_TRUE(myQueen->moveValid(4, 5, board));
    EXPECT_TRUE(myQueen->moveValid(4, 3, board));
}

TEST(QueenMovementTests, VerticalEmptyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    EXPECT_TRUE(myQueen->moveValid(5, 4, board));
    EXPECT_TRUE(myQueen->moveValid(7, 4, board));
    EXPECT_TRUE(myQueen->moveValid(3, 4, board));
    EXPECT_TRUE(myQueen->moveValid(0, 4, board));
}

TEST(QueenMovementTests, VerticalAllyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(7, 4)->setPiece(new Queen(black, 7, 4));
    board->getSquare(0, 4)->setPiece(new Queen(black, 0, 4));
    EXPECT_FALSE(myQueen->moveValid(7, 4, board));
    EXPECT_FALSE(myQueen->moveValid(0, 4, board));

    board->getSquare(5, 4)->setPiece(new Queen(black, 5, 4));
    board->getSquare(3, 4)->setPiece(new Queen(black, 3, 4));
    EXPECT_FALSE(myQueen->moveValid(5, 4, board));
    EXPECT_FALSE(myQueen->moveValid(3, 4, board));
}

TEST(QueenMovementTests, VerticalEnemyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(7, 4)->setPiece(new Queen(white, 7, 4));
    board->getSquare(0, 4)->setPiece(new Queen(white, 0, 4));
    EXPECT_TRUE(myQueen->moveValid(7, 4, board));
    EXPECT_TRUE(myQueen->moveValid(0, 4, board));

    board->getSquare(5, 4)->setPiece(new Queen(white, 5, 4));
    board->getSquare(3, 4)->setPiece(new Queen(white, 3, 4));
    EXPECT_TRUE(myQueen->moveValid(5, 4, board));
    EXPECT_TRUE(myQueen->moveValid(3, 4, board));
}

TEST(QueenMovementTests, AllyInWayHorizontalAndVertical){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(6, 4)->setPiece(new Queen(black, 6, 4));
    board->getSquare(2, 4)->setPiece(new Queen(black, 2, 4));
    board->getSquare(4, 6)->setPiece(new Queen(black, 4, 6));
    board->getSquare(4, 2)->setPiece(new Queen(black, 4, 2));
    EXPECT_FALSE(myQueen->moveValid(7, 4, board));
    EXPECT_FALSE(myQueen->moveValid(0, 4, board));
    EXPECT_FALSE(myQueen->moveValid(4, 7, board));
    EXPECT_FALSE(myQueen->moveValid(4, 0, board));
}

TEST(QueenMovementTests, EnemyInWayHorizontalAndVertical){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(6, 4)->setPiece(new Queen(white, 6, 4));
    board->getSquare(2, 4)->setPiece(new Queen(white, 2, 4));
    board->getSquare(4, 6)->setPiece(new Queen(white, 4, 6));
    board->getSquare(4, 2)->setPiece(new Queen(white, 4, 2));
    EXPECT_FALSE(myQueen->moveValid(7, 4, board));
    EXPECT_FALSE(myQueen->moveValid(0, 4, board));
    EXPECT_FALSE(myQueen->moveValid(4, 7, board));
    EXPECT_FALSE(myQueen->moveValid(4, 0, board));
}

TEST(QueenMovementTests, ULandDREmptyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    EXPECT_TRUE(myQueen->moveValid(7, 7, board));
    EXPECT_TRUE(myQueen->moveValid(5, 5, board));
    EXPECT_TRUE(myQueen->moveValid(0, 0, board));
    EXPECT_TRUE(myQueen->moveValid(3, 3, board));
}

TEST(QueenMovementTests, ULandDRAllyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(7, 7)->setPiece(new Queen(black, 7, 7));
    board->getSquare(0, 0)->setPiece(new Queen(black, 0, 0));
    EXPECT_FALSE(myQueen->moveValid(7, 7, board));
    EXPECT_FALSE(myQueen->moveValid(0, 0, board));

    board->getSquare(5, 5)->setPiece(new Queen(black, 5, 5));
    board->getSquare(3, 3)->setPiece(new Queen(black, 3, 3));
    EXPECT_FALSE(myQueen->moveValid(5, 5, board));
    EXPECT_FALSE(myQueen->moveValid(3, 3, board));
}

TEST(QueenMovementTests, ULandDREnemyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(7, 7)->setPiece(new Queen(white, 7, 7));
    board->getSquare(0, 0)->setPiece(new Queen(white, 0, 0));
    EXPECT_TRUE(myQueen->moveValid(7, 7, board));
    EXPECT_TRUE(myQueen->moveValid(0, 0, board));

    board->getSquare(5, 5)->setPiece(new Queen(white, 5, 5));
    board->getSquare(3, 3)->setPiece(new Queen(white, 3, 3));
    EXPECT_TRUE(myQueen->moveValid(5, 5, board));
    EXPECT_TRUE(myQueen->moveValid(3, 3, board));
}

TEST(QueenMovementTests, URandDLEmptyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 3);
    EXPECT_TRUE(myQueen->moveValid(0, 7, board));
    EXPECT_TRUE(myQueen->moveValid(7, 0, board));
    EXPECT_TRUE(myQueen->moveValid(3, 4, board));
    EXPECT_TRUE(myQueen->moveValid(5, 2, board));
}

TEST(QueenMovementTests, URandDLAllyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 3);
    board->getSquare(0, 7)->setPiece(new Queen(black, 0, 7));
    board->getSquare(7, 0)->setPiece(new Queen(black, 7, 0));
    EXPECT_FALSE(myQueen->moveValid(0, 7, board));
    EXPECT_FALSE(myQueen->moveValid(7, 0, board));

    board->getSquare(3, 4)->setPiece(new Queen(black, 3, 4));
    board->getSquare(5, 2)->setPiece(new Queen(black, 5, 2));
    EXPECT_FALSE(myQueen->moveValid(3, 4, board));
    EXPECT_FALSE(myQueen->moveValid(5, 2, board));
}

TEST(QueenMovementTests, URandDLYEnemyEnd){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 3);
    board->getSquare(0, 7)->setPiece(new Queen(white, 0, 7));
    board->getSquare(7, 0)->setPiece(new Queen(white, 7, 0));
    EXPECT_TRUE(myQueen->moveValid(0, 7, board));
    EXPECT_TRUE(myQueen->moveValid(7, 0, board));

    board->getSquare(3, 4)->setPiece(new Queen(white, 3, 4));
    board->getSquare(5, 2)->setPiece(new Queen(white, 5, 2));
    EXPECT_TRUE(myQueen->moveValid(3, 4, board));
    EXPECT_TRUE(myQueen->moveValid(5, 2, board));
}

TEST(QueenMovementTests, AllyInWayDiagonals){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(6, 6)->setPiece(new Queen(black, 6, 6));
    board->getSquare(1, 1)->setPiece(new Queen(black, 1, 1));
    board->getSquare(2, 6)->setPiece(new Queen(black, 2, 6));
    board->getSquare(6, 2)->setPiece(new Queen(black, 6, 2));
    EXPECT_FALSE(myQueen->moveValid(7, 7, board));
    EXPECT_FALSE(myQueen->moveValid(0, 0, board));
    EXPECT_FALSE(myQueen->moveValid(1, 7, board));
    EXPECT_FALSE(myQueen->moveValid(7, 1, board));
}

TEST(QueenMovementTests, EnemyInWayDiagonals){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    board->getSquare(6, 6)->setPiece(new Queen(white, 6, 6));
    board->getSquare(1, 1)->setPiece(new Queen(white, 1, 1));
    board->getSquare(2, 6)->setPiece(new Queen(white, 2, 6));
    board->getSquare(6, 2)->setPiece(new Queen(white, 6, 2));
    EXPECT_FALSE(myQueen->moveValid(7, 7, board));
    EXPECT_FALSE(myQueen->moveValid(0, 0, board));
    EXPECT_FALSE(myQueen->moveValid(1, 7, board));
    EXPECT_FALSE(myQueen->moveValid(7, 1, board));
}

TEST(QueenMovementTests, invalidGeneralMovement){
    Chessboard* board = new Chessboard();
    Queen* myQueen = new Queen(black, 4, 4);
    EXPECT_FALSE(myQueen->moveValid(8, 8, board));
    EXPECT_FALSE(myQueen->moveValid(-1, -1, board));
    EXPECT_FALSE(myQueen->moveValid(0, 8, board));
    EXPECT_FALSE(myQueen->moveValid(8, 0, board));

    EXPECT_FALSE(myQueen->moveValid(4, 8, board));
    EXPECT_FALSE(myQueen->moveValid(4, -1, board));
    EXPECT_FALSE(myQueen->moveValid(8, 4, board));
    EXPECT_FALSE(myQueen->moveValid(-1, 4, board));

    EXPECT_FALSE(myQueen->moveValid(3, 2, board));
    EXPECT_FALSE(myQueen->moveValid(2, 3, board));
    EXPECT_FALSE(myQueen->moveValid(2, 5, board));
    EXPECT_FALSE(myQueen->moveValid(3, 6, board));
    EXPECT_FALSE(myQueen->moveValid(5, 6, board));
    EXPECT_FALSE(myQueen->moveValid(6, 5, board));
    EXPECT_FALSE(myQueen->moveValid(6, 3, board));
    EXPECT_FALSE(myQueen->moveValid(5, 2, board));
}