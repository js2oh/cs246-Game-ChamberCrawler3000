#include "position.h"

using namespace std;

ostream &operator<<(ostream &out, const Position &p) {
    out << "(" << p.row << ", " << p.col << ")";
    return out;
}
