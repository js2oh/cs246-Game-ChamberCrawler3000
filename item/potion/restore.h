#ifndef RESTORE_H
#define RESTORE_H
#include "../item.h"
#include "potion.h"
class Restore: public Potion {
	public:
	Restore();
	void applyEffects();
};
#endif /* RESTORE_H */
