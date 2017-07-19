#include "floor.h"
#include <cstdlib>
#include <iostream>

using namespace std;

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
    td = new TextDisplay{WIDTH, HEIGHT, level, boardFile};

    for (int i = 0; i < CHAMBER_COUNT; ++i) {
        chambers.emplace_back(Chamber{i, this});
    }

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j].setCoords(i, j);
            grid[i][j].setTd(td);

            // Get chamber id that current cell is supposed to be in
            // Might be case that cell is outside of 5 chambers
            const int chamberId = Chamber::getMatchingId(i, j);
            if (chamberId != -1) {
                grid[i][j].setChamber(
                    &chambers.at(Chamber::getMatchingId(i, j)));
            }

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
        randomSpawn();
    }
    else {
        customSpawn();
    }
}

void Floor::spawnPlayer(string race) {
    const int i = rand() % CHAMBER_COUNT;
    pcSpawnChamber = i;
    pcSpawned = true;

    Cell &c = chambers.at(i).spawnPlayer();

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

void Floor::randomSpawn(string race) {
    spawnPlayer(race);
    spawnEnemies();
    spawnGoldPiles();
    spawnPotions();

    if (level != MAX_LEVEL) {
        spawnStairs();
    }
}

int Floor::getChamberId(Position p) {
    return Chamber::getMatchingId(p);
}

void Floor::customSpawn(string race) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            Position p{i, j};

            if (td->at(p) != '-' && td->at(p) != '|' && td->at(p) != ' ' &&
                td->at(p) != '+' && td->at(p) != '#' && td->at(p) != '.') {
                const int id = getChamberId(p);

                manualSpawn(td->at(p), p);
            }
        }
    }
}

// manualSpawn manually spawns object with provided symbol at position p.
Cell &Floor::manualSpawn(char symbol, Position p) {
#ifdef DEBUG
    cout << "Spawned: " << symbol << " in " << Chamber::getMatchingId(p)
         << " at " << p << endl;
#endif
    // EnemyFactory ef;
    // PotionFactory pf;
    // TreasureFactory tf;
    Cell &c = cellAt(p);

    switch (symbol) {
        case '@': // Player
            c.setCellObject(CellObject::Player);
            c.setCellSymbol('@');

            break;
        case 'H':
        case 'W':
        case 'E':
        case 'O':
        case 'M':
        case 'D':
        case 'L':
            c.setCellObject(CellObject::Enemy);
            c.setCellSymbol(symbol);
            // ef.create(symbol, p);
            // c.getChamber()->addEnemy(ef.create(symbol, p));
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            c.setCellObject(CellObject::Item);
            c.setCellSymbol('P');
            // pf.create(symbol, p);
            // c.getChamber()->addPotion(pf.create(symbol, p));
            break;
        case '6':
        case '7':
        case '8':
        case '9':
            c.setCellObject(CellObject::Item);
            c.setCellSymbol('G');
            // tf.create(symbol, p);
            // c.getChamber()->addGold(tf.create(symbol, p));
            break;
        case '\\':
            c.setCellObject(CellObject::Stairs);
            c.setCellSymbol('\\');
            break;
    }
    // cout << c.getChamber()->getId() << endl;
    c.notify();
    return c;
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
