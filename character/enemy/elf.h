#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf : public Enemy {
    const static char SYMBOL;

    public:
    void attackOn(Player &p) override;
    ;
};

#endif /* ELF_H */
