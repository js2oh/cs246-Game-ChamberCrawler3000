#include "player.h"
#include <string>
#include "../character.h"

using namespace std;

const char Player::SYMBOL = '@';

Player::Player(Cell *c, string race) : Character{c, SYMBOL}, race{race} {
    gold = 0;
}
Player::Player() : Character{SYMBOL} {}

int Player::getMHP() {
    return maxHP;
}
int Player::getCHP() {
    return curHP;
}
int Player::getAtk() {
    return atk;
}
int Player::getDef() {
    return def;
}
string Player::getRace() {
    return race;
}
void Player::setCHP(int value) {
    curHP = value;
}
int Player::getGold() {
    return gold;
}
void Player::setMHP(int value) {
    maxHP = value;
}
void Player::setAtk(int value) {
    atk = value;
}
void Player::setDef(int value) {
    def = value;
}
void Player::setRace(string value) {
    race = value;
}
void Player::setGold(int value) {
    gold = value;
}
