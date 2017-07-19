#include "cell.h"
#include <iostream>
#include "info.h"

Cell::Cell() {}

Cell::~Cell() {}

Info Cell::getInfo() const {
    Info i{};
    i.pos.row = pos.row;
    i.pos.col = pos.col;
    i.symbol = symbol;
    return i;
}

CellObject Cell::getCellObject() const {
    return co;
}

void Cell::setCellObject(CellObject co) {
    this->co = co;
}

void Cell::setCellSymbol(const char c) {
    this->symbol = c;
}

Chamber *Cell::getChamber() {
    return c;
}
void Cell::setChamber(Chamber *c) {
    this->c = c;
}

void Cell::setTd(TextDisplay *td) {
    this->td = td;
}

Position Cell::getPosition() const {
    return pos;
}

void Cell::setPosition(int row, int col) {
    this->pos.row = row;
    this->pos.col = col;
}

void Cell::setPosition(Position p) {
    setPosition(p.row, p.col);
}

// Notify TextDisplay
void Cell::notify() {
    td->notify(*this);
}
