#include "gtest/gtest.h"
#include "chessboardtest.h"
#include "squarestest.h"
#include "pieceTests.h"
#include "specialPieceTests.h"
#include "kingTests.h"
#include "pawnTests.h"
#include "KnightTests.h"
#include "PlayerTests.h"
#include "chesswelcometest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}