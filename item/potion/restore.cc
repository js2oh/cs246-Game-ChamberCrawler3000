#include "restore.h"
#include <memory>
#include "../../board/cell.h"

using namespace std;

Restore::Restore(int amt) : Potion{amt} {}

void Restore::applyEffects(shared_ptr<Player> p) {
    // p->increaseHp(amt);
    // p->usePotion(*this);
}
