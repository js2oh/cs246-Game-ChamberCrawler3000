#include "wounddef.h"
#include <memory>

using namespace std;

WoundDef::WoundDef(shared_ptr<Player> p): PlayerDecorator(p){}

int WoundDef::getMaxHP(){
    int new_mhp = PlayerDecorator::getMaxHP();
    return new_mhp;
}

int WoundDef::getCurHP(){
    int new_chp = PlayerDecorator::getCurHP();
    return new_chp;
}

int WoundDef::getAtk(){
    int new_atk = PlayerDecorator::getAtk();
    return new_atk;
}

int WoundDef::getDef(){
    int new_def = PlayerDecorator::getDef() - getTempAmt();
    return new_def;
}

shared_ptr<Player> WoundDef::getPlayer(){
    return PlayerDecorator::getPlayer();
}
int WoundDef::getTempAmt() {
	//if player is drow return 10 * 1.5
	return 10;
}