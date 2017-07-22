#ifndef ITEM_H
#define ITEM_H

#include "itemtype.h"
#include <string>
#include "../board/position.h"

//#include "../board/cell.h"
class Cell;



class Item {
	public:
	
	~Item() = 0;
	Item (ItemType tpe, Position pos);
	char type;
	Position pos;
	void use();
	
	
	private:
	Cell *parentCell;
	virtual void applyEffects() = 0;
};

#endif /* ITEM_H */
