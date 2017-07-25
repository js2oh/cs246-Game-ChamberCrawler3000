#ifndef RESTORE_H
#define RESTORE_H
#include "../item.h"
#include "potion.h"

class Restore : public Potion {
    public:
    Restore(int amt);
    void applyEffects(std::shared_ptr<Player> p);
};

#endif /* RESTORE_H */
