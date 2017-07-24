#ifndef ORC_H
#define ORC_H

#include "enemy.h"

class Orc : public Enemy {
    const static char SYMBOL;

    public:
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif /* ORC_H */
