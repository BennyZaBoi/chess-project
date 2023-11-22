#include "Player.h"

Player::Player(): name(""), firstMove(true), colorChoice('w') {}

Player::Player(const string playername): name(playername), firstMove(true), colorChoice('w') {}

void Player::setName(string newname) {
    name = newname;
}

void Player::setFirstMove(bool tf) {
    firstMove = tf;
}

void Player::setColorChoice(char z) {
    colorChoice = z;
}

string Player::returnName() {
    return name;
}

int Player::returnFirstMove() {
    if (firstMove == true) {
        return true;
    }
    return false;
}

char Player::returnColorChoice() {
    return colorChoice;
}