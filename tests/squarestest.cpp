#include "gtest/gtest.h"
#include "../header/squares.h"

TEST(SquareTests, DefaultConstructor){
    EXPECT_NO_THROW(Squares* newSquare = new Squares());
}

TEST(SquareTests, NonDefaultConstructor){
    Piece randomPiece;  
    EXPECT_NO_THROW(Squares* newSquare = new Squares(1, 1, randomPiece);
}