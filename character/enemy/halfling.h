#ifndef HALFLING_H
#define HALFLING_H

#include "enemy.h"

class Halfling : public Enemy {
    const static char SYMBOL;

    public:
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif /* HALFLING_H */
