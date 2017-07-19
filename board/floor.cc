#include <iostream>
#include "floor.h"
#include <cstdlib>

using namespace std;

// TODO Read input from pre-configured board file

const int Floor::WIDTH = 79;
const int Floor::HEIGHT = 25;
const int Floor::CHAMBER_COUNT = 5;
const int Floor::MAX_LEVEL = 5;

Floor::Floor(int level, string boardFile)
    : level{level},
      boardFile{boardFile},
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
        manualSpawn();
    }
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
    }
}

void Floor::spawnPotions() {
    for (int j = 0; j < 10; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        Cell &c = chambers.at(i).spawnPotion();
    }
}

void Floor::spawnGoldPiles() {
    for (int j = 0; j < 10; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        Cell &c = chambers.at(i).spawnGoldPile();
    }
}

void Floor::spawnStairs() {
    while (true) {
        int i = rand() % CHAMBER_COUNT;

        if (!pcSpawned || pcSpawnChamber != i) {
            Cell &c = chambers.at(i).spawnStairs();
            break;
        }
    }
}

void Floor::spawn(string race) {
    spawnPlayer(race);
    spawnEnemies();
    spawnGoldPiles();
    spawnPotions();

    if (level != MAX_LEVEL) {
        spawnStairs();
    }
}

int Floor::getChamberId(Position p) {
    return Chamber::getId(p);
}

void Floor::manualSpawn(string race) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            Position p{i, j};

            if (td->at(p) != '-' && td->at(p) != '|' && td->at(p) != ' ' &&
                td->at(p) != '+' && td->at(p) != '#' && td->at(p) != '.') {
                const int id = getChamberId(p);

                chambers.at(id).manualSpawn(td->at(p), p);
            }
        }
    }
}

bool Floor::vacantAt(int row, int col) const {
    return grid.at(row).at(col).getOccupied() == CellObject::Empty;
}

Cell &Floor::cellAt(int row, int col) {
    return grid.at(row).at(col);
}

Cell &Floor::cellAt(Position p) {
    return cellAt(p.row, p.col);
}

ostream &operator<<(ostream &out, const Floor &f) {
    out << *(f.td);
    return out;
}
