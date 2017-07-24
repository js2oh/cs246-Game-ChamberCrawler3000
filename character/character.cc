#include "character.h"
#include "../board/cell.h"

using namespace std;

// Character::Character(Cell *cell) : cell{cell} {}

Character::Character(Cell *cell, char symbol) : cell{cell}, symbol{symbol} {}

Character::~Character() {}

char Character::getSymbol() const {
    return symbol;
}

void Character::setCell(Cell *cell) {
    this->cell = cell;
}

Cell *Character::getCell() const {
    return this->cell;
}

Position Character::getPosition() const {
    return cell->getPosition();
}

