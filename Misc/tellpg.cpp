#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream x("filename.txt");
	x << "Lorem ipsum lorem ipsum";
	//cout << "TELLG: " << x.tellg() << endl;
	cout << "TELLP: " << x.tellp() << endl;

	return 0;
};
