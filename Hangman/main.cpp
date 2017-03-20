#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void clrscr();
void hangmanPrinter(int x);
void wordPrinter(string x, bool *victory);
void startGame(string target, int *hangmanFault);
string targetSelect();

vector <char> guessedArr;
vector <char> wrongLetters;

int main() {
    string target;
    clrscr();
    wrongLetters.clear();
    guessedArr.clear();

    int hangmanFault = 0;
    guessedArr.push_back(' ');
    guessedArr.push_back('-');

    target = targetSelect();
    startGame(target, &hangmanFault);
}

string targetSelect() {
    cout << "Select Category (1 to 3): " << endl;
    cout << "1. Hollywood Movies" << endl;
    cout << "2. Bollywood Movies" << endl;
    cout << "3. Car Companies" << endl;
    cout << "Selection: ";
    char selection;
    string targetList;
    int numberOfEntries;
    bool pass;

    do {
        pass = true;

        cin >> selection;

        if (isdigit(selection)){

            switch (selection) {
            case '1':
                targetList = "hollywood.txt";
                numberOfEntries = 10;
                break;
            case '2':
                targetList = "bollywood.txt";
                numberOfEntries = 10;
                break;
            case '3':
                targetList = "car.txt";
                numberOfEntries = 10;
                break;
            default:
                cout << "Try again.\nSelection: ";
                pass = false;
            };
        }

        else {
            cout << "Try again.\nSelection: ";
            pass = false;
        }

    } while (pass == false);


    string targetPath = "./list/" + targetList;
    const char *targetPathChar = targetPath.c_str();

    ifstream targetFile(targetPathChar);

    srand(time(0));

    int entryIndex = (rand() % numberOfEntries);

    string temp;

    for (int i=0; i<entryIndex; i++) {
        getline(targetFile, temp);
    }
    string selectedTarget;

    getline(targetFile, selectedTarget);

    targetFile.close();

    selectedTarget = selectedTarget.substr(0, selectedTarget.length()-1);

    return selectedTarget;

}

void startGame(string target, int *hangmanFault) {
    char tempGuessed;
    clrscr();
    bool victory = true;

    hangmanPrinter(*hangmanFault);
    bool atFault = true;

    cout << endl;
    wordPrinter(target, &victory);
    cout << endl << endl;

    if (*hangmanFault != 6 && victory == false) {
        cout << "Enter letter: ";
        cin >> tempGuessed;

        if (isalpha(tempGuessed)) {
            tempGuessed = (char)(toupper(tempGuessed));
        }

        bool typedBefore = false;

        for (unsigned int j=0; j<guessedArr.size(); j++) {
            if (guessedArr[j] == tempGuessed) {
                typedBefore = true;
            };
        };

        if (typedBefore == false) {
            guessedArr.push_back(tempGuessed);

            for (unsigned int i=0; i<target.length(); i++) {
                if (tempGuessed == target[i]) {
                    atFault = false;
                    break;
                };
            };

            if (atFault == true) {
                (*hangmanFault)++;
                wrongLetters.push_back(tempGuessed);
            };
        };

        startGame(target, hangmanFault);
    }

    else {
        if (*hangmanFault == 6) {
            cout << "YOU'VE LOST. BETTER LUCK NEXT TIME! (Answer: " << target << ")" << endl;
        }

        else if (victory == true) {
            cout << "CONGRATULATIONS! YOU'VE WON!" << endl;
        };

        cout << "DO YOU WANT TO PLAY AGAIN (y/n)? ";
        char playAgain;
        cin >> playAgain;

        if (tolower(playAgain) == 'y') {
            main();
        };
    };
};

void clrscr() {
cout << "\033[2J\033[1;1H";
}

void hangmanPrinter(int x) {
    if (x==0) {
        for (int i=0; i<17; i++) {
            cout << endl;
        };
    }

    else if (x==1) {
        cout << "          __________________" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "------------------" << endl;
    }

    else if (x==2) {
        cout << "          __________________" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "------------------" << endl;
    }

    else if (x==3) {
        cout << "          __________________" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  **" << endl;
        cout << "         |                *    *" << endl;
        cout << "         |                *    *" << endl;
        cout << "         |                  **" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "------------------" << endl;
    }

    else if (x==4) {
        cout << "          __________________" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  **" << endl;
        cout << "         |                *    *" << endl;
        cout << "         |                *    *" << endl;
        cout << "         |                  **" << endl;
        cout << "         |                   |" << endl;
        cout << "         |                   |" << endl;
        cout << "         |                   |" << endl;
        cout << "         |                   |" << endl;
        cout << "         |                   |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "------------------" << endl;
    }

    else if (x==5) {
        cout << "          __________________" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  **" << endl;
        cout << "         |                *    *" << endl;
        cout << "         |                *    *" << endl;
        cout << "         |                  **" << endl;
        cout << "         |                   |" << endl;
        cout << "         |                  /|\\" << endl;
        cout << "         |                 / | \\" << endl;
        cout << "         |                   | " << endl;
        cout << "         |                   | " << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "         |" << endl;
        cout << "------------------" << endl;

    }

    else if (x==6) {
        cout << "          __________________" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  |" << endl;
        cout << "         |                  **" << endl;
        cout << "         |                *    *" << endl;
        cout << "         |                *    *" << endl;
        cout << "         |                  **" << endl;
        cout << "         |                   |" << endl;
        cout << "         |                  /|\\" << endl;
        cout << "         |                 / | \\" << endl;
        cout << "         |                   | " << endl;
        cout << "         |                   | " << endl;
        cout << "         |                  / \\" << endl;
        cout << "         |                 /   \\" << endl;
        cout << "         |" << endl;
        cout << "------------------" << endl;

    }
}

void wordPrinter(string word, bool *victory) {
    bool isCharGuessed = false;

    for (unsigned int i=0; i<word.length(); i++) {
        for (unsigned int j=0; j<guessedArr.size(); j++) {
            if (word[i] == guessedArr[j]) {
                isCharGuessed = true;
                break;
            };
        };

        if (word[i] == ' ') {
                cout << " \t";
        }

        else {
            if (isCharGuessed == true) {
                    cout << word[i];
            }

            else {
                cout << "_";
                *victory = false;
            };

            if (word[i+1] != ' ' && (word.length() - i) > 1) {
                cout << " ";
            };
        };

        isCharGuessed = false;
    };


    cout << "\t Wrong: ";

    for (unsigned int k=0; k<wrongLetters.size(); k++) {
        cout << wrongLetters[k];

        if ((wrongLetters.size() - k) > 1) {
            cout << ", ";
        };
    };
}
