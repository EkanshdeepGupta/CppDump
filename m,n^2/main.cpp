#include <iostream>
#include <math.h>

using namespace std;

bool isDivisible(int m, int n) {
    if ((m/n)*n == m) {
        return true;
    }

    else {
        return false;
    };
};

bool perfectSquare(int m) {
    if (sqrt(m)*sqrt(m) == m ) {return true;}
    else {return false;};
};

int main() {
    for (int x=0; x<10000000; x++) {
    int y = (5*x*x) + 4;
        if (perfectSquare(y)) {
            cout << x << "\t";
        };
    };
};
