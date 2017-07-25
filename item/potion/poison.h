#ifndef POISON_H
#define POISON_H
#include "../item.h"
#include "potion.h"

class Poison : public Potion {
    int amt;

    public:
    Poison(int amt);
    void applyEffects(std::shared_ptr<Player> p);
};

#endif /* POISON_H */
