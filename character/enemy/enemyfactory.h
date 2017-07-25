#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <memory>
#include <string>
#include "enemy.h"
#include "enemyfactory.h"

class Enemy;

class EnemyFactory {
    const static int PROB_DENOM;
    char genRandType();

    public:
    std::shared_ptr<Character> manualCreate(char symbol, Cell *c);
    std::shared_ptr<Character> randomCreate(Cell *c);
};

#endif /* ENEMYFACTORY_H */
