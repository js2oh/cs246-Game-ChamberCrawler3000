#ifndef MERCHANT_H
#define MERCHANT_H
#include "../character.h"
#include "../player/goblin.h"
#include "enemy.h"

class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class BoostAtk;
class BoostDef;
class WoundAtk;
class WoundDef;

class Merchant : public Enemy {
    const static char SYMBOL;

    public:
    int getMHP() override;
    int getCHP() override;
    int getAtk() override;
    int getDef() override;
    void setCHP(int value) override;
    Merchant(Cell *c);
    void defendFrom(Shade *sPlayer) override;
    void defendFrom(Drow *dPlayer) override;
    void defendFrom(Vampire *vPlayer) override;
    void defendFrom(Troll *tPlayer) override;
    void defendFrom(Goblin *gPlayer) override;
    void defendFrom(BoostAtk *baPlayer) override;
    void defendFrom(BoostDef *bdPlayer) override;
    void defendFrom(WoundAtk *waPlayer) override;
    void defendFrom(WoundDef *wdPlayer) override;
    void attackOn(Player &p) override;
};

#endif
