#ifndef CHAMBER_H
#define CHAMBER_H

#include "cell.h"
#include "floor.h"
#include "position.h"
#include "../character/enemy/enemy.h"
#include "../item/potion/potion.h"
#include "../item/treasure/gold.h"
#include <vector>

class Floor;

class Chamber {
    std::vector<Enemy *> enemies;
    std::vector<Potion *> potions;
    std::vector<Gold *> treasures;
    Floor *floor;

    int id, topLeftCol, topLeftRow, height, width;

    public:
    Chamber(int i, Floor *floor);
    Cell &genRandPos();
    Cell &spawnPlayer();
    Cell &spawnEnemy();
    Cell &spawnGoldPile();
    Cell &spawnPotion();
    Cell &spawnStairs();
    bool isInBounds(int row, int col) const;
};

#endif /* CHAMBER_H */
