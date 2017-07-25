#ifndef SHADE_H
#define SHADE_H
#include "player.h"
class Cell;

class Shade : public Player {
    Cell *cell;

    public:
    Shade(Cell *cell);
    ~Shade(){};
};
#endif /* SHADE_H */
