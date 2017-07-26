#include "position.h"

using namespace std;

bool Position::adjacent(const Position &other) const {
    return (row - 1 == other.row && col == other.col) ||
           (row - 1 == other.row && col + 1 == other.col) ||
           (row == other.row && col + 1 == other.col) ||
           (row + 1 == other.row && col + 1 == other.col) ||
           (row + 1 == other.row && col == other.col) ||
           (row + 1 == other.row && col - 1 == other.col) ||
           (row == other.row && col - 1 == other.col) ||
           (row - 1 == other.row && col - 1 == other.col);
}

bool Position::operator==(const Position &other) const {
    return row == other.row && col == other.col;
}

bool Position::operator!=(const Position &other) const {
    return row != other.row || col != other.col;
}

ostream &operator<<(ostream &out, const Position &p) {
    out << "(" << p.row << ", " << p.col << ")";
    return out;
}
