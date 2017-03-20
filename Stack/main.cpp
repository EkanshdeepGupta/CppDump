#include <iostream>

using namespace std;

struct stackElement {
    int value;
    stackElement * nextElement;
} stack1;

//stackElement stack1;

void push();
void pop();
void traverse();

int stackCount = 0;

int main() {
    int choice;
     do {
        cout << "MENU: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                break;
            default:
                choice = -1;
                break;
        }

     } while (choice != 4);
};

void push() {
    cout << "Enter value: ";
    int tempInt;
    cin >> tempInt;
    cout << endl;

    stackElement * temp1 = &stack1;
    stackElement *  temp2;

    for (int i=0; i<stackCount; i++) {
        temp2 = (*temp1).nextElement;
        temp1 = temp2;
    };

    (*temp1).nextElement = new stackElement;

    temp2 = (*temp1).nextElement;

    (*temp2).value = tempInt;

    stackCount++;
};

void pop() {
    stackCount--;

    stackElement * temp1 = &stack1;
    stackElement *  temp2;

    for (int i=0; i<stackCount; i++) {
        temp2 = (*temp1).nextElement;
        temp1 = temp2;
    };

    delete (*temp1).nextElement;
    cout << endl;
};

void traverse() {
    stackElement * temp1 = &stack1;
    stackElement *  temp2;

    for (int i=0; i<stackCount; i++) {
        temp2 = (*temp1).nextElement;
        temp1 = temp2;

        cout << (*temp1).value << "\t";
    };

    cout << endl << endl;
};
