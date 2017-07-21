#ifndef INFO_H
#define INFO_H
#include "cellobject.h"
#include "position.h"

struct Info {
    Position pos;
    CellObject cellObject;
    char symbol;
};

#endif
