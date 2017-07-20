#include "textdisplay.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include "cell.h"
#include "info.h"

using namespace std;

TextDisplay::TextDisplay(int width, int height, int level, string file)
    : width{width}, height{height}, theDisplay(height, vector<char>(width)) {
    readBoard(file, level);
}

TextDisplay::~TextDisplay() {}

// Read in floor layout from given file
void TextDisplay::readBoard(string file, int level) {
    fstream fin{file};
    string line;

    // Skip to desired floor level, since each file has layouts for 5 levels
    for (int i = 1; i <= level; ++i) {
        for (int j = 0; j < height; ++j) {
            getline(fin, line);
        }
    }

    // Begin file read into grid
    for (int i = 0; i < height; ++i) {
        getline(fin, line);
        for (int j = 0; j < width; ++j) {
            theDisplay.at(i).at(j) = line[j];
        }
    }
}

// at gets the symbol located at the position in the grid.
char TextDisplay::at(int row, int col) {
    return theDisplay.at(row).at(col);
}

char TextDisplay::at(Position p) {
    return theDisplay.at(p.row).at(p.col);
}

// Update grid due to change in Cell
void TextDisplay::notify(Cell &c) {
    // Get row, column, on/off state of subject
    Info i = c.getInfo();
    const Position pos = i.pos;
    const CellObject co = i.co;

    // Update display grid
    switch (co) {
        case CellObject::Empty:
            theDisplay[pos.row][pos.col] = '.';
            break;
        case CellObject::Player:
            theDisplay[pos.row][pos.col] = '@';
            break;
    }
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
