#include <iostream>

using namespace std;

class parent {
    public:
        virtual void printer() {
            cout << "SHAKIMAAN!" << endl;
        };
};

class son: public parent {
    public:
        void printer() {
            cout << "I AM THE SON OF ODIN" << endl;
        };
};

class daughter: public parent {
    public:
        void printer() {
            cout << "I AM THE DAUGHTER OF ZEUS" << endl;
        };
};

int main()
{
    son thor;
    daughter artemis;
    parent odin;
    parent *zeus = &artemis;

    odin.printer();
    zeus->printer();

}
