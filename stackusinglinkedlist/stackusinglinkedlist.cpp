#include <iostream>
using namespace std;

//Node class representing a single node in the linked list
class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		next = NULL;
	}
};

//Stack Class
class stack {
private:
	Node* top;	//pointer to the top node of the stack

public:
	stack()
	{
		top = NULL;	//initialize the stack with a null top pointer
	}
	//push operation: Insert an element onto the top of the stack
	int push(int value) {
		Node* newNode = new Node();	//1. Allocate memory for the new node
		newNode->data = value;		//2. assign value
		newNode->next = top;		//3. set the next pointer of the new node to the current top node
		top = newNode;				//4. update the top pointer to the new node
		cout << "Push value: " << value << endl;
		return value;
	}

	void pop() {
		if (isEmpty())
		{
			cout << "Stack is empty." << endl;
		}
		cout << "Popped value: " << top->data << endl;
		top = top->next;
	}

	void peek() {
		if (top == NULL)
		{
			cout << "List is empty." << endl;
		}
		else {
			Node* current = top;
			while (current != NULL)
			{
				cout << current->data << " " << endl;
				current = current->next;
			}
			cout << endl;
		}
	}

	bool isEmpty()
	{
		return top == NULL;
	}

};
int main()
{
	stack stack;

	int choice = 0;
	int value;

	while (choice != 5)
	{
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3> Peek\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the value to push: ";
			cin >> value;
			stack.push(value);
			break;
		case 2:
			if (!stack.isEmpty()) {
				stack.pop();
			}
			else {
				cout << "Stack is empty. Cannot pop" << endl;
			}
			break;
		case 3:
			if (!stack.isEmpty()) {
				stack.peek();
			}
			else {
				cout << "Stack is empty. No top value" << endl;
			}
			break;
		case 4:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}