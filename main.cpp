// This file implements the game using the custom BST in card_list.h/cpp.
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "card.h"
#include "card_list.h"

using namespace std;

int main(int argv, char** argc) {
    if (argv < 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    ifstream cardFile1(argc[1]);
    ifstream cardFile2(argc[2]);
    string line;

    if (cardFile1.fail() || cardFile2.fail()) {
        cout << "Could not open file " << argc[2] << endl;
        return 1;
    }

    CardBST alice;
    CardBST bob;

    while (getline(cardFile1, line) && !line.empty()) {
        istringstream iss(line);
        string suitToken;
        string valueToken;
        if (iss >> suitToken >> valueToken) {
            alice.insert(Card::fromInput(suitToken, valueToken));
        }
    }
    cardFile1.close();

    while (getline(cardFile2, line) && !line.empty()) {
        istringstream iss(line);
        string suitToken;
        string valueToken;
        if (iss >> suitToken >> valueToken) {
            bob.insert(Card::fromInput(suitToken, valueToken));
        }
    }
    cardFile2.close();

    playGame(alice, bob);
    return 0;
}
