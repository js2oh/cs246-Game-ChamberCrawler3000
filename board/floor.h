#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <vector>
#include "cell.h"
#include "chamber.h"
#include "position.h"
#include "textdisplay.h"
#include "../character/player/player.h"

class Floor {
    const static int WIDTH;
    const static int HEIGHT;
    const static int CHAMBER_COUNT;

    bool isHostileMerchants;
    std::vector<Chamber> chambers;       // The actual grid.
    std::vector<std::vector<Cell>> grid; // The actual grid.
    TextDisplay *td;                     // The text display.

    int pcSpawnChamber;
    bool pcSpawned;
    // Player p;
    void clearGrid(); // Frees the grid.

    void spawnPlayer(std::string race);
    void spawnEnemies();
    void spawnGoldPiles();
    void spawnPotions();
    void spawnStairs();

    public:
    Floor();
    ~Floor();

    void spawn(std::string race = "shade");

    void init();
    friend std::ostream &operator<<(std::ostream &out, const Floor &g);
};

#endif /* FLOOR_H */
