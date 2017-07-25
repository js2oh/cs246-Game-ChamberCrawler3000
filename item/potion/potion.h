#ifndef POTION_H
#define POTION_H

#include <string>
#include "../item.h"

class Potion : public Item {
    const static char SYMBOL;

    public:
    std::string displayName;

    // Potion(Cell *cell, std::string displayName);
};

#endif /* POTION_H */
