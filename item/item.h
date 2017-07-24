#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "../board/position.h"
#include "itemtype.h"

class Cell;

class Item {
    public:
    Item();
    virtual ~Item() = 0;
    // Item (ItemType it, Position pos);
    Item(ItemType it);
    char type;
    // Position pos;
    void use();
    Cell *parentCell;

    private:
    virtual void applyEffects() = 0;
};

#endif /* ITEM_H */
