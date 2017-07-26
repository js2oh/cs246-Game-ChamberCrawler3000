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
    std::shared_ptr<Enemy> manualCreate(char symbol, Cell *c);
    std::shared_ptr<Enemy> randomCreate(Cell *c);
};

#endif /* ENEMYFACTORY_H */
