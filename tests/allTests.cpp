#include "gtest/gtest.h"
#include "pieceTests.h"
#include "specialPieceTests.h"
#include "kingTests.h"
#include "pawnTests.h"
#include "PlayerTests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}