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

void TextDisplay::readBoard(string file, int level) {
    fstream fin{file};
    string line;

    // Skip to desired floor level
    for (int i = 1; i <= level; ++i) {
        for (int j = 0; j < height; ++j) {
            getline(fin, line);
        }
    }

    for (int i = 0; i < height; ++i) {
        getline(fin, line);
        for (int j = 0; j < width; ++j) {
            theDisplay.at(i).at(j) = line[j];
        }
    }
}

char TextDisplay::at(int i, int j) {
    return theDisplay.at(i).at(j);
}

char TextDisplay::at(Position p) {
    return theDisplay.at(p.row).at(p.col);
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
