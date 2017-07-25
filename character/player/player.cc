#include "player.h"

const char Player::SYMBOL = '@';

Player::Player():Character(SYMBOL){}
Player::Player(Cell *cell) : Character{cell, SYMBOL} {}
std::string Player::getRace() {
	return race;
}