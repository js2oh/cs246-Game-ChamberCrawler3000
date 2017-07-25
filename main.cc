#include <iostream>
#include <sstream>
#include "board/floor.h"
#include "board/textdisplay.h"
#include "item/potion/potionfactory.h"

using namespace std;

int main() {
    PotionFactory potionfactory;
    srand(time(NULL));

    Floor f1{1};
    Floor f2{1, "cc3kfloor.txt"}; // Default level 1
    // f1 only shows stairs until Character + Item symbols added
    f2.cellAt(3, 4).setItem(potionfactory.createItem(RH, &f2.cellAt(3, 4)));
    cout << f1 << endl;
    cout << f2 << endl;

    string input;
    while (getline(cin, input)) {
        f2.movePlayer(input);
        // f2.moveEnemies();
        cout << f2 << endl;
    }
}
