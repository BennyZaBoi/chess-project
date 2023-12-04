#include "gtest/gtest.h"
#include "../header/Knight.h"
#include "../header/squares.h"

TEST(SquareTests, DefaultConstructor){
    EXPECT_NO_THROW(Squares* newSquare = new Squares());
}

TEST(SquareTests, NonDefaultConstructor){
    Knight* newPiece = new Knight(black, 5, 7);
    EXPECT_NO_THROW(Squares* newSquare = new Squares(5, 7, newPiece));
}

TEST (SquareTests, InvalidArgumentConstructor){
    //Already a Check for Knight Tests. Just needed to check specifically for square.
    Knight* newPiece = new Knight (black, 5, 7);
    EXPECT_ANY_THROW(Squares* newSquare = new Squares(5, 8, newPiece));
}

TEST (SquareTests, NegArgumentConstructor){
    //Already a Check for Knight Tests. Just needed to check specifically for square.
    Knight* newPiece = new Knight (black, 5, 7);
    EXPECT_ANY_THROW(Squares* newSquare = new Squares(-1, 7, newPiece));
}

TEST (SquareTests, getColumn){
  Knight* newPiece = new Knight (black, 2, 3);
  Squares* newSquare = new Squares(2, 3, newPiece);
  EXPECT_EQ(newSquare->getColumn(), 3); 
}

TEST (SquareTests, getRow){
  Knight* newPiece = new Knight (black, 2, 3);
  Squares* newSquare = new Squares(2, 3, newPiece);
  EXPECT_EQ(newSquare->getRow(), 2); 
}

TEST (SquareTests, notOccupiedSquare){
  Squares* newSquare = new Squares(2, 3, nullptr);
  EXPECT_FALSE(newSquare->isOccupied());  
}

TEST (SquareTests, OccupiedSquare){
  Knight* newPiece = new Knight (black, 2, 3);
  Squares* newSquare = new Squares(2, 3, newPiece);
  EXPECT_TRUE(newSquare->isOccupied());  
}