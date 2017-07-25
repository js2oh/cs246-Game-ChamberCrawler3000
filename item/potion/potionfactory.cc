#include "potionfactory.h"
#include "boostatk.h"
using namespace std;

Item *PotionFactory::create(char symbol, shared_ptr<Player> p, Cell *c) {
    Item *potion;
    switch (symbol) {
        case '0':
            break;
        case '1':
            potion = new BoostAtk(p);
            return potion;
        case '2':
            break;

        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
    }
}