#include "../header/Player.h"

Player::Player(): name(""), firstMove(true), playColor(white) {}

Player::Player(const string& playername): name(playername), firstMove(true), playColor(white) {}

void Player::setName(string& newname) {
    name = newname;
}

void Player::setFirstMove(bool tf) {
    firstMove = tf;
}

void Player::setColorChoice(Color c) {
    playColor = c;
}

string Player::returnName() const {
    return name;
}

bool Player::returnFirstMove() const {
    if (firstMove == true) {
        return true;
    }
    return false;
}

Color Player::returnColorChoice() const {
    return playColor;
}