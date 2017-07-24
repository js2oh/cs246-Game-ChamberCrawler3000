#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"

class Dwarf : public Enemy {
    const static char SYMBOL;

    public:
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif /* DWARF_H */
