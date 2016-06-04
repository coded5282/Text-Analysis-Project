/*
Edward Chen
Header file for Node Class
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

#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{
private:
	Node* nextp;
	int wordCount;
	char endSymbol;
	int count;
	string word;
	char theChar;
public:
	void setWordCt(int num);
	void setSymb(char sym);
	int getWordCt();
	char getSymb();
	Node();
	~Node();
	void setNext(Node* theNextp);
	Node* getNext();
	void setWord(string x);
	string getWord();
	void setCount(int x);
	int getCount();
	void setChar(char c);
	char getChar();
};


#endif