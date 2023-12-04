#include "gtest/gtest.h"
#include "chessboardtest.h"
#include "squarestest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}