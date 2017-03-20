#include <iostream>

using namespace std;

void sortAscending(int *arr, int length);

/* Strength of a sequence is defined as the sum of the difference between each pair of consecutive terms in a sequence (+ve difference only).
Eg - 5, 1, 8 has as strength of (5-1)+(8-1) = 11

This is a program to arrange a series of numbers into a sequence with maximum possible strength.
*/

/* It takes a sequence, arranges it in ascending order, and places the first term of input array as the centermost term of the output array.
Then, it compares the 4 differences between the two terminal terms of each, output and the input array. Then according to whichever
difference is the highest, it places the corresponding term to the suitable end of the output array.
*/

int main()
{
    cout << "Enter a sequence of numbers (-1 when you're done): " << endl;

    int inputArr[50];
    int i = 0;

    do {
        cin >> inputArr[i];
        i++;
    } while(inputArr[i-1]!=(-1)); //Recieves the input

    const int arrLen = i-1;

    sortAscending(inputArr, arrLen-1);

    int tempOutArr[2*arrLen];

    int inputArrMarkerFront = 0; //Markers used to keep track of terms used.
    int inputArrMarkerBack = 0;
    int outputArrMarkerFront = 0;
    int outputArrMarkerBack = 0;

    int strength = 0;

    tempOutArr[arrLen] = inputArr[0];

    for (i=0; i<arrLen; i++) {
        int firstMinusFirst = (inputArr[inputArrMarkerBack+1]-tempOutArr[arrLen-outputArrMarkerBack]);
        if (firstMinusFirst < 0) {firstMinusFirst*=(-1);};

        int firstMinusLast = (inputArr[inputArrMarkerBack+1]-tempOutArr[arrLen+outputArrMarkerFront]);
        if (firstMinusLast < 0) {firstMinusLast *= (-1);};

        int lastMinusFirst = (inputArr[arrLen-1-inputArrMarkerFront]-tempOutArr[arrLen-outputArrMarkerBack]);
        if (lastMinusFirst < 0) {lastMinusFirst *= (-1);};

        int lastMinusLast = (inputArr[arrLen-1-inputArrMarkerFront]-tempOutArr[arrLen+outputArrMarkerFront]);
        if (lastMinusLast < 0) {lastMinusLast *= (-1);};

        if ((firstMinusFirst>=firstMinusLast) && (firstMinusFirst>=lastMinusFirst) && (firstMinusFirst>=lastMinusLast)) {
            tempOutArr[arrLen-outputArrMarkerBack-1] = inputArr[inputArrMarkerBack+1];

            outputArrMarkerBack++;
            inputArrMarkerBack++;
            strength+= firstMinusFirst;
        }

        else if ((firstMinusLast>=firstMinusFirst) && (firstMinusLast>=lastMinusFirst) && (firstMinusLast>=lastMinusLast)) {
            tempOutArr[arrLen+outputArrMarkerFront+1] = inputArr[inputArrMarkerBack+1];

            outputArrMarkerFront++;
            inputArrMarkerBack++;
            strength+=firstMinusLast;
        }

        else if ((lastMinusFirst>=firstMinusFirst) && (lastMinusFirst>=firstMinusLast) && (lastMinusFirst>=lastMinusLast)) {
            tempOutArr[arrLen-outputArrMarkerBack-1] = inputArr[arrLen-1-inputArrMarkerFront];

            outputArrMarkerBack++;
            inputArrMarkerFront++;
            strength+=lastMinusFirst;
        }

        else if ((lastMinusLast>=firstMinusFirst) && (lastMinusLast>=firstMinusLast) && (lastMinusLast>=lastMinusFirst)) {
            tempOutArr[arrLen+outputArrMarkerFront+1] = inputArr[arrLen-i-inputArrMarkerFront];

            outputArrMarkerFront++;
            inputArrMarkerFront++;
            strength+=lastMinusLast;
        };

    };

    cout << endl << endl << "Final solution: " << endl;

    for (int h=0; h<arrLen; h++) {
        cout << tempOutArr[arrLen-outputArrMarkerBack+h] << "\t";
    }

    cout << endl << "Strength = " << strength << endl;
}

void sortAscending(int *arr, int length) { //BubbleSort is used.
    for (int x=0; x<length; x++) {
        for (int y=0; y<length; y++) {
            if (arr[y] > arr[y+1]) {
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            };
        };
    };
};
