#ifndef POISON_H
#define POISON_H
#include <memory>
#include "../../character/player/player.h"
#include "../item.h"
#include "potion.h"

using namespace std;

class Player;

class Poison : public Potion {
    public:
    Poison(int amt);
    void applyEffects(shared_ptr<Player> p) override;
};

#endif
