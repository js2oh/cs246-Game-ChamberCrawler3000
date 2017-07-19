#include "textdisplay.h"
#include "floor.h"

using namespace std;

int main() {
    srand(time(NULL));

    Floor f1{0};
    Floor f2{0, "../cc3kfloor.txt"};
    cout << f1 << endl;
    cout << f2 << endl;
}
