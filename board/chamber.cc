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
    return floor->cellAt(row, col);
}

Cell &Chamber::spawnPlayer() {
    return genRandPos();
}

Cell &Chamber::spawnEnemy() {
    Cell &c = genRandPos();
    // EnemyFactory ef;

    // enemies.emplace_back(ef.create(c));
    c.setCellObject(CellObject::Enemy);
    c.setCellSymbol('E');
    c.notify();
    return c;
}

Cell &Chamber::spawnPotion() {
    Cell &c = genRandPos();
    // PotionFactory pf;

    // potions.emplace_back(pf.spawn(c));
    c.setCellObject(CellObject::Item);
    c.setCellSymbol('P');
    c.notify();
    return c;
}

Cell &Chamber::spawnGoldPile() {
    Cell &c = genRandPos();
    // TreasureFactory tf;
    // potions.emplace_back(tf.spawn(c));
    c.setCellObject(CellObject::Item);
    c.setCellSymbol('G');
    c.notify();

    return c;
}

Cell &Chamber::spawnStairs() {
    Cell &c = genRandPos();
    c.setCellObject(CellObject::Stairs);
    c.setCellSymbol('\\');
    c.notify();
    return c;
}

Cell &Chamber::manualSpawn(char symbol, Position p) {
    cout << "Spawned: " << symbol << " at " << p << endl;
    // EnemyFactory ef;
    // PotionFactory pf;
    // TreasureFactory tf;
    Cell &c = floor->cellAt(p);

    switch (symbol) {
        case '@': // Player
            break;
        case 'H':
        case 'W':
        case 'E':
        case 'O':
        case 'M':
        case 'D':
        case 'L':
            // ef.create(symbol, p);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            // pf.create(symbol, p);
            break;
        case '6':
        case '7':
        case '8':
        case '9':
            // tf.create(symbol, p);
            break;
        case '\\':
            c.setCellObject(CellObject::Stairs);
            c.setCellSymbol('\\');
            break;
    }
    return c;
}

int Chamber::getId(Position p) {
    if (p.row >= 10 && p.row <= 12 && p.col >= 38 && p.col <= 49) {
        return 4;
    }
    else if (p.row >= 15 && p.row <= 21 && p.col >= 4 && p.col <= 24) {
        return 3;
    }
    else if (p.row >= 16 && p.row <= 21 && p.col >= 37 && p.col <= 75) {
        return 2;
    }
    else if (p.row >= 3 && p.row <= 6 && p.col >= 3 && p.col <= 28) {
        return 0;
    }
    else if (p.row >= 3 && p.row <= 12 && p.col >= 39 && p.col <= 75) {
        return 1;
    }
    else {
        return -1;
    }
}
