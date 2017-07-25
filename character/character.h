#ifndef CHARACTER_H
#define CHARACTER_H
#include "../board/position.h"
class Cell;

class Character {
    public:
    char getSymbol() const;
    void setCell(Cell *cell);
    Cell *getCell() const;
    Position getPosition() const;
    // Character(Cell *cell);
    Character(char symbol);
    Character(Cell *cell, char symbol);
    virtual ~Character() = 0;

    // needs constant maxHP working first
    int getMaxHP() {
        return hp;
    }
    int getCurHP() {
        return hp;
    }
    int getAtk() {
        return atk;
    }
    int getDef() {
        return def;
    }

    int getMoves() {
        return moves;
    }

    void increaseMoves() {
        ++moves;
    }

    protected:
    const char symbol;
    Cell *cell;

    // const int maxHp;
    int hp;
    int def;
    int atk;
    int moves;
};

#endif /* CHARACTER_H */
