#ifndef BOOSTATK_H
#define BOOSTATK_H
#include "../../character/player/player.h"
#include "potion.h"
#include "../playerdecorator.h"
#include <memory>

using namespace std;

class BoostAtk: public PlayerDecorator, public Potion {
	int getTempAmt();
public:
    BoostAtk(shared_ptr<Player> p);
    int getMaxHP() override;
    int getCurHP() override;
    int getAtk() override;
    int getDef() override;
    shared_ptr<Player> getPlayer() override;
};
#endif /* BOOSTATK_H */
