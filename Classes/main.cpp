#include <iostream>
#include <string>

using namespace std;


class Dumbass {
    private:
        string name;

    public:
        Dumbass(string james) {setName(james);}
        void setName(string x) {name = x;};
        string getName() {return name;};

};

int main() {
    Dumbass jackass("Rowley");
    cout << jackass.getName();

    Dumbass jeffrey("Joey Tribbiani");
    cout << jeffrey.getName();

    cout << jackass.getName();
    return 0;
}
