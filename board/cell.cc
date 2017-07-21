#include "cell.h"
#include <iostream>
#include "info.h"

Cell::Cell() : symbol{'.'} {}

Cell::~Cell() {}

Info Cell::getInfo() const {
    Info i{};
    i.pos.row = pos.row;
    i.pos.col = pos.col;
    i.co = co;
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

void Cell::transfer(Cell &cell) {
    setCellObject(CellObject::Empty);
    notify();

    cell.setCellObject(CellObject::Character);
    cell.notify();
}

bool Cell::isEmpty() const {
    return co == CellObject::Empty;
}

Character *Cell::getCharacter() {
    return cp;
}

void Cell::setCharacter(Character *cp) {
    this->cp = cp;
}

Item *Cell::getItem() {
    return ip;
}

void Cell::setItem(Item *ip) {
    this->ip = ip;
}
