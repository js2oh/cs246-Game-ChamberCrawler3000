#include "floor.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Values that hold for all Floors
const int Floor::WIDTH = 79;
const int Floor::HEIGHT = 25;
const int Floor::CHAMBER_COUNT = 5;
const int Floor::MAX_LEVEL = 5;

// Configurable options:
const int Floor::MAX_ENEMIES = 20;
const int Floor::MAX_POTIONS = 10;
const int Floor::MAX_GOLD_PILES = 10;

Floor::Floor(int level, string boardFile)
    : isHostileMerchants{false}, // Controls hostility of all merchants
      alreadyInit{false},        // Controls whether to clear grid upon init
      level{level},              // 1-5
      boardFile{boardFile},      // Default is empty.txt
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

    // Add 5 chambers to map
    chambers[ChamberLoc::TopLeft] = Chamber{ChamberLoc::TopLeft, this};
    chambers[ChamberLoc::TopRight] = Chamber{ChamberLoc::TopRight, this};
    chambers[ChamberLoc::BottomRight] = Chamber{ChamberLoc::BottomRight, this};
    chambers[ChamberLoc::BottomLeft] = Chamber{ChamberLoc::BottomLeft, this};
    chambers[ChamberLoc::Centre] = Chamber{ChamberLoc::Centre, this};

    // Set properties for each Cell in grid
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            // Set coordinates
            grid[i][j].setPosition(i, j);
            // Each Cell has a TextDisplay observer
            grid[i][j].setTd(td);

            // Get chamber location that current cell is supposed to be in
            // Might be case that cell is outside of 5 chambers
            const ChamberLoc chamberLoc = Chamber::getMatchingLoc(i, j);
            if (chamberLoc == ChamberLoc::Other) {
                grid[i][j].setChamber(nullptr);
            }
            else {
                grid[i][j].setChamber(
                    &chambers.at(Chamber::getMatchingLoc(i, j)));
            }

            // Get symbol at current position in TextDisplay
            const char symbol = td->at(i, j);
            // later

            // Accessible Cells
            if (symbol == '+' || symbol == '#') {
                grid[i][j].setCellObject(CellObject::Empty);
                grid[i][j].setCellSymbol(symbol);
            }
            // Inaccessible cells
            else if (symbol == '|' || symbol == '-' || symbol == ' ') {
                grid[i][j].setCellObject(CellObject::Wall);
                grid[i][j].setCellSymbol(symbol);
            }
            // Standard tiles (may be occupied by characters and items)
            else {
                grid[i][j].setCellSymbol('.');
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
                // const ChamberLoc id = getChamberLoc(p);
                manualSpawn(td->at(p), p);
            }
        }
    }
}

// Manually spawn object with given symbol at position p.
void Floor::manualSpawn(char symbol, Position p) {
#ifdef DEBUG
// cout << "Spawned: " << symbol << " in " << Chamber::getMatchingId(p)
//     << " at " << p << endl;
#endif
    // EnemyFactory ef;
    // PotionFactory pf;
    // TreasureFactory tf;
    Cell &c = cellAt(p);
    c.setCellSymbol('.');

    switch (symbol) {
        // Player
        case '@':
            c.setCellObject(CellObject::Character);
            player = new Player(&c); // Later change to Character *
            // c.setCharacter(player);

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
            c.setCellObject(CellObject::Character);
            // Use factory to manually spawn the correct enemy type
            // Character *cp = ef.create(symbol, p);
            // c.setCharacter(cp);
            // c.getChamber()->addEnemy(cp);
            break;
        // Potion types
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            c.setCellObject(CellObject::Item);
            // Item *ip = pf.create(symbol, p);
            // c.setItem(ip);
            // c.getChamber()->addPotion(ip);
            break;
        // Treasures
        case '6':
        case '7':
        case '8':
        case '9':
            c.setCellObject(CellObject::Item);
            // Item *ip = tf.create(symbol, p);
            // c.setItem(ip);
            // c.getChamber()->addGold(ip);
            break;
        // Stairs
        case '\\':
            c.setCellObject(CellObject::Stairs);
            break;
    }

    // Notify TextDisplay of changes
    // Display should show 'P' for potions and 'G' for gold
    c.notify();
    // return c;
}

// Spawn methods:
// Spawn player according to chosen race (shade by default)
void Floor::spawnPlayer(string race) {
    // Randomly select chamber
    const int i = rand() % CHAMBER_COUNT;
    const ChamberLoc randLoc = intToChamberLoc(i);

    // Keep track of spawn chamber so that stairs do not spawn in same chamber
    pcSpawnChamber = randLoc;

    Cell &c = chambers.at(randLoc).spawnPlayer();
    player = new Player(&c); // Change to Character once implemented
    // c.setCharacter(player);

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
    for (int j = 0; j < MAX_ENEMIES; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        const ChamberLoc randLoc = intToChamberLoc(i);
        // Spawn enemies and store in vectors inside chambers
        Cell &c = chambers.at(randLoc).spawnEnemy();
    }
}

// Potions
void Floor::spawnPotions() {
    for (int j = 0; j < MAX_POTIONS; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        const ChamberLoc randLoc = intToChamberLoc(i);
        // Spawn potions and store in vectors inside chambers
        Cell &c = chambers.at(randLoc).spawnPotion();
    }
}

// Gold
void Floor::spawnGoldPiles() {
    for (int j = 0; j < MAX_GOLD_PILES; ++j) {
        const int i = rand() % CHAMBER_COUNT;
        const ChamberLoc randLoc = intToChamberLoc(i);
        // Spawn gold piles and store in vectors inside chambers
        Cell &c = chambers.at(randLoc).spawnGoldPile();
    }
}

// Stairs
void Floor::spawnStairs() {
    while (true) {
        int i = rand() % CHAMBER_COUNT;
        const ChamberLoc randLoc = intToChamberLoc(i);

        // Make sure selected chamber does not contain player
        if (pcSpawnChamber != randLoc) {
            Cell &c = chambers.at(randLoc).spawnStairs();
            break;
        }
    }
}

void Floor::movePlayer(string dir) {
    const Position oldPos = player->getPosition();
    const Position newPos = dirToPos(oldPos, dir);

    Cell *oldCell = player->getCell();

    if (isInBounds(newPos)) {
        Cell &newCell = cellAt(newPos);

        switch (newCell.getCellObject()) {
            case CellObject::Empty:
                oldCell->transferCharacter(newCell);
                player->setCell(&newCell);
                break;
            case CellObject::Item:
                // if (isDragonHoard)
                //      cannot be picked up
                // else if (gold) {
                //      pick up
                //}
                break;
            case CellObject::Stairs:
                // Load next level
                break;
            default:
                break;
        }
    }
}

// Get Cell at given position
Cell &Floor::cellAt(int row, int col) {
    return grid.at(row).at(col);
}

Cell &Floor::cellAt(Position p) {
    return cellAt(p.row, p.col);
}

// Get chamber location that p belongs to
ChamberLoc Floor::getChamberLoc(Position p) const {
    return Chamber::getMatchingLoc(p);
}

Position Floor::getPlayerPosition() const {
    return player->getPosition();
}

ChamberLoc Floor::intToChamberLoc(int i) {
    switch (i) {
        case 0:
            return ChamberLoc::TopLeft;
        case 1:
            return ChamberLoc::TopRight;
        case 2:
            return ChamberLoc::BottomRight;
        case 3:
            return ChamberLoc::BottomLeft;
        case 4:
            return ChamberLoc::Centre;
        default: // Should never happen
            return ChamberLoc::Other;
    }
}

bool Floor::isInBounds(Position p) const {
    return p.row >= 0 && p.row < HEIGHT && p.col >= 0 && p.col < WIDTH;
}

Position Floor::dirToPos(Position pos, string dir) const {
    Position newPos{pos};
    // TODO In future, disallow one-character directions like 'n', 'e', etc.
    // Keep for now because it's easier to type

    if (dir == "nw") {
        --newPos.row;
        --newPos.col;
    }
    else if (dir == "n" || dir == "no") {
        --newPos.row;
    }
    else if (dir == "ne") {
        --newPos.row;
        ++newPos.col;
    }
    else if (dir == "e" || dir == "ea") {
        ++newPos.col;
    }
    else if (dir == "se") {
        ++newPos.row;
        ++newPos.col;
    }
    else if (dir == "s" || dir == "so") {
        ++newPos.row;
    }
    else if (dir == "sw") {
        ++newPos.row;
        --newPos.col;
    }
    else {
        --newPos.col;
    }

    return newPos;
}

// Determine vacancy of grid at given position
bool Floor::vacantAt(const int row, const int col) const {
    return grid.at(row).at(col).getCellObject() == CellObject::Empty;
}

ostream &operator<<(ostream &out, const Floor &f) {
    out << *(f.td);
    out << "Player at " << f.getPlayerPosition();
    return out;
}
