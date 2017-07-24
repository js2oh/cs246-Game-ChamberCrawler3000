#ifndef ITEM_H
#define ITEM_H

#include "itemtype.h"
#include <string>
#include "../board/position.h"


class Cell;



class Item {
	public:
	
	virtual ~Item() = 0;
	//Item (ItemType it, Position pos);
	Item (ItemType it);
	char type;
	//Position pos;
	void use();
	Cell *parentCell;
	
	private:
	
	virtual void applyEffects() = 0;
};

#endif /* ITEM_H */
