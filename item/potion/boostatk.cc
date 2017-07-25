#include "boostatk.h"
#include <math.h>
#include <memory>
#include <string>

using namespace std;

BoostAtk::BoostAtk(int amt, shared_ptr<Player> p)
    : Potion{amt}, PlayerDecorator(p) {}

BoostAtk::BoostAtk(int amt) : Potion{amt} {}

int BoostAtk::getAtk() {
    int new_atk = PlayerDecorator::getAtk() + Potion::getAmt();
    return new_atk;
}

int BoostAtk::getDef() {
    int new_def = PlayerDecorator::getDef();
    return new_def;
}

int BoostAtk::getMHP() {
    int new_mhp = PlayerDecorator::getMHP();
    return new_mhp;
}

int BoostAtk::getCHP() {
    int new_chp = PlayerDecorator::getCHP();
    return new_chp;
}

string BoostAtk::getString() {
    return PlayerDecorator::getString();
}

void BoostAtk::setCHP(int value) {
    PlayerDecorator::setCHP(value);
}

shared_ptr<Player> BoostAtk::getPlayer() {
    return PlayerDecorator::getPlayer();
}

void BoostAtk::attackOn(Enemy &e) {
    e.defendFrom(this);
}

void BoostAtk::defendFrom(Human *hEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostAtk::defendFrom(Dwarf *wEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostAtk::defendFrom(Elf *eEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostAtk::defendFrom(Orc *oEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    if (this->getString() == "Goblin") {
        damage *= 1.5;
    }
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostAtk::defendFrom(Merchant *mEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostAtk::defendFrom(Dragon *dEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void BoostAtk::defendFrom(Halfling *lEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
