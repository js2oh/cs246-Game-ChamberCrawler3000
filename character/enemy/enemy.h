#ifndef ENEMY_H
#define ENEMY_H
#include "../character.h"

class Cell;
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

class Enemy : public Character {
    int maxHP;
    int curHP;
    int atk;
    int def;

    public:
    Enemy(Cell *c, char symbol);

    virtual int getMHP();
    virtual int getCHP();
    virtual int getAtk();
    virtual int getDef();
    virtual void setCHP(int value);
    void setMHP(int value);
    void setAtk(int value);
    void setDef(int value);
    virtual void attackOn(Player &p) = 0;
    virtual void defendFrom(Shade *sPlayer) = 0;
    virtual void defendFrom(Drow *dPlayer) = 0;
    virtual void defendFrom(Vampire *vPlayer) = 0;
    virtual void defendFrom(Troll *tPlayer) = 0;
    virtual void defendFrom(Goblin *gPlayer) = 0;
    virtual void defendFrom(BoostAtk *baPlayer) = 0;
    virtual void defendFrom(BoostDef *bdPlayer) = 0;
    virtual void defendFrom(WoundAtk *waPlayer) = 0;
    virtual void defendFrom(WoundDef *wdPlayer) = 0;
};

#endif
