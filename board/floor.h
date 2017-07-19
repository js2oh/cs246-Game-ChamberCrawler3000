#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <vector>
#include "../character/player/player.h"
#include "cell.h"
#include "cellobject.h"
#include "chamber.h"
#include "position.h"
#include "textdisplay.h"

class Chamber;

class Floor {
    const static int WIDTH;
    const static int HEIGHT;
    const static int CHAMBER_COUNT;
    const static int MAX_LEVEL;

    bool isHostileMerchants;
    std::vector<Chamber> chambers;       // The actual grid.
    std::vector<std::vector<Cell>> grid; // The actual grid.
    TextDisplay *td;                     // The text display.
    std::string boardFile;
    int level;
    int pcSpawnChamber;
    bool pcSpawned;
    Player p;
    void clearGrid(); // Frees the grid.
    int getChamberId(Position p);
    void spawnPlayer(std::string race);
    void spawnEnemies();
    void spawnGoldPiles();
    void spawnPotions();
    void spawnStairs();

    public:
    Floor(int level, std::string boardFile = "empty.txt");
    ~Floor();

    Cell &cellAt(int row, int col);
    Cell &cellAt(Position p);

    bool vacantAt(int row, int col) const;
    void spawn(std::string race = "shade");
    void manualSpawn(std::string race = "shade");
    void init();
    friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

std::ostream &operator<<(std::ostream &out, const Floor &f);

#endif /* FLOOR_H */
