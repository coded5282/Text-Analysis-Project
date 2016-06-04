/*
Edward Chen
Header file for Line Class
Overview of Line Class: The Line class contains each of the details 
for each sentence in the document and is arranged in a Line array in the
Document class.
Functions in file:
void setStr(string sent) -- Sets the string of words in each sentence
string getStr() -- Returns the string of words for each sentence
void setWordCt(int count) -- Sets the word count of each sentence
int getWordCt() -- Returns the number of words from each sentence
void setCharCt(int charCt) -- Sets the number of characters per sentence
int getCharCt() -- Returns the number of characters per sentence
Line() -- Constructor for Line Class
Line(string phrase) -- Constructor for Line Class to also set the string at initialization
Line(string phrase, int num) -- Constructor to also set string of words as well as id of line
~Line() -- Destructor for Line Class
string* parseWords() -- Returns the array of string of words in each sentence
char* parseChar() -- Returns the array of characters in each line
char* parseChar(string* arrString) -- Returns the array of characters given an array of strings
*/

#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <string>
using namespace std;


class Line
{
private:
	string str; 
	int wordCount;
	int charCount;
public:
	int id;
	void setStr(string sent);
	string getStr();
	void setWordCt(int count);
	int getWordCt();
	void setCharCt(int charCt);
	int getCharCt();
	Line();
	Line(string phrase);
	Line(string phrase, int num);
	~Line();
	string* parseWords(); 
	char* parseChar();
	char* parseChar(string* arrString);
};

#endif