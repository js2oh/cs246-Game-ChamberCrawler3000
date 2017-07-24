#ifndef POSITION_H
#define POSITION_H
#include <iostream>

struct Position {
    // const static int HEIGHT = 25;
    // const static int WIDTH = 79;

    int row;
    int col;

    bool operator!=(const Position &other) const;
};

std::ostream &operator<<(std::ostream &out, const Position &p);

#endif /* POSITION_H */
