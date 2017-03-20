#include "SampleClass.h"
#include <iostream>
#include "sampleClass2.h"


using namespace std;

SampleClass::SampleClass()
: varSample1(23)
{
    /*cout << "Go go go!" << endl;*/

}

SampleClass::~SampleClass()
{
    /*cout << "Retreat!" << endl;*/
}

/*
void SampleClass::constFunction(int *x) const {
    cout << *x << endl;

    (*x)++;

    cout << *x << endl;
}
*/

void SampleClass::print() {
    cout << varSample1;
}
