#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <utility>
#include <vector>
#include "cellobject.h"
#include "chamber.h"
#include "position.h"
#include "textdisplay.h"

struct Info;
class Chamber;

class Cell {
    char symbol;
    CellObject co;
    Position pos;

    Chamber *c;
    TextDisplay *td;

    public:
    Cell();
    ~Cell();

    Info getInfo() const;
    CellObject getCellObject() const;
    void setCellObject(CellObject co);
    void setCellSymbol(char c);
    Chamber *getChamber();
    void setChamber(Chamber *c);
    void setTd(TextDisplay *td);
    Position getPosition() const;
    void setPosition(int row, int col);
    void setPosition(Position p);
    void notify();
};

#endif /* CELL_H */
