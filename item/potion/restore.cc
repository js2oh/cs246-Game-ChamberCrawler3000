#include "restore.h"
#include <memory>

using namespace std;

Restore::Restore(int amt) : Potion{amt} {}

void Restore::applyEffects(shared_ptr<Player> p) {
    if (p->getRace() == "Drow") {
        Potion::setAmt(Potion::getAmt() * 1.5);
    }

    if (p->getMaxHP() == 0 || p->getCHP() + Potion::getAmt() < p->getMHP()) {
        p->setCHP(p->getCHP() + Potion::getAmt());
    }
    else {
        p->setCHP(p->getMHP());
    }
}
