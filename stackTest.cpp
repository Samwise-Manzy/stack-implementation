#include <iostream>
#include <stack>
#include "myStack.h"

using namespace std;

void postfixTest() {
	int operandCount = 0; // assures proper sufficient operands and legal post-fix expression
	myStack operandStack(100);
	cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << endl;
	cout << "and enter '=' to indicate the end of the expression and to output the result." << endl;
	
	while(1){

		char inputHolder;
		cin >> inputHolder;


		if (inputHolder >= '0' && inputHolder <= '9') {
			operandStack.push(inputHolder - '0');
			operandCount++;
			
		} else if(inputHolder == '+' || inputHolder == '-' || inputHolder == '*' || inputHolder == '/') {
			if (operandCount < 2) {
				cout << "Error! No sufficient operands.\n";
			} else {
				int val1 = operandStack.pop();
				int val2 = operandStack.pop();

				switch (inputHolder) { 		// switch checks for operator and input and executes accordingly;
					case '+':				// places value back in stack
						operandStack.push(val2 + val1);
						break;
					case '-':
						operandStack.push(val2 - val1);
						break;
					case '*':
						operandStack.push(val2 * val1);
						break;
					case '/':
						operandStack.push(val2 / val1);
						break;
				}
				operandCount--;				// decroments soperand count after operation execution 
			}
		} else {
			if (operandCount == 1) {
				cout << "The entered post-fix expression results is " << operandStack.pop() << endl;
			} else {
				cout << "The entered post-fix expression was not a legal one.\n";
			}
		}
	}
}

int main()
{
    cout << "Testing the basic functions of the stack..." << endl;
	cout << "Please enter the max capacity of the testStack: ";
	int testSize;
	cin >> testSize;
	myStack testStack(testSize);
	
	cout << "Testing..." << endl;
	while(1) {
		cout << "Please enter 'p' for push, 'o' for pop, 'e' for exit:  ";
		char userChoice;
		cin >> userChoice;
		
		if(userChoice == 'e')
			break;
		
		switch (userChoice) {
			case 'p':			
				if(!testStack.isFull()) {
					cout << "Please enter the integer you would like to push: ";
					int userInt;
					cin >> userInt;
					testStack.push(userInt);
				}
				else
					cout << "Nothing has been pushed in. The stack is full!" << endl;
				break;
			case 'o':
				if(!testStack.isEmpty())
					cout << testStack.pop() << " has been popped out" << endl;
				else
					cout << "Nothing has been popped out. The stack is empty!" << endl;
				break;
			default:
				cout << "Illegal user-input character. Please try again." << endl;
		}
	}

	cout << "Now, start to use a stack to evaluate postfix expressions..." << endl;
	postfixTest();	
	
	return 0;
}

