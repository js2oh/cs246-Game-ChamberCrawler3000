#ifndef BOOSTATK_H
#define BOOSTATK_H
#include <memory>
#include "../../character/player/player.h"
#include "../playerdecorator.h"
#include "potion.h"

using namespace std;

class BoostAtk : public PlayerDecorator, public Potion {
    int getTempAmt();

    public:
    BoostAtk(int amt, shared_ptr<Player> p);
    BoostAtk(int amt);

    int getMaxHP() override;
    int getCurHP() override;
    int getAtk() override;
    int getDef() override;
    shared_ptr<Player> getPlayer() override;
    // void applyEffects() override;
};
#endif /* BOOSTATK_H */
