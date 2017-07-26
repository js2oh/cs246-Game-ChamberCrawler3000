#include "gold.h"
#include "../../character/player/player.h"
Gold::Gold(ItemType it, Cell *cell) : Item (it)
{
	symbol = 'G';
	this->cell = cell;
	switch (it) {
		case SH:
			value = 1;
		case NH:
			value = 2;
		case MH:
			value = 4;
		case DH:
			value = 6;
	}
} 
void Gold::applyEffects(std::shared_ptr <Player> p) {
	p->setGold(p->getGold()+ value) ;
}
