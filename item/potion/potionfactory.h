#ifndef POTIONFACTORY_H
#define POTIONFACTORY_H
#include <memory>
#include <string>
#include "../item.h"
#include "../itemfactory.h"
#include "boostatk.h"
#include "boostdef.h"
#include "poison.h"
#include "restore.h"
#include "temp.h"
#include "woundatk.h"
#include "wounddef.h"

class Cell;
class Potion;
class Player;
class Item;

class PotionFactory : public ItemFactory {
    const static int POTION_TYPES;
    ItemType genRandType();

    public:
    std::shared_ptr<Potion> manualCreate(char symbol, Cell *c);
    std::shared_ptr<Potion> randomCreate(Cell *c);
};

#endif /* POTIONFACTORY_H */
