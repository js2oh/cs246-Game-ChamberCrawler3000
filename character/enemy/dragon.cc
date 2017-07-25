#include "dragon.h"
#include <math.h>
#include <stdlib.h>
#include <string>
#include "../../item/potion/boostatk.h"
#include "../../item/potion/boostdef.h"
#include "../../item/potion/woundatk.h"
#include "../../item/potion/wounddef.h"
#include "../character.h"
#include "../player/drow.h"
#include "../player/goblin.h"
#include "../player/player.h"
#include "../player/shade.h"
#include "../player/troll.h"
#include "../player/vampire.h"
#include "enemy.h"

using namespace std;

const char Dragon::SYMBOL = 'D';

int Dragon::getMHP() {
    return Enemy::getMHP();
}
int Dragon::getCHP() {
    return Enemy::getCHP();
}
int Dragon::getAtk() {
    return Enemy::getAtk();
}
int Dragon::getDef() {
    return Enemy::getDef();
}
void Dragon::setCHP(int value) {
    Enemy::setCHP(value);
}

Dragon::Dragon(Cell *c) : Enemy{c, SYMBOL} {
    Enemy::setMHP(150);
    Enemy::setCHP(150);
    Enemy::setAtk(20);
    Enemy::setDef(20);
}
void Dragon::defendFrom(Shade *sPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (sPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
void Dragon::defendFrom(Drow *dPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (dPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
void Dragon::defendFrom(Vampire *vPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (vPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    int curHP = vPlayer->getCHP();
    int maxHP = vPlayer->getMHP();
    if (curHP < maxHP) {
        if (curHP + 5 > maxHP) {
            curHP = maxHP;
        }
        else {
            curHP += 5;
        }
    }
    vPlayer->setCHP(curHP);
    this->setCHP(remainingHP);
}
void Dragon::defendFrom(Troll *tPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (tPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Dragon::defendFrom(Goblin *gPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (gPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
        gPlayer->setGold(gPlayer->getGold() + 5);
    }
    this->setCHP(remainingHP);
}

void Dragon::defendFrom(BoostAtk *baPlayer) {
    string baseType = baPlayer->getRace();
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (baPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
        if (baseType == "Goblin") {
            baPlayer->setGold(baPlayer->getGold() + 5);
        }
    }
    if (baseType == "Vampire") {
        int curHP = baPlayer->getCHP();
        int maxHP = baPlayer->getMHP();
        if (curHP < maxHP) {
            if (curHP + 5 > maxHP) {
                curHP = maxHP;
            }
            else {
                curHP += 5;
            }
        }
        baPlayer->setCHP(curHP);
    }
    this->setCHP(remainingHP);
}
void Dragon::defendFrom(BoostDef *bdPlayer) {
    string baseType = bdPlayer->getRace();
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (bdPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
        if (baseType == "Goblin") {
            bdPlayer->setGold(bdPlayer->getGold() + 5);
        }
    }
    if (baseType == "Vampire") {
        int curHP = bdPlayer->getCHP();
        int maxHP = bdPlayer->getMHP();
        if (curHP < maxHP) {
            if (curHP + 5 > maxHP) {
                curHP = maxHP;
            }
            else {
                curHP += 5;
            }
        }
        bdPlayer->setCHP(curHP);
    }
    this->setCHP(remainingHP);
}
void Dragon::defendFrom(WoundAtk *waPlayer) {
    string baseType = waPlayer->getRace();
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (waPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
        if (baseType == "Goblin") {
            waPlayer->setGold(waPlayer->getGold() + 5);
        }
    }
    if (baseType == "Vampire") {
        int curHP = waPlayer->getCHP();
        int maxHP = waPlayer->getMHP();
        if (curHP < maxHP) {
            if (curHP + 5 > maxHP) {
                curHP = maxHP;
            }
            else {
                curHP += 5;
            }
        }
        waPlayer->setCHP(curHP);
    }
    this->setCHP(remainingHP);
}
void Dragon::defendFrom(WoundDef *wdPlayer) {
    string baseType = wdPlayer->getRace();
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (wdPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
        if (baseType == "Goblin") {
            wdPlayer->setGold(wdPlayer->getGold() + 5);
        }
    }
    if (baseType == "Vampire") {
        int curHP = wdPlayer->getCHP();
        int maxHP = wdPlayer->getMHP();
        if (curHP < maxHP) {
            if (curHP + 5 > maxHP) {
                curHP = maxHP;
            }
            else {
                curHP += 5;
            }
        }
        wdPlayer->setCHP(curHP);
    }
    this->setCHP(remainingHP);
}
void Dragon::attackOn(Player &p) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        p.defendFrom(this);
    }
}
