#include "player.h"

using namespace std;

Player::Player(Cell *cell) : cell{cell} {}

void Player::setCell(Cell *cell) {
    this->cell = cell;
}

Cell *Player::getCell() const {
    return this->cell;
}

Position Player::getPosition() const {
    return cell->getPosition();
}
