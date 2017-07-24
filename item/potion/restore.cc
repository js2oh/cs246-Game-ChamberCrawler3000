#include "restore.h"
#include <iostream>
#include "../../board/cell.h"
using namespace std;

Restore::Restore() {
    cout << "RH spawned"; //<< parentCell->getInfo().pos.row << "," <<
                          // parentCell->getInfo().pos.col << endl
}
void Restore::applyEffects() {
    cout << "RH used" << endl;
}