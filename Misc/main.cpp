#include <iostream>
#include <stdlib.h>
#include <string.h>

/*using namespace std;

int main() {

system("stty raw");

char input; //= getchar();

cin >> input;

cout << input;

system ("stty cooked");

return 0;
}
*/

using namespace std;

int main() {
    unsigned long long int x;
    x=0;
    x--;

    int counter = 0;

    cout << x << endl;
    //cout << convert.len();
    while (x>0) {
    counter++;
    x /= 10;
    }

    cout << counter;
}
