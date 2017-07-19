#include "textdisplay.h"
#include "floor.h"

using namespace std;

int main() {
    srand(time(NULL));
    Floor fl{};
    fl.spawnEnemies();

    cout << fl << endl;
}
