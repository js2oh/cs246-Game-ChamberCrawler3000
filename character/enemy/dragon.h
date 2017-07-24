#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Dragon : public Enemy {
    const static char SYMBOL;

    public:
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif /* DRAGON_H */
