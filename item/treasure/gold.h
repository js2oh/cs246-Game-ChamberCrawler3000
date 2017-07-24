#ifndef GOLD_H
#define GOLD_H
#include "../item.h"

class Gold:Item {
	public:
	Gold(int value);
	
	int value;
	ItemType it;
	
};

#endif /* GOLD_H */
