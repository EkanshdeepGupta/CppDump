#include <iostream>

using namespace std;

/*This program is made to solve the puzzle in which n soldiers stand in a circle and take turns killing the next person and then passing the sword to the one ahead. You have to find the survivor.*/

int aliveCount = 0;

int finalSoldier(bool * soldierAlive, int n) {
	int x = 1;
	while (aliveCount > 1) {
		while (soldierAlive[x] == false) {
			x = (x+1)%n;
		};
		soldierAlive[x] = false;
		aliveCount--;
			
		x = (x+1)%n;
		
		while (soldierAlive[x] == false) {
			x = (x+1)%n;
		};

		x = (x+1)%n;
	};

	for (int i=0; i<n; i++) {
		if (soldierAlive[i] == true) {
			return (i+1);
		};
	};
};
		
		


int main() {
	cout << "Enter number of soldiers: ";
	int n;
	cin >> n;
	
	aliveCount = n;	

	bool soldierAlive[n];
	for (int i=0; i<n; i++) {
		soldierAlive[i] = true;
	};

cout << finalSoldier(soldierAlive, n) << endl;

};

