#include "gtest/gtest.h"
#include "../header/King.h"

TEST(KingCapturedTests, isCaptured){
    King* myKing = new King(black, 0, 0);
    EXPECT_FALSE(myKing->isCaptured());
}

TEST(KingCapturedTests, setsCaptured){
    King* myKing = new King(black, 0, 0);
    myKing->setCaptured();
    EXPECT_TRUE(myKing->isCaptured());
}

TEST(KingMovementTests, kingMovesOffBoard){
    King* myKing = new King(black, 7, 7);
    EXPECT_FALSE(myKing->moveValid(8,8));
}

TEST(KingMovementTests, ForwardAndBackKingMoves){
    King* myKing = new King(black, 6, 6);
    EXPECT_TRUE(myKing->moveValid(5,6));
    EXPECT_TRUE(myKing->moveValid(7,6));
}

TEST(KingMovementTests, SidewaysKingMoves){
    King* myKing = new King(black, 6, 6);
    EXPECT_TRUE(myKing->moveValid(6,5));
    EXPECT_TRUE(myKing->moveValid(6,7));
}

TEST(KingMovementTests, DiagonalKingMoves){
    King* myKing = new King(black, 6, 6);
    EXPECT_TRUE(myKing->moveValid(7,7));
    EXPECT_TRUE(myKing->moveValid(5,5));
}

TEST(KingMovementTests, InvalidKingMoves){
    King* myKing = new King(black, 6, 6);
    EXPECT_FALSE(myKing->moveValid(4,6));
    EXPECT_FALSE(myKing->moveValid(6,4));
}