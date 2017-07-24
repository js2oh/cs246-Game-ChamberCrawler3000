#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <utility>
#include <vector>
//#include "../character/character.h"
//#include "../item/item.h"
#include "cellobject.h"
#include "chamber.h"
#include "position.h"
#include "textdisplay.h"
class Character;
struct Info;
class Chamber;
class Item;

class Cell {
    char symbol;
    CellObject co;
    Position pos;

    Character *cp;
    Item *ip;

    Chamber *c;
    TextDisplay *td;

    public:
    Cell();
    Cell(Position pos, char symbol = '.');
    ~Cell();

    bool isEmpty() const;
    void notify();
    void transferCharacter(Cell &cell);
    Info getInfo() const;

    CellObject getCellObject() const;
    void setCellObject(CellObject co);
    void setCellSymbol(char c);
    Chamber *getChamber();
    void setChamber(Chamber *c);
    Character *getCharacter();
    void setCharacter(Character *cp);
    Item *getItem();
    void setItem(Item *ip);
    void setTd(TextDisplay *td);
    Position getPosition() const;
    void setPosition(int row, int col);
    void setPosition(Position p);
    void useItem();
};

#endif /* CELL_H */
