#ifndef POTION_H
#define POTION_H

#include <memory>
#include <string>
#include "../item.h"

class Player;

class Potion : public Item {
    const static char SYMBOL;

    protected:
    int amt;

    public:
    std::string displayName;

    virtual void applyEffects(std::shared_ptr<Player> p);

    Potion(int amt);
};

#endif /* POTION_H */
