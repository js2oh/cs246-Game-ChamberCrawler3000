#include "chamber.h"
#include <iostream>
#include "cellobject.h"

using namespace std;

Chamber::Chamber(int id) : id{id} {
    // Use temp textdisplay for guidance
    TextDisplay td;

    bool irregular = false;

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

    for (int i = 0; i < height; ++i) {
        cells.emplace_back(vector<Cell>{});

        for (int j = 0; j < width; ++j) {
            cells.at(i).emplace_back(Cell{});
            cells.at(i).at(j).setCoords(i + topLeftRow, j + topLeftCol);
            cells.at(i).at(j).setCellObject(CellObject::Empty);
        }
    }

    if (irregular) {
        // cout << "WIDTH: " << width << endl;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                // cout << td.at(i, j);
                if (td.at(i + topLeftRow, j + topLeftCol) != '.' ||
                    (id == 1 && (i >= 4 && j < 22))) {
                    cells.at(i).at(j).setCellObject(CellObject::Wall);
                }
            }
        }
    }
}

Cell &Chamber::genRandPos() {
    bool found = false;
    int col = 0;
    int row = 0;

    do {
        col = rand() % width;
        row = rand() % height;
        cout << "(" << row << ", " << col << ")" << endl;

        found = (cells.at(row).at(col).getOccupied() == CellObject::Empty);
    } while (!found);
    cout << "(" << row << ", " << col << ")" << endl;
    return cells.at(row).at(col);
}

Position Chamber::spawnPlayer() {
    Cell c = genRandPos();
    Position p = c.getPosition();
    c.setCellObject(CellObject::Player);

    return p;
}

Position Chamber::spawnEnemy() {
    EnemyFactory ef;

    Cell c = genRandPos();
    Position p = c.getPosition();

    c.setCellObject(CellObject::Enemy);
    enemies.emplace_back{ef.create(p)};
    return p;
}

Position Chamber::spawnPotion() {
    PotionFactory pf;

    Cell c = genRandPos();
    Position p = c.getPosition();

    c.setCellObject(CellObject::Item);
    potions.emplace_back{pf.spawn(p)};
    return p;
}

Position Chamber::spawnGoldPile() {
    TreasureFactory tf;

    Cell c = genRandPos();
    Position p = c.getPosition();

    c.setCellObject(CellObject::Item);
    potions.emplace_back{tf.spawn(p)};
    return p;
}

Position Chamber::spawnStairs() {
    Cell c = genRandPos();
    c.setCellObject(CellObject::Stairs);
    return c.getPosition();
}
