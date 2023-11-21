#include "gtest/gtest.h"
#include "../header/Pawn.h"

TEST(PawnUpwardsMovementTests, moveForwardOne){
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_TRUE(myPawn->moveValid(5,6));
    EXPECT_FALSE(myPawn->moveValid(7,6));
}

TEST(PawnUpwardsMovementTests, moveDiagonalLeft){
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_TRUE(myPawn->moveValid(5,5));
}

TEST(PawnUpwardsMovementTests, moveDiagonalRight){
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_TRUE(myPawn->moveValid(5,7));
}

TEST(PawnDownwardsMovementTests, moveForwardOne){
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    EXPECT_TRUE(myPawn->moveValid(7,6));
    EXPECT_FALSE(myPawn->moveValid(5,6));
}

TEST(PawnDownwardsMovementTests, moveDiagonalLeft){
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    EXPECT_TRUE(myPawn->moveValid(7,7));
}

TEST(PawnDownwardsMovementTests, moveDiagonalRight){
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    EXPECT_TRUE(myPawn->moveValid(7,5));
}

TEST(PawGeneralMovementTests, movesOffBoard){
    Pawn* myPawn = new Pawn(black, 7, 7, true);
    EXPECT_FALSE(myPawn->moveValid(8,8));
}

TEST(PawnGeneralMovementTests, sidewaysMovement){
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_FALSE(myPawn->moveValid(6,5));
    EXPECT_FALSE(myPawn->moveValid(6,7));
}