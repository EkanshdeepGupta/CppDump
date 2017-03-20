#include <iostream>
#include <vector>

using namespace std;

/*  This is a program used to find the continuous subarray which has the largest sum, from an input array.
    Firstly, the 'modifyArray' function takes the array and adds all continuous terms with the same sign together to create a shorter array,
    which is then checked by brute force by 'largestSubarray'  */

struct integerPlaceholder {
        int sum;
        int firstPosition;
        int lastPosition;
};

vector <integerPlaceholder> finalArray;

void modifyArray(vector <int> inputArray, int first);
integerPlaceholder largestSubarray(vector<integerPlaceholder> finalArray);

int main() {
    vector <int> inputArray;
    cout << "Enter terms of array (-1 when done): " << endl;

    int temp;

    do {
        cin >> temp;
        if (temp != -1) {inputArray.push_back(temp);}
        else {break;};

    } while (true);

    modifyArray(inputArray, 0);

    cout << endl << endl;

    integerPlaceholder finalANSWER = largestSubarray(finalArray);

    cout << "Array indices: " << finalANSWER.firstPosition << " to " << finalANSWER.lastPosition << " with a sum of " << finalANSWER.sum;
};

void modifyArray(vector <int> inputArray, int first) {

    if(first < inputArray.size()) {
        bool integerSign = (inputArray[first] > 0);
        int sum = 0;
        int i = 0;

        while (((inputArray[first+i] > 0) == integerSign) && (first+i < inputArray.size())) {
            sum += inputArray[first+i];
            i++;
        };

        integerPlaceholder temp;
        temp.firstPosition = first;
        temp.lastPosition = first+i-1;
        temp.sum = sum;

        finalArray.push_back(temp);

        modifyArray(inputArray, first+i);
    };
};

integerPlaceholder largestSubarray(vector<integerPlaceholder> finalArray) {
    integerPlaceholder finalAnswer;

    for (int i=0; i < finalArray.size(); i++) {
        if (finalArray[i].sum < 0) {i++;};

        for (int j=i; j < finalArray.size(); j+=2) {
            int tempSum = 0;

            if (finalArray[j].sum < 0) {j++;};

            for (int k=i; k<=j; k++) {
                tempSum += finalArray[k].sum;
            }

            if (tempSum > finalAnswer.sum) {
                finalAnswer.sum = tempSum;
                finalAnswer.firstPosition = finalArray[i].firstPosition;
                finalAnswer.lastPosition = finalArray[j].lastPosition;
            };
        };
    };

    return finalAnswer;
}
