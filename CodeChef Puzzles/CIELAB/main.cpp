#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long a,b;
	cin >> a >> b;

	long result = a-b;

	if (fmod(result, 10) < 4) {
		cout << (result+1);
	} else {
		cout << (result-1);
	};
	
	return 0;
};

