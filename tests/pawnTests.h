#include "gtest/gtest.h"
#include "../header/Pawn.h"

TEST(PawnMovementTests, downwardPawnMove){
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_TRUE(myPawn->moveValid(5,6));
    EXPECT_FALSE(myPawn->moveValid(7,6));
}

TEST(PawnMovementTests, pawnMovesDownwards){
    Pawn* myPawn = new Pawn(black, 1, 1, false);
    EXPECT_TRUE(myPawn->moveValid(2,1));
    EXPECT_FALSE(myPawn->moveValid(0,1));
}

TEST(PawnMovementTests, pawnMovesOffBoard){
    Pawn* myPawn = new Pawn(black, 7, 7, true);
    EXPECT_FALSE(myPawn->moveValid(8,8));
}

TEST(PawnMovementTests, sidewaysPawnMove){
    Pawn* myPawn = new Pawn(black, 7, 7, true);
    EXPECT_FALSE(myPawn->moveValid(7,6));
}

TEST(PawnMovementTests, doublePawnMove){
    Pawn* myPawn = new Pawn(black, 7, 7, true);
    EXPECT_TRUE(myPawn->moveValid(5,7));
}

TEST(PawnMovementTests, doublePawnMoveInvalid){
    Pawn* myPawn = new Pawn(black, 7, 7, true);
    myPawn->setMoved();
    EXPECT_FALSE(myPawn->moveValid(5,7));
}