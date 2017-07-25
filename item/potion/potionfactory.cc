#include "potionfactory.h"
#include "temp.h"
using namespace std;

const int PotionFactory::POTION_TYPES = 9;
class Temp;

shared_ptr<Potion> PotionFactory::manualCreate(char symbol, Cell *cell) {
    shared_ptr<Potion> ip;

    switch (symbol) {
        // RH (Perm)
        case '0':
            ip = make_shared<Restore>(10);
            break;
        // BA
        case '1':
            ip = make_shared<Temp>(ItemType::BA, 5);
            break;
        // BD
        case '2':
            ip = make_shared<Temp>(ItemType::BD, 5);
            break;
        // PH (Perm)
        case '3':
            ip = make_shared<Poison>(10);
            break;
        // WA
        case '4':
            ip = make_shared<Temp>(ItemType::WA, 5);
            break;
        // WD
        case '5':
            ip = make_shared<Temp>(ItemType::WD, 5);
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

shared_ptr<Potion> PotionFactory::randomCreate(Cell *cell) {
    shared_ptr<Potion> ip;
    ItemType it = genRandType();

    switch (it) {
        // RH (Perm)
        case ItemType::RH:
            ip = make_shared<Restore>(10);
            break;
        case ItemType::PH:
            ip = make_shared<Poison>(10);
            break;
        // BA
        case ItemType::BA:
        // BD
        case ItemType::BD:
        // WA
        case ItemType::WA:
        // WD
        case ItemType::WD:
            ip = make_shared<Temp>(it, 5);
            break;
    }
    return ip;
}
