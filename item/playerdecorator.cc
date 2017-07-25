#include "playerdecorator.h"
#include <memory>
#include <string>

using namespace std;

PlayerDecorator::PlayerDecorator() {}
PlayerDecorator::PlayerDecorator(shared_ptr<Player> p) : player{p} {}

int PlayerDecorator::getMHP() {
    return player->getMaxHP();
}

int PlayerDecorator::getCHP() {
    return player->getCurHP();
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
