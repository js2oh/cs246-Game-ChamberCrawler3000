#include "position.h"

using namespace std;

bool Position::operator!=(const Position &other) const {
    return row != other.row || col != other.col;
}

ostream &operator<<(ostream &out, const Position &p) {
    out << "(" << p.row << ", " << p.col << ")";
    return out;
}
