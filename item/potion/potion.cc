#include "potion.h"
#include <memory>
using namespace std;

Potion::Potion(int amt) : amt{amt} {}

void Potion::setAmt(int value) {
    amt = value;
}

int Potion::getAmt() {
    return amt;
}

void Potion::applyEffects(shared_ptr<Player> p) {}
