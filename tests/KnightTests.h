#include "gtest/gtest.h"
#include "../header/Knight.h"

TEST(KnightMovementTests, U2L1){
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(2,3));
}

TEST(KnightMovementTests, U2R1){
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(2,5));
}

TEST(KnightMovementTests, U1L2){
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(3,2));
}

TEST(KnightMovementTests, U1R2){
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(3,6));
}

TEST(KnightMovementTests, D2L1){
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(6,3));
}

TEST(KnightMovementTests, D2R1){
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(6,5));
}

TEST(KnightMovementTests, D1L2){
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(5,2));
}

TEST(KnightMovementTests, D1R2){
    Knight* myKnight = new Knight(black, 4, 4);
    EXPECT_TRUE(myKnight->moveValid(5,6));
}

TEST(KnightMovementTests, invalidMovement){
    Knight* myKnight = new Knight(black, 1, 1);
    EXPECT_FALSE(myKnight->moveValid(0,-1));
    EXPECT_FALSE(myKnight->moveValid(-1,0));
    EXPECT_FALSE(myKnight->moveValid(1,0));
    EXPECT_FALSE(myKnight->moveValid(1,1));
    EXPECT_FALSE(myKnight->moveValid(2,2));
}