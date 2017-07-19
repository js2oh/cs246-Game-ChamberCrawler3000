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

    Chamber *getChamber();

    void setChamber(Chamber *c);
    void setCellObject(CellObject co);
    void setCellSymbol(char c);
    void setCoords(int r, int c);
    void setTd(TextDisplay *td);
    void notify();

    Info getInfo() const;
    CellObject getOccupied() const;
    Position getPosition() const;
};

#endif /* CELL_H */
