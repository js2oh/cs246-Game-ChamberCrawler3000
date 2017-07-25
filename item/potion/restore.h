#ifndef RESTORE_H
#define RESTORE_H
#include <memory>
#include "../item.h"
#include "potion.h"

using namespace std;

class Player;

class Restore: public potion{
    public:
        Restore();
        void applyEffect(shared_ptr<Player> p);
};

#endif
