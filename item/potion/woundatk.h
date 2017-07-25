#ifndef WOUNDATK_H
#define WOUNDATK_H
#include <memory>
#include "../../character/player/player.h"
#include "../playerdecorator.h"
#include "potion.h"

using namespace std;

class WoundAtk : public PlayerDecorator, public Potion {
    int getTempAmt();

    public:
    WoundAtk(int amt);
    WoundAtk(int amt, shared_ptr<Player> p);
    int getMaxHP() override;
    int getCurHP() override;
    int getAtk() override;
    int getDef() override;
    shared_ptr<Player> getPlayer() override;
};

#endif /* WOUNDATK_H */
