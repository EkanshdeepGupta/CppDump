#include <iostream>
#include <fstream>

using namespace std;

int countFinal = 0;

void bubbleSort(int *arr, int finish, int start=0) {
    for (int i=start; i<finish; i++) {
        for (int j=start; j<finish-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                countFinal++;
            };
        };
    };
};


int main()
{
    int arr[1000];
    ifstream file("./Untitled 1.csv");

    for (int i=0; i<1000; i++) {
        file >> arr[i];
    }

    bubbleSort(arr, 1000);

    cout << "FINAL: " << endl;

    for (int i=0; i<1000; i++) {
        cout << arr[i] << " \t";
    };

    cout << endl << countFinal << " swaps made.";

    file.close();
}
