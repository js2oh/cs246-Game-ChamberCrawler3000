#include <iostream>
#include <sstream>
#include "board/floor.h"
#include "board/textdisplay.h"
#include "item/potion/potionfactory.h"

using namespace std;

string gameStart();
bool isDirection(string input);
bool stopEnemies;
Floor f2;
int main() {
	stopEnemies = false;
    PotionFactory potionfactory;
    srand(time(NULL));

    string race;
    race = gameStart();

    Floor f1{1};
    Floor f2{1, "cc3kfloor.txt"}; // Default level 1
    // f1 only shows stairs until Character + Item symbols added

    // debug stuff
    // f2.cellAt(3, 4).setItem(potionfactory.createItem(RH));
    cout << f1 << endl;

    cout << f2 << endl;

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
            return 0;
        }
        else {
			istringstream iss (input);
			string word1, word2;
			iss >> word1;
			iss >> word2;
			
			if (word1 == "a") {
				if (isDirection(word2)) {
					
					cout << "Attacking " << word2 << endl;
				}
			}
			else if (word1 == "u") {
				if (isDirection(word2)) {
					
					cout << "Picking up " << word2 << endl;
				}
			}
			else {
				if (isDirection(word1)) {
					
					cout << "Moving "<< word2 << endl;
					f2.movePlayer(word1);
				}
			}
			
	
            
        }
		if (!stopEnemies) {
			//f2.moveEnemies();
		}
        // f2.moveEnemies();
        if (f2.isGameOver()) {
            break;
        }
        cout << f2 << endl;
    }

    f2.printEndGame();
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
	f2.init(race);
    return race;
}

bool isDirection (string input) {
	if (input == "nw" || input == "n" || input == "no" ||
		input == "ne" || input == "e" || input == "ea" ||
		input == "se" || input == "s" || input == "so" ||
		input == "sw" || input == "w") {
		return true;
	}
	cout << input << " is not a direction";
	return false;
}