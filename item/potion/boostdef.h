#ifndef BOOSTDEF_H
#define BOOSTDEF_H
#include "../../character/player/player.h"
#include "potion.h"
#include "../playerdecorator.h"
#include <memory>

using namespace std;

class BoostDef: public PlayerDecorator, public Potion {
	int getTempAmt();
public:
    BoostDef(shared_ptr<Player> p);
    int getMaxHP() override;
    int getCurHP() override;
    int getAtk() override;
    int getDef() override;
    shared_ptr<Player> getPlayer() override;
};

#endif /* BOOSTDEF_H */
