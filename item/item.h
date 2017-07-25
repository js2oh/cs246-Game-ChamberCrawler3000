#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <string>
#include "../board/position.h"
#include "itemtype.h"

class Cell;
class Player;

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
    void use(std::shared_ptr<Player> p);
    virtual void applyEffects(std::shared_ptr<Player> p) = 0;

    private:
    
    protected:
    Cell *cell;
    char symbol;
};

#endif /* ITEM_H */
