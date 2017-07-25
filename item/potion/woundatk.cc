#include "woundatk.h"
#include <math.h>
#include <memory>
#include <string>

using namespace std;

WoundAtk::WoundAtk(int amt) : Potion{amt} {}

WoundAtk::WoundAtk(int amt, shared_ptr<Player> p)
    : Potion{amt}, PlayerDecorator(p) {}

void WoundAtk::applyEffects(shared_ptr<Player> p) {}

int WoundAtk::getAtk() {
    int new_atk = PlayerDecorator::getAtk() - Potion::getAmt();
    if (new_atk < 0) {
        new_atk = 0;
    }
    return new_atk;
}

int WoundAtk::getDef() {
    int new_def = PlayerDecorator::getDef();
    return new_def;
}

int WoundAtk::getMHP() {
    int new_mhp = PlayerDecorator::getMHP();
    return new_mhp;
}

int WoundAtk::getCHP() {
    int new_chp = PlayerDecorator::getCHP();
    return new_chp;
}

string WoundAtk::getRace() {
    return PlayerDecorator::getRace();
}

void WoundAtk::setCHP(int value) {
    PlayerDecorator::setCHP(value);
}

void WoundAtk::setPlayer(shared_ptr<Player> p) {
    player = p;
}

shared_ptr<Player> WoundAtk::getPlayer() {
    return PlayerDecorator::getPlayer();
}

void WoundAtk::attackOn(Enemy &e) {
    e.defendFrom(this);
}

void WoundAtk::defendFrom(Human *hEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundAtk::defendFrom(Dwarf *wEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundAtk::defendFrom(Elf *eEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundAtk::defendFrom(Orc *oEnemy) {
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

void WoundAtk::defendFrom(Merchant *mEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundAtk::defendFrom(Dragon *dEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void WoundAtk::defendFrom(Halfling *lEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
