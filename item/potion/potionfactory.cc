#include "potionfactory.h"
#include "boostatk.h"
#include "restore.h"
using namespace std;

std::shared_ptr<Item> PotionFactory::create(char symbol, Cell *cell) {
    return createItem(ItemType::RH, cell);
}

shared_ptr<Item> PotionFactory::createItem(ItemType it, Cell *cell) {
    shared_ptr<Item> ip;
    switch (it) {
        case RH:
            // return new Restore();
            ip = make_shared<Restore>();
            return ip;
    }
}
