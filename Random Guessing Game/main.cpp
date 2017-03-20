#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void clrscr() {
cout << "\033[2J\033[1;1H";
}

int main() {
    int input;
    vector<int> randomNumbers;
    int numberOfEntries = 24;

    srand(time(0));

    for (int a=0; a<=numberOfEntries; a++) {
        randomNumbers.push_back((rand()%100)+1);
    }

    int chosenNumber = randomNumbers[(rand()%(numberOfEntries+1))];

    cout << "Welcome to the guessing game. Here are the numbers... Choose wisely." << endl << endl;

    for (int a=0; a<=numberOfEntries; a++) {
        cout << randomNumbers[a] << "\t";
        if (a%5==4) {cout << endl;};
    }

    bool isInputMember = false, finish = false;

    do {
        isInputMember = false;

        do {
            cout << endl << endl;
            cout << "Enter number: ";
            cin >> input;
            cout << endl;

            for(int a=0; a<=numberOfEntries; a++) {
                if (randomNumbers[a]==input) {isInputMember = true; break;};
            }

            if (isInputMember==false) {
                cout << "Incorrect selection. Please try again.";
            }
        } while (isInputMember==false);

        if (input==chosenNumber) {
            cout << "Congratulations! You've won! The lucky number is: " << chosenNumber << endl << endl;
            finish = true;
            break;
        }



        else if (input>chosenNumber) {
            if (input-chosenNumber<=5) {
                cout << "Mmmm... You're getting close. Try a little lower.";
            }

            else {
                cout << "You chose too high. Try again.";
                finish = false;
            };
        }

        else if (input<chosenNumber) {
            if (chosenNumber-input<=5) {
                cout << "Mmmm... You're getting close. Try a little higher.";
            }

            else {
                cout << "Go a little higher. Try again";
                finish = false;
            };
        };

    } while (finish==false);

    cout << "Do you wanna play again (y/n)?\t";
    char x;
    cin >> x;

    if (x=='y') {
    clrscr();
    main();
    }

    else {
    cout << endl << "Have a good day, then!" << endl;
    };

    return 0;
}
