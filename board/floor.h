#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <map>
#include <vector>
#include "../character/player/player.h"
#include "cell.h"
#include "cellobject.h"
#include "chamber.h"
#include "chamberloc.h"
#include "position.h"
#include "textdisplay.h"

class Chamber;
class Player;

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
    bool isHostileMerchants;
    bool alreadyInit;
    int level;
    std::string boardFile;
    ChamberLoc pcSpawnChamber;

    Player *player;
    TextDisplay *td;                        // The text display
    std::map<ChamberLoc, Chamber> chambers; // Chambers
    std::vector<std::vector<Cell>> grid;    // The actual grid

    void clearGrid();
    ChamberLoc getChamberLoc(Position p) const;
    static ChamberLoc intToChamberLoc(int i);
    Position dirToPos(Position pos, std::string dir) const;

    // Private spawn methods
    void spawnPlayer(std::string race);
    void spawnEnemies();
    void spawnGoldPiles();
    void spawnPotions();
    void spawnStairs();
    void randomSpawn(std::string race = "shade");
    void customSpawn(std::string race = "shade");
    void manualSpawn(char symbol, Position p);

    public:
    Floor(int level, std::string boardFile = "empty.txt");
    ~Floor();
    void init();
    void movePlayer(std::string dir);

    Cell &cellAt(int row, int col);
    Cell &cellAt(Position p);
    Position getPlayerPosition() const;
    bool isInBounds(Position p) const;
    bool vacantAt(int row, int col) const;
    friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

std::ostream &operator<<(std::ostream &out, const Floor &f);

#endif /* FLOOR_H */
