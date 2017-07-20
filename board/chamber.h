#ifndef CHAMBER_H
#define CHAMBER_H
#include <vector>
#include "../character/enemy/enemy.h"
#include "../item/potion/potion.h"
#include "../item/treasure/gold.h"
#include "cell.h"
#include "chamberloc.h"
#include "floor.h"
#include "position.h"

class Cell;
class Floor;

class Chamber {
    ChamberLoc loc;
    Floor *floor;
    int topLeftCol, topLeftRow, height, width;

    std::vector<Enemy *> enemies;
    std::vector<Potion *> potions;
    std::vector<Gold *> treasures;

    public:
    Chamber();
    Chamber(ChamberLoc loc, Floor *floor);
    void addEnemy(Enemy *e);
    void addPotion(Potion *p);
    void addGold(Gold *g);
    Cell &genRandPos();
    ChamberLoc getLoc() const;
    static ChamberLoc getMatchingLoc(int row, int col);
    static ChamberLoc getMatchingLoc(Position p);
    bool isInBounds(int row, int col) const;

    Cell &spawnPlayer();
    Cell &spawnEnemy();
    Cell &spawnGoldPile();
    Cell &spawnPotion();
    Cell &spawnStairs();
};

#endif /* CHAMBER_H */
