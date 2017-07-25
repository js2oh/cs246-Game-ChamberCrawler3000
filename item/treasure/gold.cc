#include "gold.h"

Gold::Gold(ItemType it, Cell *cell) : Item (it)
{
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