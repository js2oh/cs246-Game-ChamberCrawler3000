#include "restore.h"
#include <memory>

using namespace std;

Restore::Restore(int amt) : Potion{amt} {}

void Restore::applyEffects(shared_ptr<Player> p) {
    if (p->getCHP() + Potion::getAmt() >= p->getMHP()) {
        p->setCHP(p->getMHP());
    }
    else {
        p->setCHP(p->getCHP() + Potion::getAmt());
    }
}
