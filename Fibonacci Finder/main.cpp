#include <iostream>

using namespace std;

int fibo(int x);

int main() {
    cout << "Enter Number: ";
    int input;
    cin >> input;

    cout << endl;

    if (input%10==1) {cout << input << "st";}
    if (input%10==2) {cout << input << "nd";}
    if (input%10==3) {cout << input << "rd";}
    else {cout << input << "th";};

    cout << " term of the fibonacci sequence is " << fibo(input);

    cout << endl;
    return 0;
}

int fibo(int x) {
    if ((x==1) || (x==2)) {
        return 1;
    }

    else {
    return (fibo(x-1) + fibo (x-2));
    }

}
