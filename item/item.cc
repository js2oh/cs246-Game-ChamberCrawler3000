#include "item.h"

Item::Item (ItemType it):
	type(it) {}



void Item::use() {
	applyEffects();
	//parentCell->useItem();

}

