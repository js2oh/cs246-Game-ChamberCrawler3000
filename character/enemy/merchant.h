#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"

class Merchant : public Enemy {
    const static char SYMBOL;

    public:
    void attackOn(Player &p) override;
};

#endif /* MERCHANT_H */
