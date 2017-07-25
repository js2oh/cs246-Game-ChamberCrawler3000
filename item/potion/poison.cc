#include "poison.h"
#include <iostream>
#include <memory>
using namespace std;

Poison::Poison(int amt) : Potion{amt} {}

void Poison::applyEffects(shared_ptr<Player> p) {
    if (p->getCHP() - Potion::getAmt() <= 0) {
        p->setCHP(0);
    }
    else {
        cout << "Pre-HP: " << p->getCHP() << endl;
        p->setCHP(p->getCHP() - Potion::getAmt());
        cout << "Post-HP: " << p->getCHP() << endl;
    }
}
