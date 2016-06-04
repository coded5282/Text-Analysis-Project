/*
Edward Chen
Source file for Node Class
Overview of Node Class: The class used to create linked lists and store data
Functions:
void setWordCt(int num) -- Sets the word count in the node
void setSymb(char sym) -- Sets the ending symbol in the node
int getWordCt() -- Returns the word count 
char getSymb() -- Returns the last symbol
Node() -- Constructor for Node Class
~Node() -- Destructor for Node Class
void setNext(Node* theNext) -- Sets the next pointer of node
Node* getNext() -- Returns the Node next in linked list
void setWord(string x) -- Sets the word in the Node
string getWord() -- Returns the word that was set
void setCount(int x) -- Sets the number of times the word/char appears
int getCount() -- Returns the count
void setChar(char c) -- Sets the character in Node
char getChar() -- Returns the character set in Node
*/

#include "Node.h"
#include <iostream>
using namespace std;

/*
Purpose: To set the word count in the Node
Assumptions - 
Pre-condition: Node object is created
Post-condition: Word count is set
*/
void Node::setWordCt(int num)
{
	wordCount = num;
}
/*
Purpose: To set the end symbol in the Node
Assumptions - 
Pre-condition: End symbol is given and Node object is created
Post-condition: End symbol is set
*/
void Node::setSymb(char sym)
{
	endSymbol = sym;
}
/*
Purpose: To return the word count set in the Node
Assumptions - 
Pre-condition: Node object is created and word count is set
Post-condition: Word count is returned
*/
int Node::getWordCt()
{
	return wordCount;
}
/*
Purpose: Returns the end symbol in the Node
Assumptions - 
Pre-condition: Node object is created and end symbol is set
Post-condition: End symbol is returned
*/
char Node::getSymb()
{
	return endSymbol;
}
/*
Purpose: Constructor for Node class
Assumptions - 
Pre-condition: Creating Node object
Post-condition: Node object is created and next pointer is set
*/
Node::Node()
{
	nextp = NULL;
}
/*
Purpose: Deconstructor for Node Class
Assumptions - 
Pre-condition: Node object is created
Post-condition: Node object is destructed
*/
Node::~Node()
{
}
/*
Purpose: Sets the next pointer of Node object
Assumptions - 
Pre-condition: Node object is created 
Post-condition: Next pointer is set
*/
void Node::setNext(Node* theNextp)
{
	nextp = theNextp;
}
/*
Purpose: Returns the Node referred to by the next pointer
Assumptions - 
Pre-condition: Node object is created
Post-condition: Node referred to by the next pointer is returned
*/
Node* Node::getNext()
{
	return nextp;
}
/*
Purpose: Sets the word for the Node
Assumptions - 
Pre-condition: Node object is created and string is valid
Post-condition: Word string is set
*/
void Node::setWord(string x)
{
	word = x;
}
/*
Purpose: Return the word in the Node
Assumptions - 
Pre-condition: Node object is created and word is set
Post-condition: Word is returned
*/
string Node::getWord()
{
	return word;
}
/*
Purpose: Sets the number of time the word/char appears
Assumptions - 
Pre-condition: Node object is created and count is int
Post-condition: Count is set
*/
void Node::setCount(int x)
{
	count = x;
}
/*
Purpose: Count in Node is returned
Assumptions - 
Pre-condition: Node object is created and count is set
Post-condition: Count is returned
*/
int Node::getCount()
{
	return count;
}
/*
Purpose: To set the character in the Node
Assumptions - 
Pre-condition: Node object is created and character is valid
Post-condition: Character is set
*/
void Node::setChar(char c)
{
	theChar = c;
}
/*
Purpose: To return the character in Node object
Assumptions - 
Pre-condition: Node object is created and character is set
Post-condition: Character is returned
*/
char Node::getChar()
{
	return theChar;
}