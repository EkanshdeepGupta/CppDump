#include <iostream>

using namespace std;

struct stackElement {
	int value;
	stackElement * next;
};

class stack {
	private:
		stackElement * head;
	public:
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

		void traverse() {
			stackElement * temp = head;
			while (temp->next != NULL) {
				cout << temp->value << "\t";
				temp = temp->next;
			};
		};
		
		int lastElement() {
			return head->value;
		};

		stackElement * getHead() {
			return head;
		};

		stack() {
			head = new stackElement;
			head->next = NULL;
			head->value = 0;
		};
};

int main() {
	stack stack1;
	stack1.push(3);
	stack1.pop();
	stack1.push(6);
	stack1.push(7);
	stack1.traverse();

	return 0;
};
