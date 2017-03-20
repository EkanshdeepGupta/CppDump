#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long int input, temp;
    vector <int> factorList;
    cout << "Enter Number: ";
    cin >> input;
    int factor = 2;

    temp = input;

    while (temp>1) {
        if (temp%factor==0) {
            factorList.push_back(factor);
            temp /= factor;
        }
        else {
            if (factor==2) {
                factor += 1;
            }
            else {
                factor +=2;
            };
        };
    }

    cout << input << "=1";

    for (int i=0; i<factorList.size(); i++) {
        cout << "*" << factorList[i];
    }

    cout << endl;

    return 0;
}
