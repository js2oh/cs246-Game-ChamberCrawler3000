#include <memory>
#include "poison.h"

using namespace std;

void Poison::applyEffect(shared_ptr<Player> p){
    if (p->getCHP() - Potion::getPermAmt() <= 0){
        p->setCHP(0);
    }
    else{
        p->setCHP(p->getCHP() - Potion::getPermAmt());
    }
}
