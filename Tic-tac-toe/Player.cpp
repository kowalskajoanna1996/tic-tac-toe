#include <iostream>

#include "Player.h"

Player::Player() { }

Player::Player(char sign) {
	Player::setSign(sign);
}

void Player::setSign(char sign) {
	Player::sign = sign;
}

char Player::getSign() {
	return sign;
}