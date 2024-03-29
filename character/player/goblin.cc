#include "goblin.h"
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

int Goblin::getMHP() {
    return Player::getMHP();
}
int Goblin::getCHP() {
    return Player::getCHP();
}
int Goblin::getDef() {
    return Player::getDef();
}
void Goblin::setCHP(int value) {
    Player::setCHP(value);
}
int Goblin::getAtk() {
    return Player::getAtk();
}

Goblin::Goblin(Cell *c) : Player{c, "Goblin"} {
    Player::setMHP(110);
    Player::setCHP(110);
    Player::setAtk(15);
    Player::setDef(20);
    Player::setGold(0);
}

void Goblin::attackOn(Enemy &e) {
    e.defendFrom(this);
}

void Goblin::defendFrom(Human *hEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (hEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Goblin::defendFrom(Dwarf *wEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (wEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Goblin::defendFrom(Elf *eEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (eEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Goblin::defendFrom(Orc *oEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (oEnemy->getAtk()));
    damage *= 1.5;
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Goblin::defendFrom(Merchant *mEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (mEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Goblin::defendFrom(Dragon *dEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (dEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Goblin::defendFrom(Halfling *lEnemy) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (lEnemy->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
