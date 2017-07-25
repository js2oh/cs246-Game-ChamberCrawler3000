#include "shade.h"


Shade::Shade(Cell *cell) : Player {cell} {
	race = "Shade";
	hp = 125;
	maxHp = 125;
	atk = 25;
	def = 25;
}