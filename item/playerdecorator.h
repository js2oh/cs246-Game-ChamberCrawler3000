#ifndef _PLAYERDECORATOR_H_
#define _PLAYERDECORATOR_H_
#include <memory>
#include <string>
#include "../character/player/player.h"
#include "itemtype.h"

using namespace std;

class PlayerDecorator : public Player {
    int amt;

    protected:
    shared_ptr<Player> player;
    virtual int getMHP();
    virtual int getCHP();
    virtual int getAtk();
    virtual int getDef();
    virtual string getRace();
    virtual void setCHP(int value);
    virtual shared_ptr<Player> getPlayer();
    virtual int getAmt();

    public:
    PlayerDecorator();
    PlayerDecorator(int amt, shared_ptr<Player> p);
    virtual void attackOn(Enemy &e) = 0;
    virtual void defendFrom(Human *hEnemy) = 0;
    virtual void defendFrom(Dwarf *wEnemy) = 0;
    virtual void defendFrom(Elf *eEnemy) = 0;
    virtual void defendFrom(Orc *oEnemy) = 0;
    virtual void defendFrom(Merchant *mEnemy) = 0;
    virtual void defendFrom(Dragon *dEnemy) = 0;
    virtual void defendFrom(Halfling *lEnemy) = 0;
};

#endif
