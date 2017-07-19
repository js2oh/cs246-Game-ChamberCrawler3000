#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <utility>
#include <vector>
#include "cellobject.h"
#include "textdisplay.h"
#include "position.h"

struct Info;

class Cell {
    TextDisplay *td;
    CellObject co;
    Position pos;
    char symbol;

    // Add other private members if necessary
    // std::vector<Observer *> observers;

    public:
    Cell(); // Default constructor
    ~Cell();

    void setCoords(int r, int c); // Tells me my row and column number.
    void setCellObject(CellObject co);
    void setCellSymbol(char c);
    void setTd(TextDisplay *td);
    void notify();

    Info getInfo() const;
    CellObject getOccupied() const;
    Position getPosition() const;
};

#endif /* CELL_H */
