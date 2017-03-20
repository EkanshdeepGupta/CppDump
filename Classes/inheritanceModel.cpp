#include <iostream>

using namespace std;

class base {
	public:
		int getA() {
			cout << a << endl;
		};
		void setA(int x) {
			a = x;
		};

		int b;

	private:
		int a;
};

class derived : public base {
	public: 
		int c;
	//	int getA1() { GIVES ERROR!!!
	//		cout << A;
		};
};

int main() {
	derived D;

	D.c = 5;
	cout << D.c << endl;
	D.setA(5);
	D.getA();

	return 0;
};


