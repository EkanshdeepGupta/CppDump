#ifndef SAMPLECLASS2_H
#define SAMPLECLASS2_H

#include "sampleClass2.h"
#include <iostream>
#include "SampleClass.h"


class sampleClass2
{
    public:
        sampleClass2(SampleClass st);
        ~sampleClass2();
        SampleClass sm;
        void print2();
    protected:
    private:
};

#endif // SAMPLECLASS2_H
