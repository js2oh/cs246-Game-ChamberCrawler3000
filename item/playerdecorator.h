#ifndef _PLAYERDECORATOR_H_
#define _PLAYERDECORATOR_H_
#include <memory>
#include "../character/player/player.h"

using namespace std;

class PlayerDecorator : public Player {
    shared_ptr<Player> player;

    protected:
    virtual int getMaxHP();
    virtual int getCurHP();
    virtual int getAtk();
    virtual int getDef();
    virtual shared_ptr<Player> getPlayer();

    public:
    PlayerDecorator(shared_ptr<Player> p);
    // PlayerDecorator(Player *p);
};

#endif
