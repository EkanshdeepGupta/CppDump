#include <iostream>

using namespace std;

/* This is to check a counterexample to the following inequality:

   sigma(n) * sigma(1/n) > pi(n) + n //sigma->summation, pi->product

   TURNS OUT IT'S <i>False</i>!!
*/

int main() {
	double sum1, product1;
	double sum2;
	double lhs;
	double rhs;

	for (double x=1; x<=1000; x++) {
		sum1=0;sum2=0;product1=1;lhs=0;rhs=0;

		for (double y=1; y<=x; y++) {
			sum1 += y;
			sum2 += (1/y);
			product1 *= y;
		};

		lhs = sum1*sum2;
		rhs = product1 + x;

		cout << "X=" << x << "\tsum1=" << sum1 << "\tsum2=" << sum2 << "\tproduct1=" << product1 << "\tLHS-RHS=" << lhs-rhs;

		if ((lhs-rhs) < 0) {
			cout << " ALERT!!!";
		};

		cout << endl;
	};

	return 0;
};



