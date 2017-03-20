#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std;

/*int fibo(int x);

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
*/

int main () {
    /*int x, y;
    cout << "GRID DIMENSIONS: " << endl;
    cout << "Rows: ";
    cin >> x;
    cout << "Columns: ";
    cin >> y;

    const int arrX = x;
    const int arrY = y;

    int arr[arrX][arrY];

    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            cin >> arr[i][j];
        };
    };

    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            cout << arr[i][j] << "\t";
        };
        cout << endl;
    };*/

   vector <char> asd;
   asd.push_back('k');
   asd.push_back('l');
   asd.push_back('m');
   asd[0] = 'x';
   cout << asd[0];

}
