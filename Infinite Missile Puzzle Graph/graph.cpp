

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int mappedValue(int x) {
	if (x%2 ==0) {
		return x/2;
	}
	
	else {
		return (-1)*((x+1)/2);
	};
};
	


struct point {
	int x;
	int y;
};

int main() {
	int initial = 0;
	int velocity = 0;

	vector <point> pointVector;
	
	int time = 0;

	while(time <=10000) {
		int initialTemp = initial;
		int velocityTemp = velocity;

		while (initialTemp >= 0) {
			int y = mappedValue(initialTemp) + (time*mappedValue(velocityTemp));
			struct point pointTemp;
			pointTemp.x = time;
			pointTemp.y = y;
			pointVector.push_back(pointTemp);

			time++;
			initialTemp--;
			velocityTemp++;
		};

		initial++;
	};

	for (int j=0; j<=10; j++) {
		cout << pointVector[j].y << endl;
	};
	
	ofstream asd("/home/ekansh/as.txt");	
	
	for (int j=0;j<=10000; j++) {
		asd << pointVector[j].x << "  " <<  pointVector[j].y << endl;
	};

	asd.close();

return 0;
};
