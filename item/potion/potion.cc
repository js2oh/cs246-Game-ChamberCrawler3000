#include "potion.h"
#include <memory>
using namespace std;

const char Potion::SYMBOL = 'P';

Potion::Potion(int amt) : Item{SYMBOL}, amt{amt} {}

void Potion::setAmt(int value) {
    amt = value;
}

int Potion::getAmt() {
    return amt;
}
