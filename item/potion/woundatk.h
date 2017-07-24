#ifndef WOUNDATK_H
#define WOUNDATK_H
#include "../../character/player/player.h"
#include "potion.h"
#include "../playerdecorator.h"
#include <memory>

using namespace std;

class WoundAtk: public PlayerDecorator, public Potion {
	int getTempAmt();
public:
    WoundAtk(shared_ptr<Player> p);
    int getMaxHP() override;
    int getCurHP() override;
    int getAtk() override;
    int getDef() override;
    shared_ptr<Player> getPlayer() override;
};

#endif /* WOUNDATK_H */
