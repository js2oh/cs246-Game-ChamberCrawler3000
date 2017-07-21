#include <iostream>
#include <sstream>
#include "board/floor.h"
#include "board/textdisplay.h"

using namespace std;

int main() {
    srand(time(NULL));

    Floor f1{0};
    Floor f2{0, "cc3kfloor.txt"};
    // cout << f1 << endl;
    cout << f2 << endl;

    string input;
    while (getline(cin, input)) {
        f2.movePlayer(input);
        cout << f2 << endl;
    }
}