#include "woundatk.h"
#include <memory>

using namespace std;

WoundAtk::WoundAtk(shared_ptr<Player> p): PlayerDecorator(p){}

int WoundAtk::getMaxHP(){
    int new_mhp = PlayerDecorator::getMaxHP();
    return new_mhp;
}

int WoundAtk::getCurHP(){
    int new_chp = PlayerDecorator::getCurHP();
    return new_chp;
}

int WoundAtk::getAtk(){
    int new_atk = PlayerDecorator::getAtk() - getTempAmt();
    return new_atk;
}

int WoundAtk::getDef(){
    int new_def = PlayerDecorator::getDef();
    return new_def;
}

shared_ptr<Player> WoundAtk::getPlayer(){
    return PlayerDecorator::getPlayer();
}
