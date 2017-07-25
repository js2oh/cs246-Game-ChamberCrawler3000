#include <string>
#include <math.h>
#include "drow.h"
#include "../chracter.h"
#include "player.h"
#include "../enemy/enemy.h"
#include "../enemy/human.h"
#include "../enemy/dwarf.h"
#include "../enemy/elf.h"
#include "../enemy/orc.h"
#include "../enemy/merchant.h"
#include "../enemy/dragon.h"
#include "../enemy/halfling.h"

using namespace std;

int Drow::getMHP(){
    return Player::getMHP();
}
int Drow::getCHP(){
    return Player::getCHP();
}
int Drow::getDef(){
    return Player::getDef();
}
void Drow::setCHP(int value){
    Player::setCHP(value);
}
int Drow::getAtk(){
    return Player::getAtk();
}
string Drow::getString(){
    return Player::getString();
}
Drow::Drow(){
    Player::setMHP(150);
    Player::setCHP(150);
    Player::setAtk(25);
    Player::setDef(15);
    Player::setString("Drow");
    Player::setGold(0);
}

void Drow::attackOn(Enemy &e){
    e.defendFrom(this);
}

void Drow::defendFrom(Human *hEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Drow::defendFrom(Dwarf *wEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Drow::defendFrom(Elf *eEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Drow::defendFrom(Orc *oEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Drow::defendFrom(Merchant *mEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Drow::defendFrom(Dragon *dEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Drow::defendFrom(Halfling *lEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
