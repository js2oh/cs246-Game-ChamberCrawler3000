#ifndef VAMPIRE_H
#define VAMPIRE_H
#include <string>
#include "../chracter.h"
#include "player.h"

using namespace std;

class Enemy;
class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Dragon;
class Halfling;

class Vampire: public Player{
    public:
    int getMHP();
    int getCHP();
    int getDef();
    void setCHP(int value);
    int getAtk();
    string getString();
    Vampire();
    void attackOn(Enemy &e);
    void defendFrom(Human *hEnemy);
    void defendFrom(Dwarf *wEnemy);
    void defendFrom(Elf *eEnemy);
    void defendFrom(Orc *oEnemy);
    void defendFrom(Merchant *mEnemy);
    void defendFrom(Dragon *dEnemy);
    void defendFrom(Halfling *lEnemy);
};

#endif
