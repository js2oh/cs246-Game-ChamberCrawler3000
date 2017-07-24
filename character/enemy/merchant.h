#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"

class Merchant : public Enemy {
    const static char SYMBOL;

    public:
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif /* MERCHANT_H */
