#include "gtest/gtest.h"
#include "../header/Pawn.h"

TEST(PawnUpwardsMovementTests, moveForwardOneEmpty){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_TRUE(myPawn->moveValid(5, 6, board));
    EXPECT_FALSE(myPawn->moveValid(7, 6, board));
}

TEST(PawnUpwardsMovementTests, moveForwardOneAlly){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(5, 6)->setPiece(new Knight(black, 5, 6));
    EXPECT_FALSE(myPawn->moveValid(5, 6, board));
    EXPECT_FALSE(myPawn->moveValid(7, 6, board));
}

TEST(PawnUpwardsMovementTests, moveForwardOneEnemy){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(5, 6)->setPiece(new Knight(white, 5, 6));
    EXPECT_FALSE(myPawn->moveValid(5, 6, board));
    EXPECT_FALSE(myPawn->moveValid(7, 6, board));
}

TEST(PawnUpwardsMovementTests, moveForwardTwoEmpty){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_TRUE(myPawn->moveValid(4, 6, board));
}

TEST(PawnUpwardsMovementTests, moveForwardTwoHasMoved){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    myPawn->setMoved();
    EXPECT_FALSE(myPawn->moveValid(4, 6, board));
}

TEST(PawnUpwardsMovementTests, moveForwardTwoAllyEnd){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(4, 6)->setPiece(new Knight(black, 4, 6));
    EXPECT_FALSE(myPawn->moveValid(4, 6, board));
}

TEST(PawnUpwardsMovementTests, moveForwardTwoAllyInWAy){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(5, 6)->setPiece(new Knight(black, 5, 6));
    EXPECT_FALSE(myPawn->moveValid(4, 6, board));
}

TEST(PawnUpwardsMovementTests, moveForwardTwoEnemyEnd){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(4, 6)->setPiece(new Knight(white, 4, 6));
    EXPECT_FALSE(myPawn->moveValid(4, 6, board));
}

TEST(PawnUpwardsMovementTests, moveForwardTwoEnemyInWay){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(5, 6)->setPiece(new Knight(white, 5, 6));
    EXPECT_FALSE(myPawn->moveValid(4, 6, board));
}

TEST(PawnUpwardsMovementTests, moveDiagonalLeftEmpty){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_FALSE(myPawn->moveValid(5, 5, board));
}

TEST(PawnUpwardsMovementTests, moveDiagonalLeftAlly){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(5, 5)->setPiece(new Knight(black, 5, 5));
    EXPECT_FALSE(myPawn->moveValid(5, 5, board));
}

TEST(PawnUpwardsMovementTests, moveDiagonalLeftEnemy){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(5, 5)->setPiece(new Knight(white, 5, 5));
    EXPECT_TRUE(myPawn->moveValid(5, 5, board));
}

TEST(PawnUpwardsMovementTests, moveDiagonalRightEmpty){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_FALSE(myPawn->moveValid(5, 7, board));
}

TEST(PawnUpwardsMovementTests, moveDiagonalRightAlly){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(5, 7)->setPiece(new Knight(black, 5, 7));
    EXPECT_FALSE(myPawn->moveValid(5, 7, board));
}

TEST(PawnUpwardsMovementTests, moveDiagonalRightEnemy){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    board->getSquare(5, 7)->setPiece(new Knight(white, 5, 7));
    EXPECT_TRUE(myPawn->moveValid(5, 7, board));
}

TEST(PawnDownwardsMovementTests, moveForwardOneEmpty){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    EXPECT_TRUE(myPawn->moveValid(7, 6, board));
    EXPECT_FALSE(myPawn->moveValid(5, 6, board));
}

TEST(PawnDownwardsMovementTests, moveForwardOneAlly){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    board->getSquare(7, 6)->setPiece(new Knight(black, 7, 6));
    EXPECT_FALSE(myPawn->moveValid(7, 6, board));
    EXPECT_FALSE(myPawn->moveValid(5, 6, board));
}

TEST(PawnDownwardsMovementTests, moveForwardOneEnemy){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    board->getSquare(7, 6)->setPiece(new Knight(white, 7, 6));
    EXPECT_FALSE(myPawn->moveValid(7, 6, board));
    EXPECT_FALSE(myPawn->moveValid(5, 6, board));
}

TEST(PawnDownwardsMovementTests, moveForwardTwoEmpty){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 4, 4, false);
    EXPECT_TRUE(myPawn->moveValid(6, 4, board));
}

TEST(PawnDownwardsMovementTests, moveForwardTwoHasMoved){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 4, 4, false);
    myPawn->setMoved();
    EXPECT_FALSE(myPawn->moveValid(6, 4, board));
}

TEST(PawnDownwardsMovementTests, moveForwardTwoAllyEnd){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 4, 4, false);
    board->getSquare(6, 4)->setPiece(new Knight(black, 6, 4));
    EXPECT_FALSE(myPawn->moveValid(6, 4, board));
}

TEST(PawnDownwardsMovementTests, moveForwardTwoAllyInWAy){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 4, 4, false);
    board->getSquare(5, 4)->setPiece(new Knight(black, 5, 4));
    EXPECT_FALSE(myPawn->moveValid(6, 4, board));
}

TEST(PawnDownwardsMovementTests, moveForwardTwoEnemyEnd){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 4, 4, false);
    board->getSquare(6, 4)->setPiece(new Knight(white, 6, 4));
    EXPECT_FALSE(myPawn->moveValid(6, 4, board));
}

TEST(PawnDownwardsMovementTests, moveForwardTwoEnemyInWay){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 4, 4, false);
    board->getSquare(5, 4)->setPiece(new Knight(white, 5, 4));
    EXPECT_FALSE(myPawn->moveValid(6, 4, board));
}

TEST(PawnDownwardsMovementTests, moveDiagonalLeftEmpty){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    EXPECT_FALSE(myPawn->moveValid(7, 7, board));
}

TEST(PawnDownwardsMovementTests, moveDiagonalLeftAlly){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    board->getSquare(7, 7)->setPiece(new Knight(black, 7, 7));
    EXPECT_FALSE(myPawn->moveValid(7, 7, board));
}

TEST(PawnDownwardsMovementTests, moveDiagonalLeftEnemy){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    board->getSquare(7, 7)->setPiece(new Knight(white, 7, 7));
    EXPECT_TRUE(myPawn->moveValid(7, 7, board));
}

TEST(PawnDownwardsMovementTests, moveDiagonalRightEmpty){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    EXPECT_FALSE(myPawn->moveValid(7, 5, board));
}

TEST(PawnDownwardsMovementTests, moveDiagonalRightAlly){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    board->getSquare(7, 5)->setPiece(new Knight(black, 7, 5));
    EXPECT_FALSE(myPawn->moveValid(7, 5, board));
}

TEST(PawnDownwardsMovementTests, moveDiagonalRightEnemy){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, false);
    board->getSquare(7, 5)->setPiece(new Knight(white, 7, 5));
    EXPECT_TRUE(myPawn->moveValid(7, 5, board));
}


TEST(PawnGeneralMovementTests, movesOffBoard){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 7, 7, true);
    EXPECT_FALSE(myPawn->moveValid(8, 8, board));
}

TEST(PawnGeneralMovementTests, sidewaysMovement){
    Chessboard* board = new Chessboard();
    Pawn* myPawn = new Pawn(black, 6, 6, true);
    EXPECT_FALSE(myPawn->moveValid(6, 5, board));
    EXPECT_FALSE(myPawn->moveValid(6, 7, board));
}