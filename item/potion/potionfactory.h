#ifndef POTIONFACTORY_H
#define POTIONFACTORY_H
#include <memory>
#include <string>

class Cell;
class Potion;
class Player;
class Item;

class PotionFactory {
    public:
    Item *create(char symbol, std::shared_ptr<Player> p, Cell *c);
};

#endif /* POTIONFACTORY_H */
