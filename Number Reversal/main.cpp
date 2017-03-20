#include<iostream>
#include<math.h>

using namespace std;

int main() {
cout<<"Enter number: ";
long int numb, a, m, n, final, count;
cin>>numb;
count = 0;

for (n=numb; n>10; n=n/10){
count++;
};

final = 0;

for (m=numb; m>0; m=m/10){
a = m%10;
final += a*pow(10, count);
count--;
};

cout<<"\nReversed number: "<<final<<endl;

return 0;

}
