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
    const static int POTION_TYPES;
    ItemType genRandType();

    public:
    std::shared_ptr<Item> manualCreate(char symbol, Cell *c);
    std::shared_ptr<Item> randomCreate(Cell *c);
};

#endif /* POTIONFACTORY_H */
