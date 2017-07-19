#include <iostream>
#include <utility>
#include "cell.h"
#include "info.h"

// Default constructor and destructor
Cell::Cell() : pos{0, 0} {}
Cell::~Cell() {}

Info Cell::getInfo() const {
    Info i{};
    i.pos.row = pos.row;
    i.pos.col = pos.col;
    i.symbol = symbol;
    return i;
}

void Cell::setCellObject(CellObject co) {
    this->co = co;
}

void Cell::setTd(TextDisplay *td) {
    this->td = td;
}

void Cell::setCoords(int r, int c) {
    this->pos.row = r;
    this->pos.col = c;
}

void Cell::notify() {
    td->notify(*this);
}

Position Cell::getPosition() const {
    return pos;
}

CellObject Cell::getOccupied() const {
    return co;
}

void Cell::setCellSymbol(const char c) {
    this->symbol = c;
}
