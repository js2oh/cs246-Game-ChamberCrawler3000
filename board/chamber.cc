#include "chamber.h"
#include <iostream>
#include "cellobject.h"

using namespace std;

Chamber::Chamber(int id, Floor *floor) : id{id}, floor{floor} {
    /*
        Assign appropriate chamber dimensions

        Each chamber is represented as rectangular blocks, even though some may
        have irregular shapes. Because of this simplification, chamber 1 (top
        right) overlaps with chamber 4 (centre). These overlaps are all handled
        appropriately.
    */

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
            break;
        // Bottom right
        case 2:
            topLeftCol = 37;
            topLeftRow = 16;
            height = 6;
            width = 39;
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

// Methods for adding object pointer to corresponding vectors
void Chamber::addEnemy(Enemy *e) {
    enemies.emplace_back(e);
}
void Chamber::addPotion(Potion *p) {
    potions.emplace_back(p);
}
void Chamber::addGold(Gold *g) {
    treasures.emplace_back(g);
}

// isInBounds returns true if the provided row and column lies within the
// chamber.
bool Chamber::isInBounds(const int row, const int col) const {
    // Handle irregular-shaped chambers

    // Top right chamber, check position does not lie within the centre chamber
    if (id == 1) {
        return !(row >= 4 + topLeftRow && col < 22 + topLeftCol);
    }
    // Bottom right chamber, check it does not lie outside of chamber
    else if (id == 2) {
        return !(row < 3 + topLeftRow && col < 28 + topLeftCol);
    }
    // Rectangular-shaped chambers
    else {
        return (row >= topLeftRow && row < topLeftRow + height) &&
               (col >= topLeftCol && col < topLeftCol + width);
    }
}

// genRandPos randomnly returns an unoccupied Cell in the current chamber
Cell &Chamber::genRandPos() {
    int col = 0;
    int row = 0;

    // Keep generating positions until a vacant position is found
    while (true) {
        col = rand() % width + topLeftCol;
        row = rand() % height + topLeftRow;

        // Found vacant position
        if (isInBounds(row, col) && floor->vacantAt(row, col)) {
            break;
        }
    }
    return floor->cellAt(row, col);
}

int Chamber::getId() const {
    return id;
}

// getMatchingId are static methods for determining which chamber (0-4) the
// provided position is supposed to be in.
int Chamber::getMatchingId(int row, int col) {
    // Centre chamber (checked first because overlaps with rectangle covered by
    // top right chamber 1)
    if (row >= 10 && row <= 12 && col >= 38 && col <= 49) {
        return 4;
    }
    // Bottom left chamber
    else if (row >= 15 && row <= 21 && col >= 4 && col <= 24) {
        return 3;
    }
    // Bottom right chamber
    else if (row >= 16 && row <= 21 && col >= 37 && col <= 75) {
        return 2;
    }
    // Top left chamber
    else if (row >= 3 && row <= 6 && col >= 3 && col <= 28) {
        return 0;
    }
    // Top right chamber
    else if (row >= 3 && row <= 12 && col >= 39 && col <= 75) {
        return 1;
    }
    // Neither chambers
    else {
        return -1;
    }
}

int Chamber::getMatchingId(Position p) {
    return getMatchingId(p.row, p.col);
}

// Spawn methods:
// Player
Cell &Chamber::spawnPlayer() {
    // Get randomly-selected Cell and update its symbol and information
    Cell &c = genRandPos();
    c.setCellObject(CellObject::Player);
    c.setCellSymbol('@');
    // Notify TextDisplay so that it updates
    c.notify();
    return c;
}

// Enemy
Cell &Chamber::spawnEnemy() {
    Cell &c = genRandPos();
    // Use EnemyFactory to randomly generate type of Enemy
    // EnemyFactory ef;
    // enemies.emplace_back(ef.create(c));
    c.setCellObject(CellObject::Enemy);
    c.setCellSymbol('E');
    c.notify();
    return c;
}

// Potion
Cell &Chamber::spawnPotion() {
    Cell &c = genRandPos();
    // Use EnemyFactory to randomly generate type of Potion
    // PotionFactory pf;

    // potions.emplace_back(pf.spawn(c));
    c.setCellObject(CellObject::Item);
    c.setCellSymbol('P');
    c.notify();
    return c;
}

// Gold (Treasure)
Cell &Chamber::spawnGoldPile() {
    Cell &c = genRandPos();
    // Use EnemyFactory to randomly generate type of Treasure
    // TreasureFactory tf;
    // potions.emplace_back(tf.spawn(c));
    c.setCellObject(CellObject::Item);
    c.setCellSymbol('G');
    c.notify();

    return c;
}

// Stairs
Cell &Chamber::spawnStairs() {
    Cell &c = genRandPos();
    c.setCellObject(CellObject::Stairs);
    c.setCellSymbol('\\');
    c.notify();
    return c;
}
