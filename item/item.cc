#include "item.h"

Item::Item() {}
Item::~Item() {}
Item::Item(ItemType it) : type(it) {}

void Item::use() {
    applyEffects();
}

char Item::getSymbol() const {
    return symbol;
}
