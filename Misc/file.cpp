#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>

using namespace std;

struct Student {
	string name;
	int number;
};

int main() {
	cout << "AAMBA" << endl;
	ofstream out("/home/ekansh/file.dat", ios::binary);
	if (!out) {cout << "ERROR!";};
	Student S;
	S.name = "John";
	S.number = 42;
	out.write ( (char*) &S, sizeof(S));
	out.close();
	ifstream in("/home/ekansh/file.dat", ios::binary);
	if (!in) {cout << "ERR2";};
	S.name = "My";
	cout << "My, size=" << sizeof(S);
	S.name = "Myssadasdadsadsa";
	cout << "Myssadasdasaas, zise=" << sizeof(S) << endl;
	S.number = 56;
	in.read( (char*) &S, sizeof(S));
	cout << S.name << "|||||" << S.number << endl << endl;
};	
