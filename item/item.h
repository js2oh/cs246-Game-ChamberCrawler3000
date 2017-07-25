#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "../board/position.h"
#include "itemtype.h"

class Cell;

class Item {
    public:
    Item();
    Item(ItemType it);

    Item(char symbol);
    Item(Cell *cell, char symbol);

    virtual ~Item() = 0;

    char getSymbol() const;

    char type;
    // Position pos;
    void use();

    private:
    virtual void applyEffects() = 0;

    protected:
    Cell *cell;
    char symbol;
};

#endif /* ITEM_H */
