#include <iostream>

using namespace std;

int main() {
	long long int testCases;

	cin >> testCases;

	bool answer[testCases];

	for (long long int alpha=0; alpha<testCases; alpha++) {
		unsigned long long int n;
		unsigned long long int m;

		cin >> n >> m;
		if (((n%2==0)&&(n>2)&&(m==1)) || ((m%2==0)&&(m>2)&&(n==1))) {
			answer[alpha] = false;
		}
		else {
			if (((n%2) == 0) || ((m%2) == 0)) {
				answer[alpha] = true;
			}

			else {
				answer[alpha] = false;
			};
		};
	};

	for (long long int alpha=0; alpha<testCases; alpha++) {
		if (answer[alpha] == true) {cout << "Yes" << endl;}
		else {cout << "No" << endl;};
	};
};