#include "gtest/gtest.h"
#include "chesswelcometest.h"
#include "chessvictorytest.h"
#include "PlayerTests.h"
#include "chessboardtest.h"
#include "squarestest.h"
#include "pieceTests.h"
#include "specialPieceTests.h"
#include "kingTests.h"
#include "queenTests.h"
#include "pawnTests.h"
#include "KnightTests.h"
#include "PlayerTests.h"
#include "displaychessboardtest.h"
#include "rookTests.h"
#include "bishopTests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}