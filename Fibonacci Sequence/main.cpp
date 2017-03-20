#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;

    b = 1;
    c = 1;

    cout << "Fibonacci Sequence: " << endl << endl;

    cout << 1 << endl;
    cout << 1 << endl;

    for (a=0; a<=100; a++) {
        d = b;
        b = b + c;
        c = d;
        cout << b << endl;
    }

    return 0;
}
