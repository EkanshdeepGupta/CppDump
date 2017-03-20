#include <iostream>

using namespace std;

struct stackElement {
	int value;
	stackElement * next;
};

double gCount=0;

class stack {
	private:
		stackElement * head;
	public:

		stack() {
			head = new stackElement;
			head->next = NULL;
			head->value = 0;
		};
		void push(int x) {
			stackElement * temp = new stackElement;
			temp->value = x;
			temp->next = head;
			head = temp;
		};

		void pop() {
			head->value = 0;
			stackElement * temp = head;
			head = head->next;
			delete temp;
		};

		void traverse(stackElement * temp) {
			if (temp->next == NULL) {}

			else if ((temp->next)->next == NULL) {
				printElement(temp);
			}

			else {
				traverse(temp->next);
				printElement(temp);
			};
		};

		void printElement(stackElement * temp) {
			cout << temp->value << ".";
		};

		
		int lastElement() {
			return head->value;
		};

		stackElement * getHead() {
			return head;
		};
};


/*stack * stack1 = new stack;
stack * stack2 = new stack;
stack * stack3 = new stack;*/

stack stack1, stack2, stack3;

void initialise(int size=7) {
	for (int i=size; i>0; i--) {
		stack1.push(i);
	};
};


void print() {
	cout << "STACK1: "; 
	stack1.traverse(stack1.getHead());
	cout << endl;
	cout << "STACK2: ";
	stack2.traverse(stack2.getHead());
	cout << endl;
	cout << "STACK3: ";
	stack3.traverse(stack3.getHead());
	cout << endl;
	cout << endl;
};

void recursion(int size2, stack  &initialStack=stack1, stack  &finalStack=stack3, stack &tempStack=stack2) {
	if (size2 == 1) {
		initialStack.pop();
		finalStack.push(1);
		gCount++;
		print();
	}

	else {
		recursion((size2-1), initialStack, tempStack, finalStack);

		initialStack.pop();
		finalStack.push(size2);
		gCount++;
		print();

		recursion((size2-1), tempStack, finalStack, initialStack);
	}
};

int main() {
	int size;
	cout << "Enter size: ";
	cin >> size;
	initialise(size);
	print();
	recursion(size);
	
	cout << "TOTAL STEPS: " << gCount << endl << endl;
	return 0;
};
