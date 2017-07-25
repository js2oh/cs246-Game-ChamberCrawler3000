#include "poison.h"
#include <memory>
#include "../../board/cell.h"

using namespace std;

Poison::Poison(int amt) : amt{amt} {}

void Poison::applyEffects(shared_ptr<Player> p) {
    // p->decreaseHp(amt);
    // p->usePotion(*this);
}
