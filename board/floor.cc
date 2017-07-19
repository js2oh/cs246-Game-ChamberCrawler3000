#include "floor.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Values that hold for all Floors
const int Floor::WIDTH = 79;
const int Floor::HEIGHT = 25;
const int Floor::CHAMBER_COUNT = 5;
const int Floor::MAX_LEVEL = 5;

Floor::Floor(int level, string boardFile)
    : level{level},              // 1-5
      boardFile{boardFile},      // Default is empty.txt
      isHostileMerchants{false}, // Controls hostility of all merchants
      alreadyInit{false},        // Controls whether to clear grid upon init
      grid{HEIGHT, vector<Cell>{WIDTH}} {
    // Initialize grid Cells and spawn objects
    init();
}

Floor::~Floor() {
    delete td;
}

void Floor::clearGrid() {
    delete td;

    // Clear each 'row' in grid
    for (int i = 0; i < grid.size(); ++i) {
        grid[i].clear();
    }
}

// Initialize TextDisplay, Chambers, Cells, and spawns objects randomly or
// manually
void Floor::init() {
    if (alreadyInit) {
        clearGrid();
    }
    alreadyInit = true;

    // Initialize and load contents of board file into td
    td = new TextDisplay{WIDTH, HEIGHT, level, boardFile};

    // Add 5 chambers to vector
    for (int i = 0; i < CHAMBER_COUNT; ++i) {
        chambers.emplace_back(Chamber{i, this});
    }

    // Set properties for each Cell in grid
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            // Set coordinates
            grid[i][j].setPosition(i, j);
            // Each Cell has a TextDisplay observer
            grid[i][j].setTd(td);

            // Get chamber id that current cell is supposed to be in
            // Might be case that cell is outside of 5 chambers
            const int chamberId = Chamber::getMatchingId(i, j);
            if (chamberId != -1) {
                grid[i][j].setChamber(
                    &chambers.at(Chamber::getMatchingId(i, j)));
            }
            else {
                grid[i][j].setChamber(nullptr);
            }

            // Get symbol at current position in TextDisplay
            char symbol = td->at(i, j);

            // Accessible Cells
            if (symbol == '+' || symbol == '#' || symbol == '.') {
                grid[i][j].setCellObject(CellObject::Empty);
            }
            // Inaccessible cells
            else if (symbol == '|' || symbol == '-' || symbol == ' ') {
                grid[i][j].setCellObject(CellObject::Wall);
            }
            // Other types of cells are configured in spawn methods below
        }
    }

    // Spawn all objects randomly
    if (boardFile == "empty.txt") {
        randomSpawn();
    }
    // Spawn all objects according to specified board file and level
    else {
        customSpawn();
    }
}

// Get chamber id which p belongs to
// Returns -1 if not in a chamber
int Floor::getChamberId(Position p) {
    return Chamber::getMatchingId(p);
}

// Spawn methods:
// Spawn player according to chosen race (shade by default)
void Floor::spawnPlayer(string race) {
    // Randomly select chamber
    const int i = rand() % CHAMBER_COUNT;
    // Keep track of spawn chamber so that stairs do not spawn in same chamber
    pcSpawnChamber = i;

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

// Enemies
void Floor::spawnEnemies() {
    for (int j = 0; j < 20; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        Cell &c = chambers.at(i).spawnEnemy();
    }
}

// Potions
void Floor::spawnPotions() {
    for (int j = 0; j < 10; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        Cell &c = chambers.at(i).spawnPotion();
    }
}

// Gold
void Floor::spawnGoldPiles() {
    for (int j = 0; j < 10; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        Cell &c = chambers.at(i).spawnGoldPile();
    }
}

// Stairs
void Floor::spawnStairs() {
    while (true) {
        int i = rand() % CHAMBER_COUNT;

        // Make sure selected chamber does not contain player
        if (pcSpawnChamber != i) {
            Cell &c = chambers.at(i).spawnStairs();
            break;
        }
    }
}

// Spawn all objects in specified order
void Floor::randomSpawn(string race) {
    spawnPlayer(race);
    spawnEnemies();
    spawnGoldPiles();
    spawnPotions();

    // Spawn stairs only in first 4 levels
    if (level != MAX_LEVEL) {
        spawnStairs();
    }
}

// Spawn according to TextDisplay (which was loaded from board file)
void Floor::customSpawn(string race) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            Position p{i, j};

            // Manually spawn player, enemies, and items
            if (td->at(p) != '-' && td->at(p) != '|' && td->at(p) != ' ' &&
                td->at(p) != '+' && td->at(p) != '#' && td->at(p) != '.') {
                const int id = getChamberId(p);

                manualSpawn(td->at(p), p);
            }
        }
    }
}

// Manually spawn object with given symbol at position p.
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
        // Player
        case '@':
            c.setCellObject(CellObject::Player);
            c.setCellSymbol('@');
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
            break;
        // Enemy types
        case 'H':
        case 'W':
        case 'E':
        case 'O':
        case 'M':
        case 'D':
        case 'L':
            c.setCellObject(CellObject::Enemy);
            c.setCellSymbol(symbol);
            // Use factory to manually spawn the correct enemy type
            // ef.create(symbol, p);
            // c.getChamber()->addEnemy(ef.create(symbol, p));
            break;
        // Potion types
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
        // Treasures
        case '6':
        case '7':
        case '8':
        case '9':
            c.setCellObject(CellObject::Item);
            c.setCellSymbol('G');
            // tf.create(symbol, p);
            // c.getChamber()->addGold(tf.create(symbol, p));
            break;
        // Stairs
        case '\\':
            c.setCellObject(CellObject::Stairs);
            c.setCellSymbol('\\');
            break;
    }

    // Notify TextDisplay of changes
    // Display should show 'P' for potions and 'G' for gold
    c.notify();
    return c;
}

// Get Cell at given position
Cell &Floor::cellAt(int row, int col) {
    return grid.at(row).at(col);
}

Cell &Floor::cellAt(Position p) {
    return cellAt(p.row, p.col);
}

// Determine vacancy of grid at given position
bool Floor::vacantAt(const int row, const int col) const {
    return grid.at(row).at(col).getCellObject() == CellObject::Empty;
}

ostream &operator<<(ostream &out, const Floor &f) {
    out << *(f.td);
    return out;
}
