#include "player.h"

const char Player::SYMBOL = '@';

Player::Player(Cell *cell) : Character{cell, SYMBOL} {
    hp = 10;
}
