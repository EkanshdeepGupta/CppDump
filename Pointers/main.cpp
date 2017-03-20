#include <iostream>

using namespace std;

int main()
{
    int b = 17;
    int a = 5;

    int *ptr3 = &b;
    int *ptr2 = &a;

    *(ptr2++);
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "ptr2 = " << ptr2 << endl;

    *(ptr3++);
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "ptr2 = " << ptr2 << endl;

    (ptr3++);
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "ptr2 = " << ptr2 << endl;

    *(ptr3++);
    cout << "*ptr2 = " << *ptr2 << endl;
    (ptr3++);
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "ptr2 = " << ptr2 << endl;


}
