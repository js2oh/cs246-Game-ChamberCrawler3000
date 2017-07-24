#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"

class Dwarf : public Enemy {
    const static char SYMBOL;

    public:
    void attackOn(Player &p) override;
};

#endif /* DWARF_H */
