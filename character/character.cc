#include "character.h"
#include "../board/cell.h"
Character::Character(Cell *cell) {
	
}
using namespace std;
char Character::getSymbol() {
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
