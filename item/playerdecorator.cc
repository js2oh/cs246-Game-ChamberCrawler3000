
#include "playerdecorator.h"
#include <memory>

using namespace std;

PlayerDecorator::PlayerDecorator(shared_ptr<Player> p) : player{p} {}

PlayerDecorator::PlayerDecorator() {}

int PlayerDecorator::getMaxHP() {
    return player->getMaxHP();
}

int PlayerDecorator::getCurHP() {
    return player->getCurHP();
}

int PlayerDecorator::getAtk() {
    return player->getAtk();
}

int PlayerDecorator::getDef() {
    return player->getDef();
}

shared_ptr<Player> PlayerDecorator::getPlayer() {
    return player;
}
