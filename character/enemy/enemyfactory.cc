#include "enemyfactory.h"
#include "../character.h"
#include "dragon.h"
#include "dwarf.h"
#include "elf.h"
#include "halfling.h"
#include "human.h"
#include "merchant.h"
#include "orc.h"

using namespace std;

const int EnemyFactory::PROB_DENOM = 18;

std::shared_ptr<Character> EnemyFactory::manualCreate(char symbol, Cell *cell) {
    shared_ptr<Character> cp;

    switch (symbol) {
        // Human
        case 'H':
            cp = make_shared<Human>(cell);
            break;
        // Dwarf
        case 'W':
            cp = make_shared<Dwarf>(cell);
            break;
        // Elf
        case 'E':
            cp = make_shared<Elf>(cell);
            break;
        // Orc
        case 'O':
            cp = make_shared<Orc>(cell);
            break;
        // Merchant
        case 'M':
            cp = make_shared<Merchant>(cell);
            break;
        // Dragon
        case 'D':
            cp = make_shared<Dragon>(cell);
            break;
        // Halfling
        case 'L':
            cp = make_shared<Halfling>(cell);
            break;
    }

    return cp;
}

char EnemyFactory::genRandType() {
    const int i = rand() % PROB_DENOM + 1;

    if (i <= 4) {
        return 'H';
    }
    else if (i <= 7) {
        return 'W';
    }
    else if (i <= 12) {
        return 'L';
    }
    else if (i <= 14) {
        return 'E';
    }
    else if (i <= 16) {
        return 'O';
    }
    else {
        return 'M';
    }
}

shared_ptr<Character> EnemyFactory::randomCreate(Cell *cell) {
    char symbol = genRandType();
    return manualCreate(symbol, cell);
}
