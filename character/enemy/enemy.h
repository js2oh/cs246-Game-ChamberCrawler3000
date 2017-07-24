#ifndef ENEMY_H
#define ENEMY_H
#include "../player/player.h"

class Enemy {
    public:
    virtual void attackOn(Player &p) = 0;
};

#endif /* ENEMY_H */
