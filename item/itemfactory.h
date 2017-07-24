#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include <memory>
#include "itemtype.h"
class Item;

class ItemFactory {
	public:
	//std::unique_ptr <Item> createItem(ItemType it);
	Item *createItem(ItemType it);
};


#endif /* ITEMFACTORY_H */
