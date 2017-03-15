#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

#define DEFAULT_SIZE 20

/*
*
*/

int isp(char c)
{
	int i;
	if ((c == '+') || (c == '-'))
	{
		i = 1;
	}
	if ((c == '*') || (c == '/'))
	{
		i = 2;
	}
	if (c == '^')
	{
		i = 3;
	}
	if (c == '(')
	{
		i = 0;
	}
	if (c == '#') {
		i = -1;
	}
	return  i;
}
int icp(char c)
{
	int i;
	if ((c == '+') || (c == '-'))
	{
		i = 1;
	}
	if ((c == '*') || (c == '/'))
	{
		i = 2;
	}
	if (c == '^')
	{
		i = 4;
	}
	if (c == '(')
	{
		i = 4;
	}
	return  i;
}





class Stack {
	char *arr;
	int tos, capacity;
public:
	//Constructors
	Stack();
	Stack(int size);

	//Destructor
	~Stack();

	//Methods
	void push(char a);
	char pop();
	int get_size();
	bool is_empty();
	bool is_full();
	void display();
	char get_top();


};


Stack::Stack() {
	arr = new char[DEFAULT_SIZE];
	tos = 0;
	capacity = DEFAULT_SIZE;
}

Stack::Stack(int size) {
	arr = new char[size];
	tos = 0;
	capacity = size;
}

Stack::~Stack() {
	delete[] arr;
}

void Stack::push(char a) {
	if (!is_full()) {
		arr[tos++] = a;
		cout << "pushing " << a << endl;
	}
	else
		cout << "Sorry, the stack is full. Push failed!" << endl;

}
char Stack::pop() {
	if (!is_empty()) {
		cout << "popping " << arr[tos - 1] << endl;
		return arr[--tos];
	}
	else {
		//cout << "Sorry, the stack is empty. Pop failed!" << endl;
		return -1;
	}


}


char Stack::get_top() {
	if (!is_empty())
		return arr[tos - 1];
	else {
		//cout << "Sorry, the stack is empty. Pop failed!" << endl;
		return 'E';
	}
}


int Stack::get_size() {
	return tos;

}
bool Stack::is_empty() {
	if (tos == 0)
		return true;
	else
		return false;


}
bool Stack::is_full() {
	if (tos == capacity)
		return true;
	else
		return false;

}

void Stack::display() {
	if (tos == 0)
		cout << "The stack is empty" << endl;
	else {
		for (int i = 0; i<tos; i++)
			cout << arr[i] << " ";
		cout << endl;
	}


}
class Stacktype {
	float *arr;
	int tos, capacity;
public:
	//Constructors
	Stacktype();
	Stacktype(int size);

	//Destructor
	~Stacktype();

	//Methods
	void push(float a);
	float pop();
	int get_size();
	bool is_empty();
	bool is_full();
	void display();
	float get_top();


};


Stacktype::Stacktype() {
	arr = new float[DEFAULT_SIZE];
	tos = 0;
	capacity = DEFAULT_SIZE;
}

Stacktype::Stacktype(int size) {
	arr = new float[size];
	tos = 0;
	capacity = size;
}

Stacktype::~Stacktype() {
	delete[] arr;
}

void Stacktype::push(float a) {
	if (!is_full()) {
		arr[tos++] = a;
		cout << "pushing " << a << endl;
	}
	else
		cout << "Sorry, the stack is full. Push failed!" << endl;

}
float Stacktype::pop() {
	if (!is_empty()) {
		cout << "popping " << arr[tos - 1] << endl;
		return arr[--tos];
	}
	else {
		//cout << "Sorry, the stack is empty. Pop failed!" << endl;
		return -1;
	}


}


float Stacktype::get_top() {
	if (!is_empty())
		return arr[tos - 1];
	else {
		//cout << "Sorry, the stack is empty. Pop failed!" << endl;
		return 'E';
	}
}


int Stacktype::get_size() {
	return tos;

}
bool Stacktype::is_empty() {
	if (tos == 0)
		return true;
	else
		return false;


}
bool Stacktype::is_full() {
	if (tos == capacity)
		return true;
	else
		return false;

}

void Stacktype::display() {
	if (tos == 0)
		cout << "The stack is empty" << endl;
	else {
		for (int i = 0; i<tos; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
}


int main() {
	Stack stack(50);
	string infix = "2+3*(4+2)/7";
	cout << infix << endl;
	stringstream ss;
	cout << endl;



	for (char c : infix) {
		cout << "current char " << c << endl;

		if ('0' <= c && c <= '9') {
			ss << c;
		}
		else if (c == '(') {
			stack.push(c);

		}

		else if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-') {
			if (stack.is_empty()) {
				stack.push(c);

			}
			else if (!stack.is_empty()) {
				while (!stack.is_empty() && isp(stack.get_top()) >= icp(c)) {
					ss << stack.pop();

				}

				stack.push(c);
			}


		}

		else if (c == ')') {
			while (stack.get_top() != '(' && !stack.is_empty()) {
				ss << stack.pop();

			}
			if (stack.get_top() == '(')
				stack.pop();

		}

		cout << "output string " << ss.str() << endl;
		cout << "Stack : ";
		stack.display();
		cout << endl;


	}

	while (!stack.is_empty()) {

		ss << stack.pop();
	}


	string postfix = ss.str();
	cout << "Postfix : " << postfix << endl;

	Stacktype stacktype(50);

	for (char c : postfix) {
		{
			if ('0' <= c && c <= '9') {
				float a = float(c - '0');
				cout << "a: " << a << endl;
				stacktype.push(a);
			}
			else if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-') {
				float q = stacktype.pop();
				float r = stacktype.pop();
				if (c == '^') {
					stacktype.push(pow(r, q));
				}
				if (c == '*') {
					stacktype.push(r*q);
				}
				if (c == '/') {
					stacktype.push(r / q);
				}
				if (c == '+') {
					stacktype.push(r + q);
				}
				if (c == '-')
					stacktype.push(r - q);
			}


		}
	}
	cout << "evaluate the value::" << endl;
	stacktype.display();


	return 0;


}


