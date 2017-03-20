#include <iostream>
#include "SampleClass.h"
#include "sampleClass2.h"


using namespace std;

int main()
{
    const SampleClass sampleObject;

    int abra = 4;

    int *ptr = &abra;

    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;


    cout << "FUNCTION IN PROGRESS" << endl;

    /*sampleObject.constFunction(ptr);

    cout << "FUNCTION FINISHED" << endl;

    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    return 0; */

    SampleClass samObj1;

    sampleClass2 samObj2(samObj1);

    samObj2.print2();
    samObj2.sm.print();
}
