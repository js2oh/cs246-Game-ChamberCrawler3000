#include "temp.h"
#include <math.h>
#include <memory>
#include <string>

using namespace std;

Temp::Temp(ItemType type, int amt) : Potion{amt}, type{type} {}

void Temp::applyEffects(shared_ptr<Player> p) {}

shared_ptr<Player> Temp::makePlayer(shared_ptr<Player> p) {
    shared_ptr<Player> pd;

    switch (type) {
        case ItemType::BA:
            pd = make_shared<BoostAtk>(5, p);
            break;
        case ItemType::BD:
            pd = make_shared<BoostDef>(5, p);
            break;
        case ItemType::WA:
            pd = make_shared<WoundAtk>(5, p);
            break;
        case ItemType::WD:
            pd = make_shared<WoundDef>(5, p);
            break;
    }

    return pd;
}
