#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"

class Human : public Enemy {
    const static char SYMBOL;

    public:
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif /* HUMAN_H */
