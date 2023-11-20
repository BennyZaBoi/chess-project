#include "gtest/gtest.h"
#include "../header/King.h"

TEST(pieceConstructorTests, pieceNotOnBoard){
    EXPECT_ANY_THROW(King* myKing1 = new King(black, -1, -1));
    EXPECT_ANY_THROW(King* myKing2 = new King(black, 8, 8));
}

TEST(pieceConstructorTests, pieceOnBoard){
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