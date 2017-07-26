#include <iostream>
#include <sstream>
#include "board/floor.h"
#include "board/textdisplay.h"

using namespace std;

string gameStart();
bool isDirection(string input);
bool stopEnemies;

int main(int argc, char *argv[]) {
    stopEnemies = false;
    srand(time(NULL));

    string race;
    race = gameStart();

    Floor f;

    if (argc == 2) {
        f = Floor{1, argv[1]};
    }
    else {
        f = Floor{1};
    }

    f.init(race);
    cout << f << endl;

    string input;
    while (getline(cin, input)) {
        if (input == "f") {
            stopEnemies = !stopEnemies;
            if (stopEnemies) {
                cout << "Enemies stopped";
            }
            else {
                cout << "Enemies can move again";
            }
            cout << endl;
        }
        else if (input == "r") {
            gameStart();
            cout << "Restarted" << endl;
        }
        else if (input == "q") {
            cout << "You quit." << endl;
            break;
        }
        else {
            istringstream iss(input);
            string word1, word2;
            iss >> word1;
            iss >> word2;

            if (word1 == "a") {
                if (isDirection(word2)) {
                    cout << "Attacking " << word2 << endl;
                    f.attack(word2);
                }
            }
            else if (word1 == "u") {
                if (isDirection(word2)) {
                    cout << "Picking up " << word2 << endl;
                    f.usePotion(word2);
                }
            }
            else {
                if (isDirection(word1)) {
                    cout << "Moving " << word2 << endl;
                    f.movePlayer(word1);
                }
            }
        }
        if (!stopEnemies) {
            f.moveEnemies();
        }
        // f2.moveEnemies();
        if (f.isGameOver()) {
            f.printEndGame();
            break;
        }
        cout << f << endl;
    }
}

// restarts game and returns race chosen in string format
string gameStart() {
    cout << "Choose your class: " << endl;
    cout << "s - Shade: " << endl;
    cout << "d - Drow: " << endl;
    cout << "v - Vampire: " << endl;
    cout << "g - Goblin: " << endl;
    cout << "t - Troll: " << endl;
    string input;
    getline(cin, input);
    string race = input;

    if (input == "s") {
        cout << "Shade chosen";
    }
    else if (input == "d") {
        cout << "Drow chosen";
    }
    else if (input == "v") {
        cout << "Vampire chosen";
    }
    else if (input == "g") {
        cout << "Goblin chosen";
    }
    else if (input == "t") {
        cout << "Troll chosen";
    }
    else {
        cout << "Invalid race, you get to be a Shade";
        race = "s";
    }
    cout << endl;

    return race;
}

bool isDirection(string input) {
    if (input == "nw" || input == "n" || input == "no" || input == "ne" ||
        input == "e" || input == "ea" || input == "se" || input == "s" ||
        input == "so" || input == "sw" || input == "w" || input == "we") {
        return true;
    }
    cout << input << " is not a valid command" << endl;

    return false;
}
