#include <iostream>
#include <fstream>

using namespace std;

int countFinal = 0;

void quickSort(int *arr, int finish, int start=0) {
    finish--;
    int pivot = arr[finish];

    int biggerIndex;
    int smallerIndex;

    for (int i=0; /*i<=((finish-start)/2)*/; i++) {

        for (int j=start; j<=finish; j++) {
            if (arr[j] >= pivot) {
                biggerIndex = j;
                break;
            }
        };

        for (int j=finish-1; j>=start; j--) {
            if (arr[j] <= pivot) {
                smallerIndex = j;
                break;
            }
        };

        if (biggerIndex < smallerIndex) {
            int temp = arr[biggerIndex];
            arr[biggerIndex] = arr[smallerIndex];
            arr[smallerIndex] = temp;

            countFinal++;
        }

        else if (smallerIndex <= biggerIndex) {
            break;
        };
    };

    {
        int i = 0;
        while ((arr[i] <= pivot) && (i<finish)) {
                i++;
        };

        int temp = arr[finish];
        arr[finish] = arr[i];
        arr[i] = temp;
        countFinal++;


        bool ascendingComplete1 = true;
        bool ascendingComplete2 = true;


        for (int j=start; j<i-1; j++) {
            if (arr[j] > arr[j+1]) {
                ascendingComplete1 = false;
            };
        };

        for (int j=i+1; j<finish; j++) {
            if (arr[j] > arr[j+1]) {
                ascendingComplete2 = false;
            };
        };

        if (!(ascendingComplete1)) {
            quickSort(arr, i, start);
        };

        if (!(ascendingComplete2)) {
            quickSort(arr, finish+1, i+1);
        };
    };
};

int main() {
    int arr[1000];
    ifstream file("./Untitled 1.csv");

    for (int i=0; i<1000; i++) {
        file >> arr[i];
    }

    quickSort(arr, 1000);

    cout << "FINAL: " << endl;

    for (int i=0; i<1000; i++) {
        cout << arr[i] << " \t";
    };

    cout << endl << countFinal << " swaps made.";

    file.close();
    /*
    int arr[4] = {1, 3, 2, 4};
    quickSort(arr, 4);
    cout << "FINAL: " << endl;
    for (int i=0; i<4; i++) {
        cout << arr[i] << "\t";
    };
    cout << endl << countFinal;*/
};
