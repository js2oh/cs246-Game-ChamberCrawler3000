#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "position.h"

class Cell;

class TextDisplay {
    int width;
    int height;

    std::vector<std::vector<char>> theDisplay;
    void readBoard(std::string file, int level = 0);

    public:
    // TextDisplay();
    TextDisplay(int width, int height, int level, std::string file);
    ~TextDisplay();

    void notify(Cell &c);
    char at(int i, int j);
    char at(Position p);

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif /* TEXTDISPLAY_H */
