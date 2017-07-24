#ifndef PLAYER_H
#define PLAYER_H
#include <string>

#include "../character.h"
class Cell;
struct Position;

class Player : public Character {
    public:
    // Player (){};
    Player(Cell *cell);
    virtual ~Player(){};
};

#endif /* PLAYER_H */
