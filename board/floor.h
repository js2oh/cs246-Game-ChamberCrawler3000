#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "../character/player/drow.h"
#include "../character/player/goblin.h"
#include "../character/player/player.h"
#include "../character/player/shade.h"
#include "../character/player/troll.h"
#include "../character/player/vampire.h"
#include "cell.h"
#include "cellobject.h"
#include "chamber.h"
#include "chamberloc.h"
#include "position.h"
#include "textdisplay.h"

class Chamber;
class Player;
class Shade;

class Floor {
    // Constants
    const static int WIDTH;
    const static int HEIGHT;
    const static int CHAMBER_COUNT;
    const static int MAX_LEVEL;
    const static int MAX_ENEMIES;
    const static int MAX_POTIONS;
    const static int MAX_GOLD_PILES;

    // Fields
    bool alreadyInit;
    bool isHostileMerchants;
    bool gameOver;
    int level;
    int enemyMoves = 0;

    std::string boardFile;
    std::string action;
    ChamberLoc pcSpawnChamber;

    std::shared_ptr<Player> player;
    std::shared_ptr<Player> original;

    TextDisplay *td;                        // The text display
    std::map<ChamberLoc, Chamber> chambers; // Chambers
    std::vector<std::vector<Cell>> grid;    // The actual grid

    bool adjacentToPlayer(Position pos);
    bool moveAvailable(Position pos) const;
    
    void loadNextLevel();
    ChamberLoc getChamberLoc(Position p) const;
    static ChamberLoc intToChamberLoc(int i);
    Position dirToPos(Position pos, std::string dir) const;
    std::string intToDir(int i) const;

    // Private spawn methods
    void spawnPlayer(std::string race);
    void spawnEnemies();
    void spawnGoldPiles();
    void spawnPotions();
    void spawnStairs();
    void randomSpawn(std::string race = "shade");
    void customSpawn(std::string race = "shade");
    void manualSpawn(char symbol, Position p, std::string race);

    public:
    Floor(int level, std::string boardFile = "empty.txt");
    Floor(std::string boardFile = "empty.txt");
    ~Floor();
    void clearGrid();
    void init(std::string = "s");
    void movePlayer(std::string dir);
    void moveEnemies();
    void attack(std::string dir);
    void usePotion(std::string dir);

    void printEndGame() const;

    Cell &cellAt(int row, int col);
    Cell &cellAt(Position p);
    Position getPlayerPosition() const;
    bool isInBounds(int row, int col) const;
    bool isInBounds(Position p) const;
    bool isGameOver() const;
    bool vacantAt(int row, int col) const;
    friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

std::ostream &operator<<(std::ostream &out, const Floor &f);

#endif /* FLOOR_H */
