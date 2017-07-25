#ifndef BOOSTDEF_H
#define BOOSTDEF_H
#include <memory>
#include "../../character/player/player.h"
#include "../playerdecorator.h"
#include "potion.h"

using namespace std;

class BoostDef : public PlayerDecorator, public Potion {
    int getTempAmt();

    public:
    BoostDef(int amt);
    BoostDef(int amt, shared_ptr<Player> p);
    int getMaxHP() override;
    int getCurHP() override;
    int getAtk() override;
    int getDef() override;
    shared_ptr<Player> getPlayer() override;
};

#endif /* BOOSTDEF_H */
