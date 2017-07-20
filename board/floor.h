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
    const static int WIDTH;
    const static int HEIGHT;
    const static int CHAMBER_COUNT;
    const static int MAX_LEVEL;
    const static int MAX_ENEMIES;
    const static int MAX_POTIONS;
    const static int MAX_GOLD_PILES;

    bool isHostileMerchants;
    bool alreadyInit;
    int level;
    int pcSpawnChamber;

    Player *player;
    std::map<ChamberLoc, Chamber> chambers; // Chambers
    std::vector<std::vector<Cell>> grid;    // The actual grid
    TextDisplay *td;                        // The text display
    std::string boardFile;

    void clearGrid();
    ChamberLoc getChamberLoc(Position p);

    static ChamberLoc intToChamberLoc(int i);

    // Spawn methods private
    void spawnPlayer(std::string race);
    void spawnEnemies();
    void spawnGoldPiles();
    void spawnPotions();
    void spawnStairs();
    Cell &manualSpawn(char symbol, Position p);
    void randomSpawn(std::string race = "shade");
    void customSpawn(std::string race = "shade");

    public:
    Floor(int level, std::string boardFile = "empty.txt");
    ~Floor();
    void init();
    Cell &cellAt(int row, int col);
    Cell &cellAt(Position p);
    bool vacantAt(int row, int col) const;

    friend std::ostream &operator<<(std::ostream &out, const Floor &f);

    void movePlayer(std::string dir);
    Position dirToPos(Position pos, std::string dir);
    Position getPlayerPosition() const;

    bool isInBounds(Position p) const;
};

std::ostream &operator<<(std::ostream &out, const Floor &f);

#endif /* FLOOR_H */
