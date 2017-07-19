#include "position.h"

using namespace std;

Position &Position::operator++() {
    if (col + 1 >= width) {
        col = 0;
        ++row;
    }
    else {
        ++col;
    }

    return *this;
}

ostream &operator<<(ostream &out, const Position &p) {
    out << "(" << p.row << ", " << p.col << ")";
    return out;
}
