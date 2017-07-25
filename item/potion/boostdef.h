#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_
#include <memory>
#include <string>
#include "../../character/enemy/dragon.h"
#include "../../character/enemy/dwarf.h"
#include "../../character/enemy/elf.h"
#include "../../character/enemy/enemy.h"
#include "../../character/enemy/halfling.h"
#include "../../character/enemy/human.h"
#include "../../character/enemy/merchant.h"
#include "../../character/enemy/orc.h"
#include "../../character/player/player.h"
#include "../playerdecorator.h"
#include "potion.h"

using namespace std;

class BoostDef : public PlayerDecorator {
    public:
    BoostDef(int amt, shared_ptr<Player> p);

    int getMHP() override;
    int getCHP() override;
    int getAtk() override;
    int getDef() override;
    string getRace() override;
    void setCHP(int value) override;
    void setPlayer(shared_ptr<Player> p);
    shared_ptr<Player> getPlayer() override;
    void attackOn(Enemy &e);
    void defendFrom(Human *hEnemy);
    void defendFrom(Dwarf *wEnemy);
    void defendFrom(Elf *eEnemy);
    void defendFrom(Orc *oEnemy);
    void defendFrom(Merchant *mEnemy);
    void defendFrom(Dragon *dEnemy);
    void defendFrom(Halfling *lEnemy);
};

#endif
