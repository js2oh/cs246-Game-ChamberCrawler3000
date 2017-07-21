#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "../../board/cell.h"

class Cell;
struct Position;

class Player {
    Cell *cell;

    // const int maxHp;
    int hp;
    int atk;
    int def;

    public:
    Player(Cell *cell);
    void setCell(Cell *cell);
    Cell *getCell() const;

    Position getPosition() const;
};

#endif /* PLAYER_H */
