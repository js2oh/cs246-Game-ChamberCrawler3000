#include <memory>
#include <string>
#include "playerdecorator.h"

using namespace std;

PlayerDecorator::PlayerDecorator(shared_ptr<Player> p): player{p} {}

int PlayerDecorator::getMHP() {return player->getMaxHP();}

int PlayerDecorator::getCHP() {return player->getCurHP();}

int PlayerDecorator::getAtk() {return player->getAtk();}

int PlayerDecorator::getDef() {return player->getDef();}

string PlayerDecorator::getString() {return player->getString();}

void PlayerDecorator::setCHP(int value) {player->setCHP(value);}

shared_ptr<Player> PlayerDecorator::getPlayer() {return player;}
