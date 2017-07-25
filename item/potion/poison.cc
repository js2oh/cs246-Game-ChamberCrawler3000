#include "poison.h"
#include "../../board/cell.h"

using namespace std;

class Player;

Poison::Poison(int amt) : Potion{amt} {}

void Poison::applyEffects(shared_ptr<Player> p) {
    // p->decreaseHp(amt);
    // p->usePotion(*this);
}
