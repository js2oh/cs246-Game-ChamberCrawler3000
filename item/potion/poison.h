#ifndef POISON_H
#define POISON_H
#include <memory>
#include "../item.h"
#include "potion.h"

using namespace std;

class Player;

class Poison: public Potion{
    public:
    Poison();
    void applyEffect(shared_ptr<Player> p);
};

#endif
