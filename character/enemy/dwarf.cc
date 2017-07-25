#include "dwarf.h"
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

const char Dwarf::SYMBOL = 'W';

int Dwarf::getMHP() {
    return Enemy::getMHP();
}
int Dwarf::getCHP() {
    return Enemy::getCHP();
}
int Dwarf::getAtk() {
    return Enemy::getAtk();
}
int Dwarf::getDef() {
    return Enemy::getDef();
}
void Dwarf::setCHP(int value) {
    Enemy::setCHP(value);
}

Dwarf::Dwarf(Cell *c) : Enemy{c, SYMBOL} {
    Enemy::setMHP(100);
    Enemy::setCHP(100);
    Enemy::setAtk(20);
    Enemy::setDef(30);
}
void Dwarf::defendFrom(Shade *sPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (sPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
void Dwarf::defendFrom(Drow *dPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (dPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}
void Dwarf::defendFrom(Vampire *vPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (vPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    int curHP = vPlayer->getCHP();
    if (curHP - 5 <= 0) {
        // game over condition for vampire -5 hp
        curHP = 0;
    }
    else {
        curHP -= 5;
    }
    vPlayer->setCHP(curHP);
    this->setCHP(remainingHP);
}
void Dwarf::defendFrom(Troll *tPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (tPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
    }
    this->setCHP(remainingHP);
}

void Dwarf::defendFrom(Goblin *gPlayer) {
    int damage =
        ceil((100 / (100 + (double)(this->getDef()))) * (gPlayer->getAtk()));
    int remainingHP = this->getCHP() - damage;
    if (remainingHP <= 0) {
        remainingHP = 0;
        gPlayer->setGold(gPlayer->getGold() + 5);
    }
    this->setCHP(remainingHP);
}
void Dwarf::defendFrom(BoostAtk *baPlayer) {
    string baseType = baPlayer->getString();
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
        if (curHP - 5 <= 0) {
            // game over condition for vampire -5 hp
            curHP = 0;
        }
        else {
            curHP -= 5;
        }
        baPlayer->setCHP(curHP);
    }
    this->setCHP(remainingHP);
}
void Dwarf::defendFrom(BoostDef *bdPlayer) {
    string baseType = bdPlayer->getString();
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
        if (curHP - 5 <= 0) {
            // game over condition for vampire -5 hp
            curHP = 0;
        }
        else {
            curHP -= 5;
        }
        bdPlayer->setCHP(curHP);
    }
    this->setCHP(remainingHP);
}
void Dwarf::defendFrom(WoundAtk *waPlayer) {
    string baseType = waPlayer->getString();
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
        if (curHP - 5 <= 0) {
            // game over condition for vampire -5 hp
            curHP = 0;
        }
        else {
            curHP -= 5;
        }
        waPlayer->setCHP(curHP);
    }
    this->setCHP(remainingHP);
}
void Dwarf::defendFrom(WoundDef *wdPlayer) {
    string baseType = wdPlayer->getString();
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
        if (curHP - 5 <= 0) {
            // game over condition for vampire -5 hp
            curHP = 0;
        }
        else {
            curHP -= 5;
        }
        wdPlayer->setCHP(curHP);
    }
    this->setCHP(remainingHP);
}
void Dwarf::attackOn(Player &p) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        p.defendFrom(this);
    }
}
