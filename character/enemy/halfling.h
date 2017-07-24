#ifndef HALFLING_H
#define HALFLING_H

#include "enemy.h"

class Halfling : public Enemy {
    const static char SYMBOL;

    public:
    void attackOn(Player &p) override;
};

#endif /* HALFLING_H */
