#ifndef POSITION_H
#define POSITION_H

#include <iostream>

struct Position {
    const static int height = 25;
    const static int width = 79;

    int row;
    int col;

    Position &operator++();
};

std::ostream &operator<<(std::ostream &out, const Position &p);

#endif /* POSITION_H */
