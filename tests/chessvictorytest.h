#include "gtest/gtest.h"
#include "../header/chessvictory.h"
using namespace std;

TEST(ChessVictoryTests, printVictoryScreen) {
    // Capture standard output
    testing::internal::CaptureStdout();

    displayVictoryScreen();

    // Get the captured output
    string output = testing::internal::GetCapturedStdout();

    string expectedOutput =
        "*************************************\n"
        "*        Congratulations!           *\n"
        "*        You've Won the Game!       *\n"
        "*************************************\n";

    EXPECT_EQ(output, expectedOutput);
}