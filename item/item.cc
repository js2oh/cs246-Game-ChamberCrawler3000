#include "item.h"

using namespace std;

Item::Item() {}
Item::Item(char symbol) : symbol{symbol} {}
Item::~Item() {}
Item::Item(ItemType it) : type(it) {}

void Item::use(shared_ptr<Player> p) {
    applyEffects(p);
}

char Item::getSymbol() const {
    return symbol;
}
