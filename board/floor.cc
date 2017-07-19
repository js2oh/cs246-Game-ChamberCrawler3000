#include <iostream>
#include "floor.h"
#include <cstdlib>

using namespace std;

// TODO Read input from pre-configured board file

const int Floor::WIDTH = 79;
const int Floor::HEIGHT = 25;
const int Floor::CHAMBER_COUNT = 5;

Floor::Floor(string boardFile)
    : boardFile{boardFile},
      isHostileMerchants{false},
      pcSpawned{false},
      grid{HEIGHT, vector<Cell>{WIDTH}} {
    init();
}

Floor::~Floor() {
    delete td;
}

void Floor::clearGrid() {
    delete td;

    // Clear each 'row' in grid
    for (int i = 0; i < WIDTH; ++i) {
        grid[i].clear();
    }
}

void Floor::init() {
    td = new TextDisplay{WIDTH, HEIGHT, boardFile};

    for (int i = 0; i < CHAMBER_COUNT; ++i) {
        chambers.emplace_back(Chamber{i, this});
    }

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j].setCoords(i, j);
            grid[i][j].setTd(td);

            char symbol = td->at(i, j);
            if (symbol == '+' || symbol == '#' || symbol == '.') {
                grid[i][j].setCellObject(CellObject::Empty);
            }
            else if (symbol == '|' || symbol == '-' || symbol == ' ') {
                grid[i][j].setCellObject(CellObject::Wall);
            }
        }
    }

    if (boardFile == "empty.txt") {
        spawn();
    }
    else {
        // manualSpawn();
    }
}

ostream &operator<<(ostream &out, const Floor &g) {
    out << *(g.td);
    return out;
}

void Floor::spawnPlayer(string race) {
    const int i = rand() % CHAMBER_COUNT;
    pcSpawnChamber = i;
    pcSpawned = true;

    Cell &c = chambers.at(i).spawnPlayer();
    c.setCellObject(CellObject::Player);
    c.setCellSymbol('@');
    c.notify();

    /*
        if (race == "shade") {
            player = new Shade{c};
        }
        else if (race == "drow") {
            player = new Drow{c};
        }
        else if (race == "goblin") {
            player = new Goblin{c};
        }
        else if (race == "troll") {
            player = new Troll{c};
        }
        */
}

void Floor::spawnEnemies() {
    for (int j = 0; j < 20; ++j) {
        const int i = rand() % CHAMBER_COUNT;

        Cell &c = chambers.at(i).spawnEnemy();

        c.setCellObject(CellObject::Enemy);
        c.setCellSymbol('E');
        c.notify();
    }
}

void Floor::spawnPotions() {
    for (int j = 0; j < 10; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        Cell &c = chambers.at(i).spawnPotion();

        c.setCellObject(CellObject::Item);
        c.setCellSymbol('P');
        c.notify();
    }
}

void Floor::spawnGoldPiles() {
    for (int j = 0; j < 10; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        Cell &c = chambers.at(i).spawnGoldPile();

        c.setCellObject(CellObject::Item);
        c.setCellSymbol('G');
        c.notify();
    }
}

void Floor::spawnStairs() {
    while (true) {
        int i = rand() % CHAMBER_COUNT;
        if ((pcSpawned && pcSpawnChamber == i)) {
            continue;
        }
        else {
            Cell &c = chambers.at(i).spawnStairs();
            c.setCellObject(CellObject::Stairs);
            c.setCellSymbol('/');
            c.notify();
            break;
        }
    }
}

void Floor::spawn(string race) {
    spawnPlayer(race);
    spawnEnemies();
    spawnGoldPiles();
    spawnPotions();
    spawnStairs();
}

bool Floor::vacantAt(int row, int col) const {
    return grid.at(row).at(col).getOccupied() == CellObject::Empty;
}

Cell &Floor::getCell(int row, int col) {
    return grid.at(row).at(col);
}
