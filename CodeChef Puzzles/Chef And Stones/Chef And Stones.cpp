#include <iostream>

using namespace std;

int main() {
    long long int numberOfCases;
    cin >> numberOfCases;

    long long int arr[numberOfCases];

    for (int aa=0; aa<numberOfCases; aa++) {
        long long int n1, n2, m;

        cin >> n1 >> n2 >> m;

        long long int x = (m*(m+1))/2;
        long long int y = (n1 < n2)? n1:n2;

        if (x > y) {
            arr[aa] = (n1 + n2 - y - y);
        }

        else {
            arr[aa] = (n1 + n2 - x - x);
        };
    };

    cout << endl << endl;

    for (int i=0; i<numberOfCases; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
