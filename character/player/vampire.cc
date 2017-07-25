#include <string>
#include <math.h>
#include "vampire.h"
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

    int Vampire::getMHP() {
        return Player::getMHP();
    }
    int Vampire::getCHP() {
        return Player::getCHP();
    }
    int Vampire::getDef() {
        return Player::getDef();
    }
    void Vampire::setCHP(int value) {
        Player::setCHP(value);
    }
    int Vampire::getAtk() {
        return Player::getAtk();
    }
    string Vampire::getString(){
        return Player::getString();
    }
    Vampire::Vampire(){
        Player::setMHP(50);
        Player::setCHP(50);
        Player::setAtk(25);
        Player::setDef(25);
        Player::setString("Vampire");
        Player::setGold(0);
    }

void Vampire::attackOn(Enemy &e)
{
    e.defendFrom(this);
}

void Vampire::defendFrom(Human *hEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Vampire::defendFrom(Dwarf *wEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Vampire::defendFrom(Elf *eEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Vampire::defendFrom(Orc *oEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Vampire::defendFrom(Merchant *mEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Vampire::defendFrom(Dragon *dEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Vampire::defendFrom(Halfling *lEnemy){
    int damage = ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
