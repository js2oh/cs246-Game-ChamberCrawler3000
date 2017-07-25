#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_
#include <memory>
#include <string>
#include "../../character/player/player.h"
#include "../playerdecorator.h"
#include "potion.h"

using namespace std;

class BoostDef: public PlayerDecorator, public Potion {
	public:
    	BoostDef(shared_ptr<Player> p);
    	int getMHP() override;
    	int getCHP() override;
    	int getAtk() override;
    	int getDef() override;
    	string getString() override;
    	void setCHP(int value) override;
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
