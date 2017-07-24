#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Dragon : public Enemy {
    const static char SYMBOL;

    public:
    void attackOn(Player &p) override;
};

#endif /* DRAGON_H */
