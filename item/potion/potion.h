#ifndef GOBLIN_H
#define GOBLIN_H
#include "../item.h"

class Potion: public Item {
    int permAmt;
    int tempAmt;
    public:
    void setPermAmt(int value);
    void setTempAmt(int value);
    int getPermAmt();
    int getTempAmt();
};

#endif
