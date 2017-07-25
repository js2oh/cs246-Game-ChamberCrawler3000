#include "boostdef.h"
#include <memory>

using namespace std;

BoostDef::BoostDef(int amt) : Potion{amt} {}

BoostDef::BoostDef(int amt, shared_ptr<Player> p)
    : Potion{amt}, PlayerDecorator(p) {}

int BoostDef::getMaxHP() {
    int new_mhp = PlayerDecorator::getMaxHP();
    return new_mhp;
}

int BoostDef::getCurHP() {
    int new_chp = PlayerDecorator::getCurHP();
    return new_chp;
}

int BoostDef::getAtk() {
    int new_atk = PlayerDecorator::getAtk();
    return new_atk;
}

int BoostDef::getDef() {
    int new_def = PlayerDecorator::getDef() + getTempAmt();
    return new_def;
}

shared_ptr<Player> BoostDef::getPlayer() {
    return PlayerDecorator::getPlayer();
}

int BoostDef::getTempAmt() {
    // if player is drow return 10 * 1.5
    return 10;
}