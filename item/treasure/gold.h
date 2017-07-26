#ifndef GOLD_H
#define GOLD_H
#include "../item.h"
#include "../itemtype.h"
class Gold: public Item {
	public:
	Gold(int value);
	Gold(ItemType it, Cell *cell);
	int value;
	ItemType it;
	void applyEffects(std::shared_ptr <Player> p);

};


#endif /* GOLD_H */
