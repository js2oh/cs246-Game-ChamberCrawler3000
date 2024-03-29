#include "enemy.h"
#include "../character.h"

Enemy::Enemy(Cell *c, char symbol) : Character{c, symbol}, moves{0} {}

int Enemy::getMoves() const {
    return moves;
}

void Enemy::increaseMoves() {
    ++moves;
}

int Enemy::getMHP() {
    return maxHP;
}
int Enemy::getCHP() {
    return curHP;
}
int Enemy::getAtk() {
    return atk;
}
int Enemy::getDef() {
    return def;
}
void Enemy::setCHP(int value) {
    curHP = value;
}
void Enemy::setMHP(int value) {
    maxHP = value;
}
void Enemy::setAtk(int value) {
    atk = value;
}
void Enemy::setDef(int value) {
    def = value;
}
