#include <iostream>
#include "floor.h"
#include <cstdlib>

using namespace std;

const int Floor::WIDTH = 79;
const int Floor::HEIGHT = 25;
const int Floor::CHAMBER_COUNT = 5;

Floor::Floor() : isHostileMerchants{false}, grid{HEIGHT, vector<Cell>{WIDTH}} {
    init(); // theDisplay(height, vector<char>(width))
}

Floor::~Floor() {
    delete td;
}

void Floor::clearGrid() {
    delete td;

    // Clear each 'row' in grid
    for (int i = 0; i < WIDTH; ++i) {
        grid[i].clear();
    }
}

void Floor::init() {
    td = new TextDisplay{WIDTH, HEIGHT};

    for (int i = 0; i < CHAMBER_COUNT; ++i) {
        chambers.emplace_back(Chamber{i});
    }
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j].setCoords(i, j);
            grid[i][j].setTd(td);

            char symbol = td->at(i, j);
            if (symbol == '+' || symbol == '#' || symbol == '.') {
                grid[i][j].setCellObject(CellObject::Empty);
            }
            else {
                grid[i][j].setCellObject(CellObject::Wall);
            }
        }
    }
}

ostream &operator<<(ostream &out, const Floor &g) {
    out << *(g.td);
    return out;
}

// TODO Spawn multiple objects
void Floor::spawnPlayer() {
    const int i = rand() % CHAMBER_COUNT;
    Position p = chambers.at(i).spawnPlayer();
    Cell &c = grid.at(p.row).at(p.col);

    c.setCellObject(CellObject::Player);
    c.setCellSymbol('@');
    c.notify();
}

void Floor::spawnEnemies() {
    const int i = rand() % CHAMBER_COUNT;
    Position p = chambers.at(i).spawnEnemy();
    cout << p.row << ", " << p.col << endl;

    Cell &c = grid.at(p.row).at(p.col);

    c.setCellObject(CellObject::Enemy);
    c.setCellSymbol('E');
    c.notify();
}

void Floor::spawnPotions() {
    const int i = rand() % CHAMBER_COUNT;
    Position p = chambers.at(i).spawnPlayer();
    Cell &c = grid.at(p.row).at(p.col);

    c.setCellObject(CellObject::Item);
    c.setCellSymbol('P');
    c.notify();
}

void Floor::spawnGoldPiles() {
    const int i = rand() % CHAMBER_COUNT;
    Position p = chambers.at(i).spawnPlayer();
    Cell &c = grid.at(p.row).at(p.col);

    c.setCellObject(CellObject::Item);
    c.setCellSymbol('G');
    c.notify();
}

void Floor::spawnStairs() {
    const int i = rand() % CHAMBER_COUNT;
    Position p = chambers.at(i).spawnPlayer();
    Cell &c = grid.at(p.row).at(p.col);

    c.setCellObject(CellObject::Stairs);
    c.setCellSymbol('/');
    c.notify();
}
