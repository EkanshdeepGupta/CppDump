#include <iostream>

using namespace std;

int main() {
	int testCases;
	cin >> testCases;

	long int answer[testCases];

	for (int alpha=0; alpha<testCases; alpha++) {
		long int numberOfRooms;
		cin >> numberOfRooms;

		char arr[numberOfRooms];

		long int greenCounter = 0;
		long int redCounter = 0;
		long int blueCounter = 0;

		for (long int i=0; i<numberOfRooms; i++) {
			cin >> arr[i];
			if (arr[i] == 'G') {greenCounter++;}
			else if (arr[i] == 'B') {blueCounter++;}
			else if (arr[i] == 'R') {redCounter++;};
		};

		if ((greenCounter >= blueCounter) && (greenCounter >= redCounter)) {
			answer[alpha] = (blueCounter+redCounter);
		}
		else if ((blueCounter >= greenCounter) && (blueCounter >= redCounter)) {
			answer[alpha] = (greenCounter+redCounter);
		}
		else if ((redCounter >= greenCounter) && (redCounter >= blueCounter)) {
			answer[alpha] = (greenCounter+blueCounter);
		};
	}

	for (int beta=0; beta<testCases; beta++) {
		cout << answer[beta] << endl;
	};
}