#include <iostream>
#include <fstream>

using namespace std;

int countFinal = 0;

void quickSort(int *arr, int finish, int start=0) {
    finish--;
    int pivot = arr[finish];

    int i=start, j=finish-1;

    while (i<j) {

        while ((arr[i] <= pivot) && i < j) {
            i++;
        };

        while ((arr[j] >= pivot) && j > i)  {
            j--;
        }

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;

        countFinal++;

    };

   i = start;
   while ((arr[i] <= pivot) && (i<finish)) {
            i++;
    };

    int temp = arr[finish];
    arr[finish] = arr[i];
    arr[i] = temp;
    countFinal++;

    int x = start, y = i+1;

    while (x < i-1) {
        if (arr[x+1] < arr[x] ) {
            quickSort(arr, i, start);
            break;
        };
        x++;
    }

    while (y < finish) {
        if (arr[y+1] < arr[y]) {
            quickSort(arr, finish+1, i+1);
            break;
        };
        y++;
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
};
