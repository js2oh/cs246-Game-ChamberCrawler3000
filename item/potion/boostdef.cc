#include "boostdef.h"
#include <math.h>
#include <memory>
#include <string>

using namespace std;

BoostDef::BoostDef(int amt, shared_ptr<Player> p) : PlayerDecorator(amt, p) {}

int BoostDef::getAtk() {
    int new_atk = PlayerDecorator::getAtk();
    return new_atk;
}

int BoostDef::getDef() {
    int new_def = PlayerDecorator::getDef() + PlayerDecorator::getAmt();
    return new_def;
}

int BoostDef::getMHP() {
    int new_mhp = PlayerDecorator::getMHP();
    return new_mhp;
}

int BoostDef::getCHP() {
    int new_chp = PlayerDecorator::getCHP();
    return new_chp;
}

string BoostDef::getRace() {
    return PlayerDecorator::getRace();
}

void BoostDef::setCHP(int value) {
    PlayerDecorator::setCHP(value);
}

void BoostDef::setPlayer(shared_ptr<Player> p) {
    player = p;
}

shared_ptr<Player> BoostDef::getPlayer() {
    return PlayerDecorator::getPlayer();
}

void BoostDef::attackOn(Enemy &e) {
    e.defendFrom(this);
}

void BoostDef::defendFrom(Human *hEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostDef::defendFrom(Dwarf *wEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostDef::defendFrom(Elf *eEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostDef::defendFrom(Orc *oEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    if (this->getRace() == "Goblin") {
        damage *= 1.5;
    }
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostDef::defendFrom(Merchant *mEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostDef::defendFrom(Dragon *dEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostDef::defendFrom(Halfling *lEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
