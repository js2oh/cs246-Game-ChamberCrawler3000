#include "playerdecorator.h"
#include <memory>
#include <string>

using namespace std;

PlayerDecorator::PlayerDecorator() {}
PlayerDecorator::PlayerDecorator(int amt, shared_ptr<Player> p)
    : Player{p->getCell(), p->getRace()}, amt{amt}, player{p} {}

int PlayerDecorator::getMHP() {
    return player->getMaxHP();
}

int PlayerDecorator::getCHP() {
    return player->getCHP();
}

int PlayerDecorator::getAtk() {
    return player->getAtk();
}

int PlayerDecorator::getDef() {
    return player->getDef();
}

string PlayerDecorator::getRace() {
    return player->getRace();
}

void PlayerDecorator::setCHP(int value) {
    player->setCHP(value);
}

shared_ptr<Player> PlayerDecorator::getPlayer() {
    return player;
}

int PlayerDecorator::getAmt() {
    return amt;
}
