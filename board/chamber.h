#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>
#include "../character/enemy/enemy.h"
#include "../item/potion/potion.h"
#include "../item/treasure/gold.h"
#include "cell.h"
#include "floor.h"
#include "position.h"

class Cell;
class Floor;

class Chamber {
    Floor *floor;
    int id, topLeftCol, topLeftRow, height, width;

    std::vector<Enemy *> enemies;
    std::vector<Potion *> potions;
    std::vector<Gold *> treasures;

    public:
    Chamber(int i, Floor *floor);
    void addEnemy(Enemy *e);
    void addPotion(Potion *p);
    void addGold(Gold *g);
    Cell &genRandPos();
    int getId() const;
    static int getMatchingId(Position p);
    static int getMatchingId(int row, int col);
    bool isInBounds(int row, int col) const;

    Cell &spawnPlayer();
    Cell &spawnEnemy();
    Cell &spawnGoldPile();
    Cell &spawnPotion();
    Cell &spawnStairs();
};

#endif /* CHAMBER_H */
