#include "floor.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "../character/enemy/enemyfactory.h"
#include "../item/potion/potionfactory.h"

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

Floor::Floor(string boardFile) : Floor{1, boardFile} {}

Floor::Floor(int level, string boardFile)
    : alreadyInit{false},        // Controls whether to clear grid upon init
      isHostileMerchants{false}, // Controls hostility of all merchants
      gameOver{false},
      level{level},         // 1-5
      boardFile{boardFile}, // Default is empty.txt
      action{"Player character has spawned."},
      grid{HEIGHT, vector<Cell>{WIDTH}} {
    // Initialize grid Cells and spawn objects
    // init(race);
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

    chambers.clear();
}

// Initialize TextDisplay, Chambers, Cells, and spawns objects randomly or
// manually
void Floor::init(string race) {
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
                grid[i][j].setCellObject(CellObject::Empty);
                grid[i][j].setCellSymbol('.');
            }

            // Other types of cells are configured in spawn methods below
        }
    }

    // Spawn all objects randomly
    if (boardFile == "empty.txt") {
        randomSpawn(race);
    }
    // Spawn all objects according to specified board file and level
    else {
        customSpawn(race);
    }
}

void Floor::loadNextLevel() {
    ++level;
    alreadyInit = false;
    player = original;
    enemyMoves = 0;
    init();
}

// Spawn all objects in specified order
void Floor::randomSpawn(string race) {
    spawnPlayer(race);
    spawnEnemies();
    spawnGoldPiles();
    spawnPotions();
    spawnStairs();
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
                manualSpawn(td->at(p), p, race);
            }
        }
    }
}

// Manually spawn object with given symbol at position p.
void Floor::manualSpawn(char symbol, Position p, string race) {
    EnemyFactory ef;
    PotionFactory pf;
    // TreasureFactory tf;
    Cell &c = cellAt(p);
    c.setCellSymbol('.');
    shared_ptr<Item> ip;

    switch (symbol) {
        // Player
        case '@':
            c.setCellObject(CellObject::Character);

            if (!player) {
                if (race == "s") {
                    player = make_shared<Shade>(&c);
                }
                else if (race == "d") {
                    player = make_shared<Drow>(&c);
                }
                else if (race == "g") {
                    player = make_shared<Goblin>(&c);
                }
                else if (race == "t") {
                    player = make_shared<Troll>(&c);
                }
                else if (race == "v") {
                    player = make_shared<Vampire>(&c);
                }
                original = player;
            }
            else {
                player->setCell(&c);
            }

            c.setCharacter(player);
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
            // shared_ptr<Character> cp = ef.manualCreate(symbol, &c);
            c.setCharacter(ef.manualCreate(symbol, &c));
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
            // ip = pf.manualCreate(symbol, &c);
            c.setPotion(pf.manualCreate(symbol, &c));
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

    if (!player) {
        if (race == "s") {
            player = make_shared<Shade>(&c);
        }
        else if (race == "d") {
            player = make_shared<Drow>(&c);
        }
        else if (race == "g") {
            player = make_shared<Goblin>(&c);
        }
        else if (race == "t") {
            player = make_shared<Troll>(&c);
        }
        else if (race == "v") {
            player = make_shared<Vampire>(&c);
        }
        original = player;
    }

    c.setCharacter(player);
    c.notify();
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
                cout << "Empty!" << endl;
                oldCell->transferCharacter(newCell);
                break;
            case CellObject::Item:
                // if (isDragonHoard)
                //      cannot be picked up
                // else if (gold) {
                //      pick up
                //}

                // oldCell->transferCharacter(newCell);
                cout << "Item!" << endl;
                break;
            case CellObject::Stairs:
                if (level == MAX_LEVEL) {
                    gameOver = true;
                }
                else {
                    loadNextLevel();
                }
                break;
            default:
                cout << "Other!" << endl;
                break;
        }
    }
}

string Floor::intToDir(const int i) const {
    switch (i) {
        case 0:
            return "no";
        case 1:
            return "ne";
        case 2:
            return "ea";
        case 3:
            return "se";
        case 4:
            return "so";
        case 5:
            return "sw";
        case 6:
            return "we";
        case 7:
            return "nw";
        default:
            throw invalid_argument("Invalid integer.");
    }
}

bool Floor::moveAvailable(const Position pos) const {
    const int row = pos.row;
    const int col = pos.col;

    if (!isInBounds(row, col)) {
        return false;
    }

    return
        // North
        (isInBounds(row - 1, col) && grid[row - 1][col].isEmpty()) ||
        // North-east
        (isInBounds(row - 1, col + 1) && grid[row - 1][col + 1].isEmpty()) ||
        // East
        (isInBounds(row, col + 1) && grid[row][col + 1].isEmpty()) ||
        // South-east
        (isInBounds(row + 1, col + 1) && grid[row + 1][col + 1].isEmpty()) ||
        // South
        (isInBounds(row + 1, col) && grid[row + 1][col].isEmpty()) ||
        // South-west
        (isInBounds(row + 1, col - 1) && grid[row + 1][col - 1].isEmpty()) ||
        // West
        (isInBounds(row, col - 1) && grid[row][col - 1].isEmpty()) ||
        // North-west
        (isInBounds(row - 1, col - 1) && grid[row - 1][col - 1].isEmpty());
}

void Floor::moveEnemies() {
    const int ADJACENT_CELLS = 8;

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            Cell &oldCell = grid[i][j];
            const Position cellPos = oldCell.getPosition();

            if (oldCell.getCellObject() == CellObject::Character &&
                cellPos != player->getPosition() && moveAvailable(cellPos) &&
                oldCell.getCharacter()->getMoves() == enemyMoves) {
                oldCell.getCharacter()->increaseMoves();
                ChamberLoc cLoc = oldCell.getChamberLoc();
                // oldCell.getCharacter().getMoves;

                // Find new position to move to
                while (true) {
                    int i = rand() % ADJACENT_CELLS;
                    const Position newPos = dirToPos(cellPos, intToDir(i));

                    if (isInBounds(newPos)) {
                        Cell &newCell = cellAt(newPos);

                        if (newCell.getCellObject() == CellObject::Empty &&
                            newCell.getChamberLoc() == cLoc &&
                            newCell.isTile()) {
                            oldCell.transferCharacter(newCell);
                            break;
                        }
                    }
                }
            }
        }
    }

    ++enemyMoves;
}

void Floor::attack(string dir) {
    const Position oldPos = player->getPosition();
    const Position newPos = dirToPos(oldPos, dir);
    Cell *oldCell = player->getCell();

    if (isInBounds(newPos)) {
        Cell &newCell = cellAt(newPos);
        const ChamberLoc enemyChamberLoc = Chamber::getMatchingLoc(newPos);
        shared_ptr<Character> cp = newCell.getCharacter();

        if (newCell.getCellObject() == CellObject::Character) {
            // player->attackOn(*cp);
        }
    }
}

void Floor::usePotion(string dir) {
    const Position oldPos = player->getPosition();
    const Position newPos = dirToPos(oldPos, dir);

    Cell *oldCell = player->getCell();

    if (isInBounds(newPos)) {
        Cell &newCell = cellAt(newPos);

        if (newCell.getCellObject() == CellObject::Item) {
            shared_ptr<Potion> pp = newCell.getPotion();
            player = pp->makePlayer(player);

            pp->applyEffects(player);
            oldCell->setCharacter(player);

            newCell.deleteCell();
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
    return isInBounds(p.row, p.col);
}

bool Floor::isInBounds(const int row, const int col) const {
    return row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH;
}

bool Floor::isGameOver() const {
    return gameOver;
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

void Floor::printEndGame() const {
    for (int i = 0; i < HEIGHT; ++i) {
        cout << endl;
    }

    for (int i = 0; i < WIDTH; ++i) {
        cout << "=";
    }
    cout << endl << "Game Over!" << endl << endl;

    cout << "Your final score: " << endl;
}

// Determine vacancy of grid at given position
bool Floor::vacantAt(const int row, const int col) const {
    return grid.at(row).at(col).getCellObject() == CellObject::Empty;
}

ostream &operator<<(ostream &out, const Floor &f) {
    out << *(f.td);
    string raceGold;

    raceGold += "Race: ";
    raceGold += f.player->getRace();
    raceGold += " Gold: ";
    raceGold += "0"; // f.player->getGold()

    out << left << setw(f.WIDTH - 8) << raceGold << "Level: " << f.level
        << endl;

    // TEMPORARY
    // out << "HP: " << 0 << endl;
    // out << "Atk: " << 0 << endl;
    // out << "Def: " << 0 << endl;

    out << "HP: " << f.player->getCHP() << endl;
    out << "Atk: " << f.player->getAtk() << endl;
    out << "Def: " << f.player->getDef() << endl;

    out << "Action: " << f.action;
    return out;
}
