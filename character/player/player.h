#ifndef PLAYER_H
#define PLAYER_H
#include <string>

#include "../character.h"

class Cell;
struct Position;

class Player : public Character {
	protected:
    const static char SYMBOL;
	std::string race;
    public:
    Player ();
    Player(Cell *cell);
    virtual ~Player(){};
	std::string getRace();
};

#endif /* PLAYER_H */
