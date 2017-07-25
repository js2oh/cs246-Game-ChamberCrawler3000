#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "../character.h"

using namespace std;

class Enemy;
class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Dragon;
class Halfling;

class Player : public Character {
    const static char SYMBOL;

    int maxHP;
    int curHP;
    int atk;
    int def;
    int gold;
    string type;

    public:
    Player(Cell *c);
    Player();
    virtual int getMHP();
    virtual int getCHP();
    virtual int getAtk();
    virtual int getDef();
    virtual string getString();
    virtual void setCHP(int value);
    int getGold();
    void setMHP(int value);
    void setAtk(int value);
    void setDef(int value);
    void setString(string value);
    void setGold(int value);
    virtual void attackOn(Enemy &e) = 0;
    virtual void defendFrom(Human *hEnemy) = 0;
    virtual void defendFrom(Dwarf *wEnemy) = 0;
    virtual void defendFrom(Elf *eEnemy) = 0;
    virtual void defendFrom(Orc *oEnemy) = 0;
    virtual void defendFrom(Merchant *mEnemy) = 0;
    virtual void defendFrom(Dragon *dEnemy) = 0;
    virtual void defendFrom(Halfling *lEnemy) = 0;
};

#endif
