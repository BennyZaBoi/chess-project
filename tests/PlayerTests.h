#include "gtest/gtest.h"
#include "../source/Player.cpp"

TEST(PlayerTests, defaultConstructorTest) {
    Player p1;
    EXPECT_EQ("", p1.returnName());
    EXPECT_EQ(true, p1.returnFirstMove());
    EXPECT_EQ(white, p1.returnColorChoice());
}

TEST(PlayerTests, nameConstructorTest) {
    Player p1("Jimmy");
    EXPECT_EQ("Jimmy", p1.returnName());
    EXPECT_EQ(true, p1.returnFirstMove());
    EXPECT_EQ(white, p1.returnColorChoice());
}

TEST(PlayerTests, boolConstructorTest) {
    Player p1;
    EXPECT_EQ("", p1.returnName());
    EXPECT_FALSE(p1.returnFirstMove() == false);
    EXPECT_EQ(white, p1.returnColorChoice());
}

TEST(PlayerTests, nameTest) {
    Player p1;
    p1.setName("Smith");
    EXPECT_EQ("Smith", p1.returnName());
}

TEST(PlayerTests, firstMoveTest) {
    Player p1;
    p1.setFirstMove(false);
    EXPECT_EQ(false, p1.returnFirstMove());
}

TEST(PlayerTests, colorChoiceTest) {
    Player p1;
    p1.setColorChoice(blue);
    EXPECT_EQ(Color::blue, p1.returnColorChoice());
}