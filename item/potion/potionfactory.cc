#include "potionfactory.h"
#include "boostatk.h"
#include "boostdef.h"
#include "poison.h"
#include "restore.h"
#include "woundatk.h"
#include "wounddef.h"

using namespace std;

const int PotionFactory::POTION_TYPES = 9;

std::shared_ptr<Item> PotionFactory::manualCreate(char symbol, Cell *cell) {
    shared_ptr<Item> ip;

    switch (symbol) {
        // RH (Perm)
        case '0':
            ip = make_shared<Restore>(10);
            break;
        // BA
        case '1':
            ip = make_shared<BoostAtk>(5);
            break;
        // BD
        case '2':
            ip = make_shared<BoostDef>(5);
            break;
        // PH (Perm)
        case '3':
            ip = make_shared<Poison>(10);
            break;
        // WA
        case '4':
            ip = make_shared<WoundAtk>(5);
            break;
        // WD
        case '5':
            ip = make_shared<WoundDef>(5);
            break;
    }

    return ip;
}

ItemType PotionFactory::genRandType() {
    const int i = rand() % POTION_TYPES;

    switch (i) {
        case 0:
            return ItemType::RH;
        case 1:
            return ItemType::BA;
        case 2:
            return ItemType::BD;
        case 3:
            return ItemType::PH;
        case 4:
            return ItemType::WA;
        case 5:
            return ItemType::WD;
    }
}

shared_ptr<Item> PotionFactory::randomCreate(Cell *cell) {
    shared_ptr<Item> ip;
    ItemType it = genRandType();

    switch (it) {
        // RH (Perm)
        case ItemType::RH:
            ip = make_shared<Restore>(10);
            break;
        // BA
        case ItemType::BA:
            ip = make_shared<BoostAtk>(5);
            break;
        // BD
        case ItemType::BD:
            ip = make_shared<BoostDef>(5);
            break;
        // PH (Perm)
        case ItemType::PH:
            ip = make_shared<Poison>(10);
            break;
        // WA
        case ItemType::WA:
            ip = make_shared<WoundAtk>(5);
            break;
        // WD
        case ItemType::WD:
            ip = make_shared<WoundDef>(5);
            break;
    }
    return ip;
}
