#include "gold.h"
#include "../../character/player/player.h"
Gold::Gold(ItemType it, Cell *cell) : Item (it)
{
	symbol = 'G';
	this->cell = cell;
	switch (it) {
		case SH:
			value = 1;
			break;
		case NH:
			value = 2;
			break;
		case MH:
			value = 4;
			break;
		case DH:
			value = 6;
			break;
	}
} 
void Gold::applyEffects(std::shared_ptr <Player> p) {
	p->setGold(p->getGold()+ value) ;
	cout << "Picked up " << value << " gold. Total: " << p->getGold() << endl;
	
	
}