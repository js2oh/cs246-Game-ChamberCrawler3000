#ifndef WOUNDATK_H
#define WOUNDATK_H
#include "player.h"
#include "playerDecorator.h"
#include <memory>

using namespace std;

class WoundAtk: public PlayerDecorator, public Potion {
public:
    WoundAtk(shared_ptr<Player> p);
    int getMaxHP() override;
    int getCurHP() override;
    int getAtk() override;
    int getDef() override;
    shared_ptr<Player> getPlayer() override;
};

#endif /* WOUNDATK_H */
