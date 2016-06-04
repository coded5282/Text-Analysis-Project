/*
Edward Chen
Header File for Stack Class
Overview of Stack Class: Class used to push and pop various data
Functions:
Stack() -- Constructor for Stack class
~Stack() -- Destructor for Stack class
void Push(string x) -- Pushes onto the top of the stack a string
string Pop() -- Returns the string popped off from stack
*/
#include "Node.h"
#include <iostream>
using namespace std;

class Stack
{
public:
	Stack();
	~Stack();
	void Push(string x);
	string Pop();
};