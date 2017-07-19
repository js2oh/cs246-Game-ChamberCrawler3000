#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>

class Cell;

class TextDisplay {
    int width;
    int height;

    std::vector<std::vector<char>> theDisplay;
    void readBoard(std::string file);

    public:
    // TextDisplay();
    TextDisplay(int width = 79, int height = 25);
    ~TextDisplay();

    void notify(Cell &c);
    char at(int i, int j);

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif /* TEXTDISPLAY_H */
