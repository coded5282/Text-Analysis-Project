/*
Edward Chen
Source File for Stack Class
Overview of Stack Class: Class used to push and pop various data
Functions:
void Push(string x) -- Pushes onto the top of the stack a string
string Pop() -- Returns the string popped off from stack
*/

#include "Stack.h"
#include <iostream>
using namespace std;

/*
Purpose: Constructor for stack class
Assumptions - 
Pre-condition: Creating stack object
Post-condition: Stack object is created
*/
Stack::Stack()
{
}
/*
Purpose: Destructor for stack class
Assumptions - 
Pre-condition: Stack object is created
Post-condition: Stack object is destructed 
*/
Stack::~Stack()
{
}

Node* headp = NULL;
/*
Purpose: To push on data onto the top of the stack
Assumptions - 
Pre-condition: Stack object is created and string is valid
Post-condition: String is pushed onto top of stack and stays same
*/
void Stack::Push(string x)
{
	Node* temp = NULL;
	temp->setNext(headp);
	temp->setWord(x);
	headp = temp;
}
/*
Purpose: To pop off data from the top of the stack
Assumptions - 
Pre-condition: Stack object is created
Post-condition: String is popped out from top of stack
*/
string Stack::Pop()
{
	if (headp == NULL)
	{
		return 0;
	}
	Node* temp;
	temp = headp;
	headp = headp->getNext();
	string theWord = temp->getWord();
	return theWord;
}

