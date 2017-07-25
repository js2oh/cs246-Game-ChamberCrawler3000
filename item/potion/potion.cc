#include "potion.h"
class Player;

const char Potion::SYMBOL = 'P';

// Potion::Potion(Cell *cell) : Item{cell, SYMBOL} {}
void Potion::applyEffects(std::shared_ptr<Player> p) {}

Potion::Potion(int amt) : amt{amt}, Item{SYMBOL} {}
