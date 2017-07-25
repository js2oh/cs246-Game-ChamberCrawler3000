#include <string>
#include <math.h>
#include "troll.h"
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


int Troll::getMHP() {
    return Player::getMHP();
}
int Troll::getCHP() {
    return Player::getCHP();
}
int Troll::getDef() {
    return Player::getDef();
}
void Troll::setCHP(int value) {
    Player::setCHP(value);
}
int Troll::getAtk() {
    return Player::getAtk();
}
string Troll::getString(){
    return Player::getString();
}
Troll::Troll(){
    Player::setMHP(120);
    Player::setCHP(120);
    Player::setAtk(25);
    Player::setDef(15);
    Player::setString("Troll");
    Player::setGold(0);
}

void Troll::attackOn(Enemy &e){
    e.defendFrom(this);
}

void Troll::defendFrom(Human *hEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Dwarf *wEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Elf *eEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Orc *oEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Merchant *mEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Dragon *dEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Halfling *lEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
