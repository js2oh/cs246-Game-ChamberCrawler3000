#ifndef TEMP_H
#define TEMP_H
#include <memory>
#include <string>
#include "../../character/player/player.h"
#include "../item.h"
#include "../itemtype.h"
#include "../playerdecorator.h"
#include "boostatk.h"
#include "boostdef.h"
#include "potion.h"
#include "woundatk.h"
#include "wounddef.h"

using namespace std;

class PlayerDecorator;
class Player;

class Temp : public Potion {
    ItemType type;

    public:
    Temp(ItemType type, int amt);
    void applyEffects(shared_ptr<Player> p) override;
    shared_ptr<Player> makePlayer(shared_ptr<Player> p) override;
};

#endif
