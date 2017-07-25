#ifndef GOLD_H
#define GOLD_H
#include "../item.h"
#include "../itemtype.h"
class Gold:Item {
	public:
	Gold(int value);
	Gold(ItemType it, Cell *cell);
	int value;
	ItemType it;
	
};

#endif /* GOLD_H */
