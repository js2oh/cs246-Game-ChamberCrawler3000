#include <memory>
#include "restore.h"

using namespace std;

void Restore::applyEffect(shared_ptr<Player> p){
    if (p->getCHP() + Potion::getPermAmt() >= p->getMHP()){
        p->setCHP(p->getMHP());
    }
    else {
        p->setCHP(p->getCHP() + Potion::getPermAmt());
    }
}
