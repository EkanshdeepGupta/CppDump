#include "sampleClass2.h"
#include <iostream>
#include "SampleClass.h"


using namespace std;

sampleClass2::sampleClass2(SampleClass st)
: sm(st)
{
    //ctor
}

sampleClass2::~sampleClass2()
{
    //dtor
}

void sampleClass2::print2() {
    cout << "Gryffindor is for the brave.";
}
