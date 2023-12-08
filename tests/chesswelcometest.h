#include "gtest/gtest.h"
#include "../header/chesswelcome.h"
using namespace std;

TEST(ChessWelcomeTest, printWelcomeScreen) {
    // Capture standard output
    testing::internal::CaptureStdout();

    printWelcomeScreen();

    // Get the captured output
    string output = testing::internal::GetCapturedStdout();

    string expectedOutput =
         "*************************************\n" 
         "*      Welcome to UCR Chess!       *\n" 
         "*************************************\n" 
         "*          1. Start Game            *\n" 
         "*          2. Instructions          *\n" 
         "*          3. Exit                  *\n" 
         "*************************************\n"; 


         expectedOutput += '\n'; //added this because I forgot I had a endl at the end for welcome

    EXPECT_EQ(output, expectedOutput);
}