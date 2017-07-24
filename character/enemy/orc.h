#ifndef ORC_H
#define ORC_H

#include "enemy.h"

class Orc : public Enemy {
    const static char SYMBOL;

    public:
    void attackOn(Player &p) override;
};

#endif /* ORC_H */
