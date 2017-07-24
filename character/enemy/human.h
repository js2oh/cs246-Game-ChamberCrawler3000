#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"

class Human : public Enemy {
    const static char SYMBOL;

    public:
    void attackOn(Player &p) override;
};

#endif /* HUMAN_H */
