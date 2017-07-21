#include <iostream>
#include <sstream>
#include "board/floor.h"
#include "board/textdisplay.h"

using namespace std;

int main() {
    srand(time(NULL));

    Floor f1{1};
    Floor f2{1, "cc3kfloor.txt"}; // Default level 1
    // f1 only shows stairs until Character + Item symbols added
    cout << f1 << endl;
    cout << f2 << endl;

    string input;
    while (getline(cin, input)) {
        f2.movePlayer(input);
        cout << f2 << endl;
    }
}