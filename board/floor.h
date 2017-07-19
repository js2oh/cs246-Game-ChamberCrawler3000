#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <vector>
#include "cell.h"
#include "chamber.h"
#include "textdisplay.h"

class Floor {
    const static int WIDTH;
    const static int HEIGHT;
    const static int CHAMBER_COUNT;

    bool isHostileMerchants;
    std::vector<Chamber> chambers;       // The actual grid.
    std::vector<std::vector<Cell>> grid; // The actual grid.
    TextDisplay *td;                     // The text display.

    void clearGrid(); // Frees the grid.
    public:
    Floor();
    ~Floor();

    void spawnPlayer();
    void spawnEnemies();
    void spawnGoldPiles();
    void spawnPotions();
    void spawnStairs();

    void init();
    friend std::ostream &operator<<(std::ostream &out, const Floor &g);
};

#endif /* FLOOR_H */
