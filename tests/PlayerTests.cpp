#include "gtest/gtest.h"
#include "../Player/Player.cpp"

TEST(PlayerTests, defaultConstructorTest) {
    Player p1;
    EXPECT_EQ("", p1.returnName());
    EXPECT_EQ(true, p1.returnFirstMove());
    EXPECT_EQ('w', p1.returnColorChoice());
}

TEST(PlayerTests, nameConstructorTest) {
    Player p1("Jimmy");
    EXPECT_EQ("Jimmy", p1.returnName());
    EXPECT_EQ(true, p1.returnFirstMove());
    EXPECT_EQ('w', p1.returnColorChoice());
}

TEST(PlayerTests, boolConstructorTest) {
    Player p1;
    EXPECT_EQ("", p1.returnName());
    EXPECT_FALSE(p1.returnFirstMove() == 1);
    EXPECT_EQ('w', p1.returnColorChoice());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}