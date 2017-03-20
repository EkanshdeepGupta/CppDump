#include <iostream>

using namespace std;

int main() {
	int testCases;
	cin >> testCases;
	long long int answers[testCases];

	for (int alpha=0; alpha<testCases; alpha++) {
		long long int redCounter;
		long long int blueCounter;
		long long int greenCounter;
		long long int k;

		cin >> redCounter >> blueCounter >> greenCounter;
		cin >> k;

		long long int maxBalloons = 0;

		if (redCounter >= (k-1)) {maxBalloons += (k-1);}
		else {maxBalloons += redCounter;};

		if (greenCounter >= (k-1)) {maxBalloons += (k-1);}
		else {maxBalloons += greenCounter;};

		if (blueCounter >= (k-1)) {maxBalloons += (k-1);}
		else {maxBalloons += blueCounter;};

		maxBalloons++;

		answers[alpha] = maxBalloons;
	};

	for (int beta=0; beta<testCases; beta++) {
		cout << answers[beta] << endl;
	}
}