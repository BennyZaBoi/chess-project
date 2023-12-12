#include "gtest/gtest.h"
#include "../header/King.h"

TEST(pieceConstructorTests, invalidInitialRowCol){
    EXPECT_DEBUG_DEATH(King* myKing1 = new King(black, -1, -1), "Error: Invalid Inputs For Piece");
    EXPECT_DEBUG_DEATH(King* myKing2 = new King(black, 8, 8), "Error: Invalid Inputs For Piece");
}

TEST(pieceConstructorTests, validInitialRowCol){
    EXPECT_NO_THROW(King* myKing1 = new King(black, 0, 0));
    EXPECT_NO_THROW(King* myKing2 = new King(black, 7, 7));
}

TEST(pieceGetColorTests, returnsCorrectColor){
    King* myKing = new King(black, 0, 0);
    EXPECT_EQ(myKing->getColor(), black);
    EXPECT_NE(myKing->getColor(), blue);
}

TEST(pieceGetTypeTests, returnsCorrectType){
    King* myKing = new King(black, 0, 0);
    EXPECT_EQ(myKing->getType(), Kg);
    EXPECT_NE(myKing->getType(), Pn);
}

TEST(pieceGetRowTests, returnsCorrectRow){
    King* myKing = new King(black, 0, 0);
    EXPECT_EQ(myKing->getRow(), 0);
    EXPECT_NE(myKing->getRow(), 1);
}

TEST(pieceGetColumnTests, returnsCorrectColumn){
    King* myKing = new King(black, 0, 0);
    EXPECT_EQ(myKing->getColumn(), 0);
    EXPECT_NE(myKing->getColumn(), 1);
}

TEST(pieceOnBoardTests, onBoard){
    King* myKing = new King(black, 0, 0);
    EXPECT_TRUE(myKing->onBoard(0, 0));
    EXPECT_TRUE(myKing->onBoard(0, 7));
    EXPECT_TRUE(myKing->onBoard(7, 0));
    EXPECT_TRUE(myKing->onBoard(7, 7));
}

TEST(pieceOnBoardTests, notOnBoard){
    King* myKing = new King(black, 0, 0);
    EXPECT_FALSE(myKing->onBoard(-1, -1));
    EXPECT_FALSE(myKing->onBoard(-1, 0));
    EXPECT_FALSE(myKing->onBoard(0, -1));
    EXPECT_FALSE(myKing->onBoard(8, 8));
    EXPECT_FALSE(myKing->onBoard(7, 8));
    EXPECT_FALSE(myKing->onBoard(8, 7));
}

TEST(isMovingTests, movingToNewLocation){
    King* myKing = new King(black, 4, 4);
    EXPECT_TRUE(myKing->isMoving(5,5));
    EXPECT_TRUE(myKing->isMoving(5,4));
    EXPECT_TRUE(myKing->isMoving(4,5));
    EXPECT_TRUE(myKing->isMoving(3,3));
    EXPECT_TRUE(myKing->isMoving(3,4));
    EXPECT_TRUE(myKing->isMoving(4,3));
    EXPECT_TRUE(myKing->isMoving(5,3));
    EXPECT_TRUE(myKing->isMoving(3,5));
}

TEST(isMovingTests, movingToSameLocation){
    King* myKing = new King(black, 4, 4);
    EXPECT_FALSE(myKing->isMoving(4,4));
}