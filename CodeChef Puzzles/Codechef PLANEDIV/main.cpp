#include <iostream>

using namespace std;

void answer(long long int lines[][3], int umberOfLines);

void quickSort(double * arr, int finish, int start);

long long int hcf (int a, int b) {
    if (a%b == 0) {return b;}
    else {return hcf(b, a%b);};
}

int main() {
	int testCases;
	cin >> testCases;
	for (;testCases>0; testCases--) {
        int temp;
        cin >> temp;
        const int numberOfLines = temp;
		long long int lines[numberOfLines][3];

		for (int i=0; i<numberOfLines; i++) {
			cin >> lines[i][0] >> lines[i][1] >> lines[i][2];
		};

		answer(lines, numberOfLines);
	};
};

void answer(long long int lines[][3], int numberOfLines) {
    double newLines[numberOfLines][2];

    for (int i=0; i<numberOfLines; i++) {
        if (lines[i][0] != 0) {
            newLines[i][0] = ((double)lines[i][1]) / ((double)lines[i][0]);
            newLines[i][1] = ((double)lines[i][2]) / ((double)lines[i][0]);
        }

        else {
            newLines[i][0] = 1552421212;
            newLines[i][1] = lines[i][2] / lines[i][1];
        };
    };

    quickSort(*newLines, numberOfLines, 0);

   // {for (int i=0; i<numberOfLines; i++) {cout << newLines[i][0] << "-------" << newLines[i][1] << endl;};}

    int lastSameIndex=0, tempLastSameCount=1, lastSameCount=1;

    for (int i=1; i<numberOfLines; i++) {
        if (newLines[i-1][0] != newLines[i][0]) {
            lastSameCount = (tempLastSameCount > lastSameCount)? tempLastSameCount:lastSameCount;
            lastSameIndex = i;
            tempLastSameCount = 1;
        }
        else {
            bool previouslyRepeated = false;
            for (int j=lastSameIndex; j<i; j++) {
                if (newLines[j][1] == newLines[i][1]) {
                    previouslyRepeated = true;
                }
            }

            if (!previouslyRepeated) {
                tempLastSameCount++;
            };
        };

    }

    cout << lastSameCount << endl;
};

void quickSort(double * arr, int finish, int start) {
    finish--;
    double pivot = *((double *)arr + finish*2);

    long long int i=start, j=finish-1;

    while (i<j) {

        while ((*((double *)arr + i*2) <= pivot) && i < j) {
            i++;
        };

        while ((*((double *)arr + i*2) >= pivot) && j > i)  {
            j--;
        }

        double temp = *((double *)arr + i*2);
        *((double *)arr + i*2) = *((double *)arr + j*2);
        *((double *)arr + j*2) = temp;

        temp = *((double *)arr + i*2 + 1);
        *((double *)arr + i*2 + 1) = *((double *)arr + j*2 + 1);
        *((double *)arr + j*2 + 1) = temp;

        i++;
        j--;

//        countFinal++;

    };

   i = start;
   while ((*((double *)arr + i*2) <= pivot) && (i<finish)) {
            i++;
    };

    double temp = *((double *)arr + finish*2);
    *((double *)arr + finish*2) = *((double *)arr + i*2);
    *((double *)arr + i*2) = temp;

    temp = *((double *)arr + finish*2 + 1);
    *((double *)arr + finish*2 + 1) =  *((double *)arr + i*2 + 1);
    *((double *)arr + i*2 + 1) = temp;

//    countFinal++;

    long long int x = start, y = i+1;

    while (x < i-1) {
        if (*((double *)arr + (x+1)*2) < *((double *)arr + x*2) ) {
            quickSort(arr, i, start);
            break;
        };
        x++;
    }

    while (y < finish) {
        if (*((double *)arr + (y+1)*2) < *((double *)arr + y*2)) {
            quickSort(arr, finish+1, i+1);
            break;
        };
        y++;
    };
};
