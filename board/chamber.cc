#include "chamber.h"
#include <iostream>
#include "cellobject.h"

using namespace std;

Chamber::Chamber(int id, Floor *floor) : id{id}, floor{floor} {
    switch (id) {
        // Top left
        case 0:
            topLeftCol = 3;
            topLeftRow = 3;
            height = 4;
            width = 26;
            break;
        // Top right
        case 1:
            topLeftCol = 39;
            topLeftRow = 3;
            height = 10;
            width = 37;
            irregular = true;
            break;
        // Bottom right
        case 2:
            topLeftCol = 37;
            topLeftRow = 16;
            height = 6;
            width = 39;
            irregular = true;
            break;
        // Bottom left
        case 3:
            topLeftCol = 4;
            topLeftRow = 15;
            height = 7;
            width = 21;
            break;
        // Middle
        default:
            topLeftCol = 38;
            topLeftRow = 10;
            height = 3;
            width = 12;
            break;
    }
}

bool Chamber::isInBounds(const int row, const int col) const {
    if (id == 1) {
        return !(row >= 4 + topLeftRow && col < 22 + topLeftCol);
    }
    else if (id == 2) {
        return !(row < 3 + topLeftRow && col < 28 + topLeftCol);
    }
    else {
        return (row >= topLeftRow && row < topLeftRow + height) &&
               (col >= topLeftCol && col < topLeftCol + width);
    }
}

Cell &Chamber::genRandPos() {
    bool found = false;
    int col = 0;
    int row = 0;

    while (true) {
        col = rand() % width + topLeftCol;
        row = rand() % height + topLeftRow;

        if (isInBounds(row, col) && floor->vacantAt(row, col)) {
            break;
        }
    }
    return floor->getCell(row, col);
}

Cell &Chamber::spawnPlayer() {
    return genRandPos();
}

Cell &Chamber::spawnEnemy() {
    Cell &c = genRandPos();
    // EnemyFactory ef;

    // enemies.emplace_back(ef.create(c));
    return c;
}

Cell &Chamber::spawnPotion() {
    Cell &c = genRandPos();
    // PotionFactory pf;

    // potions.emplace_back(pf.spawn(c));
    return c;
}

Cell &Chamber::spawnGoldPile() {
    Cell &c = genRandPos();
    // TreasureFactory tf;

    // potions.emplace_back(tf.spawn(c));
    return c;
}

Cell &Chamber::spawnStairs() {
    Cell &c = genRandPos();
    return c;
}
