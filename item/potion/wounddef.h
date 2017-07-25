#ifndef WOUNDDEF_H
#define WOUNDDEF_H
#include <memory>
#include "../../character/player/player.h"
#include "../playerdecorator.h"
#include "potion.h"

using namespace std;

class WoundDef : public PlayerDecorator, public Potion {
    int getTempAmt();

    public:
    WoundDef(int amt);
    WoundDef(int amt, shared_ptr<Player> p);
    int getMaxHP() override;
    int getCurHP() override;
    int getAtk() override;
    int getDef() override;
    shared_ptr<Player> getPlayer() override;
};

#endif /* WOUNDDEF_H */
