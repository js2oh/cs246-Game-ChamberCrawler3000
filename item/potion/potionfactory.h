#ifndef POTIONFACTORY_H
#define POTIONFACTORY_H
#include <memory>
#include <string>
#include "../item.h"
#include "../itemfactory.h"

class Cell;
class Potion;
class Player;
class Item;

class PotionFactory : public ItemFactory {
    public:
    std::shared_ptr<Item> create(char symbol, Cell *c);
    std::shared_ptr<Item> createItem(ItemType it, Cell *c) override;
};

#endif /* POTIONFACTORY_H */
