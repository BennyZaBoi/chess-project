#include "gtest/gtest.h"
#include "../header/King.h"

TEST(SPMovedTests, hasMoved){
    King* myKing = new King(black, 0, 0);
    EXPECT_FALSE(myKing->hasMoved());
}

TEST(SPMovedTests, setMoved){
    King* myKing = new King(black, 0, 0);
    myKing->setMoved();
    EXPECT_TRUE(myKing->hasMoved());
}