#include "chamber.h"
#include <iostream>
#include "cellobject.h"

using namespace std;

Chamber::Chamber(int i) : i{i} {
    // Use temp textdisplay for guidance
    TextDisplay td;

    bool irregular = false;

    switch (i) {
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
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (td.at(i, j) != '.' || (i == 3 && (i >= 10 && j <= 61))) {
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

        found = (cells.at(row).at(col).getOccupied() == CellObject::Empty);
    } while (!found);

    cout << "id: " << i << ", " << col << ", " << row << endl;
    return cells.at(row).at(col);
}

Position Chamber::spawnPlayer() {
    Cell c = genRandPos();
    c.setCellObject(CellObject::Player);
    return c.getPosition();
}

Position Chamber::spawnEnemy() {
    Cell c = genRandPos();
    c.setCellObject(CellObject::Enemy);
    return c.getPosition();
}

Position Chamber::spawnPotion() {
    Cell c = genRandPos();
    c.setCellObject(CellObject::Item);
    return c.getPosition();
}

Position Chamber::spawnGoldPile() {
    Cell c = genRandPos();
    c.setCellObject(CellObject::Item);
    return c.getPosition();
}

Position Chamber::spawnStairs() {
    Cell c = genRandPos();
    c.setCellObject(CellObject::Stairs);
    return c.getPosition();
}
