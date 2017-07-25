#ifndef POISON_H
#define POISON_H
#include <memory>
#include "../item.h"
#include "potion.h"

class Poison : public Potion {
    public:
    Poison(int amt);
    void applyEffects(std::shared_ptr<Player> p) override;
};

#endif /* POISON_H */
