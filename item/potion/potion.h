#ifndef POTION_H
#define POTION_H
#include "../item.h"

class Potion : public Item {
    int amt;

    public:
    Potion(int amt);
    void setAmt(int value);
    int getAmt();
    virtual void applyEffects(std::shared_ptr<Player> p);
};

#endif
