#ifndef CHAMBER_H
#define CHAMBER_H

#include "cell.h"
#include "position.h"
#include <vector>

class Chamber {
    std::vector<std::vector<Cell>> cells;
    int i, topLeftCol, topLeftRow, height, width;

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
