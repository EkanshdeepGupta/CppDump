#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace::std;

string digitName(int num) {
	switch (num) {
		case 0: return ""; break;
		case 1: return "one"; break;
		case 2: return "two"; break;
		case 3: return "three"; break;
		case 4: return "four"; break;
		case 5: return "five"; break;
		case 6: return "six"; break;
		case 7: return "seven"; break;
		case 8: return "eight"; break;
		case 9: return "nine"; break;
		default: return "NaN";
	};
};

string twoDigitName(int num1) {
	if (num1/10 != 1) {
		string ten;

		switch(num1/10) {
			case 0: ten = ""; break;
			case 2: ten = "twenty"; break;
			case 3: ten = "thirty"; break;
			case 4: ten = "forty"; break;
			case 5: ten = "fifty"; break;
			case 6: ten = "sixty"; break;
			case 7: ten = "seventy"; break;
			case 8: ten = "eighty"; break;
			case 9: ten = "ninety"; break;
			default: ten = "NaN"; break;
		};

		return ( ten + " " + digitName(num1%10));
	}

	else {
		switch (num1) {
			case 10: return "ten"; break;
			case 11: return "eleven"; break;
			case 12: return "twelve"; break;
			case 13: return "thirteen"; break;
			case 14: return "fourteen"; break;
			case 15: return "fifteen"; break;
			case 16: return "sixteen"; break;
			case 17: return "seventeen"; break;
			case 18: return "eighteen"; break;
			case 19: return "nineteen"; break;
			default: return "NaN"; break;
		};
	};
};


string threeDigitName(int num1) {
	string hund = digitName(num1/100);

	if (num1/100 == 0) {
		return twoDigitName(num1%100);
	}

	else {
		return ( hund + " hundred " + twoDigitName(num1%100) );
	};
};

string words1;
string placeholder[] = {"", "thousand", "million", "billion", "trillion", "quadrillion"};
	

void recursion(int num, int place) {
	if (num/1000 != 0) {
		recursion(num/1000, place+1);
	}
	
	string tempThreeDigitName = threeDigitName(num%1000);

	if (tempThreeDigitName != " ") {
		words1 += " " + threeDigitName(num%1000) + " " + placeholder[place];
	};
};

string numToWords(int num) {
	//string words1;
	recursion(num, 0);

	return words1;
};


int main() {
	cout << "Enter number: ";
	int num;
	cin >> num;

	string words = numToWords(num);
	string words2;
	bool startspace = true;

	for (int i=0; i < words.length(); i++) {
		if (startspace == true) {
			if (words[i] != ' ') {
				words2+= toupper(words[i]);
				startspace = false;
			};
		}

		else {
			if (!(words[i] == ' ' && words[i+1] == ' ')) {
				words2+= words[i];
			};
		};
	};

	cout << num << " = " << words2 << endl;
	return 0;
}


