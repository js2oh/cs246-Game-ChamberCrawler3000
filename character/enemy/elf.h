#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf : public Enemy {
    const static char SYMBOL;

    public:
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif /* ELF_H */
