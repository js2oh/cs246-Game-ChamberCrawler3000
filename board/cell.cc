#include "cell.h"
#include <iostream>
#include "info.h"

using namespace std;

Cell::Cell() : symbol{'.'} {}

Cell::Cell(Position pos, char symbol) : pos{pos}, symbol{symbol} {}

Cell::~Cell() {}

bool Cell::isTile() const {
    return symbol == '.';
}

bool Cell::isEmpty() const {
    return co == CellObject::Empty;
}

void Cell::notify() {
    td->notify(*this);
}

// Set current Cell's object to Empty and target Cell's object to Character
void Cell::transferCharacter(Cell &cell) {
    setCellObject(CellObject::Empty);
    notify();

    // 'Move' character to next Cell
    cell.setCellObject(CellObject::Character);
    cell.setCharacter(getCharacter());
    cell.setEnemy(getEnemy());

    if (getCharacter()) {
        getCharacter()->setCell(&cell);
    }
    else if (getEnemy()) {
        getEnemy()->setCell(&cell);
    }

    setCharacter(nullptr);
    setEnemy(nullptr);
    cell.notify();
}

void Cell::deleteCell() {
    co = CellObject::Empty;
    // setCharacter(nullptr);
    setEnemy(nullptr);
    setItem(nullptr);
    setPotion(nullptr);
    notify();
}

Info Cell::getInfo() const {
    Info i{};
    i.pos.row = pos.row;
    i.pos.col = pos.col;
    i.cellObject = co;
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

ChamberLoc Cell::getChamberLoc() {
    Chamber *c = getChamber();
    if (c) {
        return c->getLoc();
    }
    return ChamberLoc::Other;
}

shared_ptr<Character> Cell::getCharacter() {
    return cp;
}

void Cell::setCharacter(shared_ptr<Character> cp) {
    this->cp = cp;
}

shared_ptr<Enemy> Cell::getEnemy() {
    return ep;
}

void Cell::setEnemy(shared_ptr<Enemy> ep) {
    this->ep = ep;
}

shared_ptr<Potion> Cell::getPotion() {
    return pp;
}

void Cell::setPotion(shared_ptr<Potion> pp) {
    this->pp = pp;
}

shared_ptr<Gold> Cell::getGold() {
    return gp;
}

void Cell::setGold(shared_ptr<Gold> gp) {
    this->gp = gp;
}


shared_ptr<Item> Cell::getItem() {
    return ip;
}

void Cell::setItem(shared_ptr<Item> ip) {
    this->ip = ip;
}

void Cell::useItem() {
    // ip->use();
    // delete ip;
    ip = nullptr;

    co = CellObject::Empty;
    notify();
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
