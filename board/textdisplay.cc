#include <iostream>
#include <utility>
#include "cell.h"
#include "info.h"
#include "textdisplay.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

TextDisplay::TextDisplay(int width, int height)
    : width{width}, height{height}, theDisplay(height, vector<char>(width)) {
    readBoard("empty.txt");
}

TextDisplay::~TextDisplay() {}

void TextDisplay::readBoard(string file) {
    fstream fin{file};
    char ch;
    int i = 0, j = 0;

    while (fin >> noskipws >> ch) {
        if (ch == '\n')
            continue;

        theDisplay.at(i).at(j) = ch;

        if (j + 1 == width) {
            j = 0;
            ++i;
        }
        else {
            ++j;
        }
    }
}

char TextDisplay::at(int i, int j) {
    return theDisplay.at(i).at(j);
}

void TextDisplay::notify(Cell &c) {
    // Get row, column, on/off state of subject
    Info i = c.getInfo();
    const Position pos = i.pos;
    const char symbol = i.symbol;

    // Update display grid
    theDisplay[pos.row][pos.col] = symbol;
}

/*
void TextDisplay::notify(Item *i) {
    // Get row, column, on/off state of subject
    Info i = i.getInfo();
    const Position pos = i.pos;
    const char symbol = i.symbol;

    // Update display grid
    theDisplay[pos.row][pos.col] = symbol;
}

void TextDisplay::notify(Character *c) {
    // Get row, column, on/off state of subject
    Info i = c.getInfo();
    const Position pos = i.pos;
    const char symbol = i.symbol;

    // Update display grid
    theDisplay[pos.row][pos.col] = symbol;
}
*/

ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int i = 0; i < td.height; ++i) {
        for (int j = 0; j < td.width; ++j) {
            out << td.theDisplay[i][j];
        }
        out << endl;
    }

    return out;
}
