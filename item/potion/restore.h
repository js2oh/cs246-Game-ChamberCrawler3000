#ifndef RESTORE_H
#define RESTORE_H
#include <memory>
#include "../../character/player/player.h"
#include "../item.h"
#include "potion.h"

using namespace std;

class Player;

class Restore : public Potion {
    public:
    Restore(int amt);
    void applyEffects(shared_ptr<Player> p) override;
};

#endif
