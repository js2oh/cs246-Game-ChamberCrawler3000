#include "boostatk.h"
#include <memory>

using namespace std;

BoostAtk::BoostAtk(int amt) : Potion{amt} {}

BoostAtk::BoostAtk(int amt, shared_ptr<Player> p)
    : Potion{amt}, PlayerDecorator(p) {}

int BoostAtk::getMaxHP() {
    int new_mhp = PlayerDecorator::getMaxHP();
    return new_mhp;
}

int BoostAtk::getCurHP() {
    int new_chp = PlayerDecorator::getCurHP();
    return new_chp;
}

int BoostAtk::getAtk() {
    int new_atk = PlayerDecorator::getAtk() + getTempAmt();
    return new_atk;
}

int BoostAtk::getDef() {
    int new_def = PlayerDecorator::getDef();
    return new_def;
}

shared_ptr<Player> BoostAtk::getPlayer() {
    return PlayerDecorator::getPlayer();
}

int BoostAtk::getTempAmt() {
    // if player is drow return 10 * 1.5
    return 10;
}

// void BoostAtk::applyEffects() {}