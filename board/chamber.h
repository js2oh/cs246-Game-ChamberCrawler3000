#ifndef CHAMBER_H
#define CHAMBER_H

#include "cell.h"
#include "position.h"
#include "../character/enemy/enemy.h"
#include "../item/potion/potion.h"
#include "../item/treasure/gold.h"
#include <vector>

class Chamber {
    std::vector<std::vector<Cell>> cells;

    std::vector<Enemy *> enemies;
    std::vector<Potion *> potions;
    std::vector<Gold *> treasures;

    int id, topLeftCol, topLeftRow, height, width;

    public:
    Chamber(int i);
    Cell &genRandPos();
    Position spawnPlayer();
    Position spawnEnemy();
    Position spawnGoldPile();
    Position spawnPotion();
    Position spawnStairs();
};

#endif /* CHAMBER_H */
