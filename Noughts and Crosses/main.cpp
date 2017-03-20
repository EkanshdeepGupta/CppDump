#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void clrscr();
void printGrid();
char write(int x);
void playGame();
int computerMove (bool &gameOver, int *openPositions, int &numberOfOpenPositions);

int gridElements[9];

int main() {
    for (int i=0; i<9; i++) {
        gridElements[i] = 0;
    };

    playGame();
};



void printGrid() {
    cout << "     |     |     " << endl;
    cout << "  " << write(gridElements[0]) << "  |  " << write(gridElements[1]) << "  |  " << write(gridElements[2]) << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << write(gridElements[3]) << "  |  " << write(gridElements[4]) << "  |  " << write(gridElements[5]) << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << write(gridElements[6]) << "  |  " << write(gridElements[7]) << "  |  " << write(gridElements[8]) << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
};

char write(int x) {
    switch(x) {
        case 1:
            return 'X';
            break;
        case -1:
            return 'O';
            break;
        case 0:
            return ' ';
            break;
    };
};

void clrscr() {
    cout << "\033[2J\033[1;1H";
};
