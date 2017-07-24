#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include <memory>
#include "item.h"

class Item;

class ItemFactory {
    public:
    // ItemFactory();
    // std::unique_ptr <Item> createItem(ItemType it);
    Item *createItem(ItemType it);
};

#endif /* ITEMFACTORY_H */
