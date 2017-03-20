#include <iostream>

using namespace std;

int main()
{
    long int input, output1, output2;
    int a, b, c, count1;
    cout << "Enter Number: ";
    cin >> input;

    count1 = 0;

    for (a=input; a>0; a=a/10) { //"count1" stores length of string.
        count1++;
    }

    a = 0; //Variables are reset to zero for reuse (saves memory).

    int digit[count1];
    b = input;

    for (a=0; a<count1; a++) { //Stores each digit separately in digit[].
        c = b%10;
        digit[a] = c;
        b = b/10;
    }

    a = 0; //Variables are reset to zero for reuse (saves memory).
    b = 0;
    c = 0;

    for (a=0; (a+1)<count1; a++) { //Nested for loop used for comparison; puts digits in digit[] in ascending order.
        for (b = 0; (b+1)<count1; b++) { //For loop used for placing highest digit in each case to the last
            if(digit[b] > digit[b+1]) { //Here, actual comparison takes place.
                c = digit[b+1];
                digit[b+1] = digit[b];
                digit[b] = c;
            }
        }
    }

    output1 = 0;
    output2 = 0;

    for (a=0; a<count1; a++) {
        output1 = (10*output1) + digit[count1 - a - 1];
        output2 = (10*output2) + digit[a];
    }

    cout << "Greatest Number Possible :" << endl << "\t" << output1 << endl ;
    cout << "Smallest Number Possible :" << endl << "\t" << output2 << endl ;

    return 0;
}
