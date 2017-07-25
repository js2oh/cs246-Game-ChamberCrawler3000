#include "../character.h"
#include "enemy.h"

int Enemy::getMHP() {return maxHP;}
int Enemy::getCHP() {return curHP;}
int Enemy::getAtk() {return atk;}
int Enemy::getDef() {return def;}
void Enemy::setCHP(int value) {curHP = value;}
void Enemy::setMHP(int value) {maxHP = value;}
void Enemy::setAtk(int value) {atk = value;}
void Enemy::setDef(int value) {def = value;}
