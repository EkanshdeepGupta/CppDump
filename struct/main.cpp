#include <iostream>

using namespace std;

struct struct1 {
    int int1;
    int * intptr;
};

int main()
{
    struct1 abc;
    struct1 * temp = &abc;

    abc.int1 = 30;
    abc.intptr = new int(45);

//    cout << "1. " << abc << endl;
//    cout << "1.5" << *abc << endl;
    cout << "2. " << abc.intptr << endl;
    cout << "3. " << *(abc.intptr) << endl;
//    cout << "4. " << (*abc).int1 << endl;
    cout << "5. " << (*temp).int1 << endl;
    (*temp).int1 = 35;
    cout << "6. " << abc.int1 << endl;
}
