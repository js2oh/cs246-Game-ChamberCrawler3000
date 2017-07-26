#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
//#include "../character/character.h"
//#include "../item/item.h"
#include "cellobject.h"
#include "chamber.h"
#include "chamberloc.h"
#include "position.h"
#include "textdisplay.h"

class Character;
struct Info;
class Chamber;
class Item;
class Potion;

class Cell {
    char symbol;
    CellObject co;
    Position pos;

    std::shared_ptr<Character> cp;
    std::shared_ptr<Potion> pp;
    std::shared_ptr<Item> ip;
    std::shared_ptr<Enemy> ep;

    Chamber *c;
    TextDisplay *td;

    public:
    Cell();
    Cell(Position pos, char symbol = '.');
    ~Cell();

    bool isTile() const;
    bool isEmpty() const;
    void notify();
    void transferCharacter(Cell &cell);
    void deleteCell();
    Info getInfo() const;

    CellObject getCellObject() const;
    void setCellObject(CellObject co);
    void setCellSymbol(char c);
    Chamber *getChamber();
    ChamberLoc getChamberLoc();
    void setChamber(Chamber *c);
    std::shared_ptr<Character> getCharacter();
    void setCharacter(std::shared_ptr<Character> cp);
    std::shared_ptr<Enemy> getEnemy();
    void setEnemy(std::shared_ptr<Enemy> ep);

    std::shared_ptr<Potion> getPotion();
    void setPotion(std::shared_ptr<Potion> pp);

    std::shared_ptr<Item> getItem();
    void setItem(std::shared_ptr<Item> ip);
    void setTd(TextDisplay *td);
    Position getPosition() const;
    void setPosition(int row, int col);
    void setPosition(Position p);
    void useItem();
};

#endif /* CELL_H */
