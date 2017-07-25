#include "troll.h"
#include <math.h>
#include <string>
#include "../character.h"
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

Troll::Troll(Cell *c) : Player{c, "Troll"} {
    Player::setMHP(120);
    Player::setCHP(120);
    Player::setAtk(25);
    Player::setDef(15);
    Player::setGold(0);
}

void Troll::attackOn(Enemy &e) {
    e.defendFrom(this);
}

void Troll::defendFrom(Human *hEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Dwarf *wEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Elf *eEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Orc *oEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Merchant *mEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Dragon *dEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Troll::defendFrom(Halfling *lEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
