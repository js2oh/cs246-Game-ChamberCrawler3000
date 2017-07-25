#include "halfling.h"
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

const char Halfling::SYMBOL = 'L';

int Halfling::getMHP() {
    return Enemy::getMHP();
}
int Halfling::getCHP() {
    return Enemy::getCHP();
}
int Halfling::getAtk() {
    return Enemy::getAtk();
}
int Halfling::getDef() {
    return Enemy::getDef();
}
void Halfling::setCHP(int value) {
    Enemy::setCHP(value);
}
Halfling::Halfling(Cell *c) : Enemy{c, SYMBOL} {
    Enemy::setMHP(100);
    Enemy::setCHP(100);
    Enemy::setAtk(15);
    Enemy::setDef(20);
}
void Halfling::defendFrom(Shade *sPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (sPlayer->getAtk()));
        int remainingHP = this->getCHP() - damage;
        if (remainingHP <= 0) {
            remainingHP = 0;
        }
        this->setCHP(remainingHP);
    }
}
void Halfling::defendFrom(Drow *dPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (dPlayer->getAtk()));
        int remainingHP = this->getCHP() - damage;
        if (remainingHP <= 0) {
            remainingHP = 0;
        }
        this->setCHP(remainingHP);
    }
}
void Halfling::defendFrom(Vampire *vPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (vPlayer->getAtk()));
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
}
void Halfling::defendFrom(Troll *tPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (tPlayer->getAtk()));
        int remainingHP = this->getCHP() - damage;
        if (remainingHP <= 0) {
            remainingHP = 0;
        }
        this->setCHP(remainingHP);
    }
}
void Halfling::defendFrom(Goblin *gPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (gPlayer->getAtk()));
        int remainingHP = this->getCHP() - damage;
        if (remainingHP <= 0) {
            remainingHP = 0;
            gPlayer->setGold(gPlayer->getGold() + 5);
        }
        this->setCHP(remainingHP);
    }
}
void Halfling::defendFrom(BoostAtk *baPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        string baseType = baPlayer->getRace();
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (baPlayer->getAtk()));
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
}
void Halfling::defendFrom(BoostDef *bdPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        string baseType = bdPlayer->getRace();
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (bdPlayer->getAtk()));
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
}
void Halfling::defendFrom(WoundAtk *waPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        string baseType = waPlayer->getRace();
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (waPlayer->getAtk()));
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
}
void Halfling::defendFrom(WoundDef *wdPlayer) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        string baseType = wdPlayer->getRace();
        int damage = ceil((100 / (100 + (double)(this->getDef()))) *
                          (wdPlayer->getAtk()));
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
}
void Halfling::attackOn(Player &p) {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        p.defendFrom(this);
    }
}
