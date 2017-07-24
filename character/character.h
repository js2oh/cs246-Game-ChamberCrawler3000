#ifndef CHARACTER_H
#define CHARACTER_H
#include "../board/position.h"
class Cell;
class Character {

	public:
	char getSymbol();
    void setCell(Cell *cell);
    Cell *getCell() const;
    Position getPosition() const;
	Character(Cell *cell);
	
	protected:
	char symbol;
	Cell *cell;

    // const int maxHp;
    int hp;
    int def;
    int atk;
};

#endif /* CHARACTER_H */
