#include <memory>
#include <string>
#include <math.h>
#include "wounddef.h"

using namespace std;

WoundDef::WoundDef(shared_ptr<Player> p): PlayerDecorator(p){}
 
int WoundDef::getAtk(){
    int new_atk = PlayerDecorator::getAtk();
    return new_atk;
}

int WoundDef::getDef(){
    int new_def = PlayerDecorator::getDef() - Potion::getTempAmt();
    if (new_def < 0){
        new_def = 0;
    }
    return new_def;
}

int WoundDef::getMHP(){
    int new_mhp = PlayerDecorator::getMHP();
    return new_mhp;
}

int WoundDef::getCHP(){
    int new_chp = PlayerDecorator::getCHP();
    return new_chp;
}

string WoundDef::getString(){
    return PlayerDecorator::getString();
}

void WoundDef::setCHP(int value) {
    PlayerDecorator::setCHP(value);
}

shared_ptr<Player> WoundDef::getPlayer(){
    return PlayerDecorator::getPlayer();
}

void WoundDef::attackOn(Enemy &e){
	e.defendFrom(this);
}

void WoundDef::defendFrom(Human *hEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundDef::defendFrom(Dwarf *wEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundDef::defendFrom(Elf *eEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundDef::defendFrom(Orc *oEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    if(this->getString() == "Goblin"){
        damage *= 1.5;
    }
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundDef::defendFrom(Merchant *mEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundDef::defendFrom(Dragon *dEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundDef::defendFrom(Halfling *lEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
