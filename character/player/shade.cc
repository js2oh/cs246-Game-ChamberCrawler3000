#include <math.h>
#include <string>
#include "shade.h"
#include "../enemy/dragon.h"
#include "../enemy/dwarf.h"
#include "../enemy/elf.h"
#include "../enemy/enemy.h"
#include "../enemy/halfling.h"
#include "../enemy/human.h"
#include "../enemy/merchant.h"
#include "../enemy/orc.h"
#include "player.h"


using namespace std;

int Shade::getMHP() {
    return Player::getMHP();
}
int Shade::getCHP() {
    return Player::getCHP();
}
int Shade::getDef() {
    return Player::getDef();
}
void Shade::setCHP(int value) {
    Player::setCHP(value);
}
int Shade::getAtk() {
    return Player::getAtk();
}
string Shade::getString() {
    return Player::getString();
}

Shade::Shade(Cell *c) : Player{c} {
    Player::setMHP(125);
    Player::setCHP(125);
    Player::setAtk(25);
    Player::setDef(25);
    Player::setString("Shade");
    Player::setGold(0);
}

void Shade::attackOn(Enemy &e) {
    e.defendFrom(this);
}

void Shade::defendFrom(Human *hEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Shade::defendFrom(Dwarf *wEnemy) {
    int damage =
        ceil((100 / (double)(100 + (this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Shade::defendFrom(Elf *eEnemy) {
    int damage =
        ceil((100 / (double)(100 + (this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Shade::defendFrom(Orc *oEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Shade::defendFrom(Merchant *mEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Shade::defendFrom(Dragon *dEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Shade::defendFrom(Halfling *lEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}