/*
Edward Chen
Source file for Line Class
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

#include "Line.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
Purpose: To set the string of words for each Line
Assumptions - 
Pre-condition: Line object is created 
Post-condition: String of words is set
*/
void Line::setStr(string sent) 
{
	str = sent; 
}
/*
Purpose: To return the string of words for each Line
Assumptions - 
Pre-condition: Line object is created and has a string of words 
Post-condition: String of words is returned
*/
string Line::getStr() 
{
	return str; 
}
/*
Purpose: Word count of each Line is set
Assumptions - 
Pre-condition: Line object is created
Post-condition: Word count is set
*/
void Line::setWordCt(int count)
{
	wordCount = count;
}
/*
Purpose: Returns the word count for each Line 
Assumptions - 
Pre-condition: Line object is created
Post-condition: Word count and character count are created
*/
int Line::getWordCt()
{
	int numSpaces = 0;
	int numChar = 0;
	if (wordCount == NULL)
	{
		for ( int i = 0; i < 99999; i++ )
		{
			if (str[i] != NULL)
			{
				numChar++;
			}
			else
			{
				break;
			}
		}
		setCharCt(numChar);
		for ( int i = 0; i < numChar; i++ )
		{
			if (str[i] == ' ')
			{
				numSpaces++;
			}
		}
		wordCount = numSpaces + 1;
	}
	return wordCount; 
}
/*
Purpose: Sets the character count for each Line
Assumptions - 
Pre-condition: Line object is created
Post-condition: Character count is set
*/
void Line::setCharCt(int charCt)
{
	charCount = charCt; 
}
/*
Purpose: Returns the character count for each Line
Assumptions - 
Pre-condition: Line object is created and character count is set
Post-condition: Character count for each line is returned
*/
int Line::getCharCt()
{
	return charCount; 
}
/*
Purpose: Constructor for Line object
Assumptions - 
Pre-condition: Creating Line object
Post-condition: Line object is created and id is set to random value
*/
Line::Line()
{
	id = rand(); 
}
/*
Purpose: Constructor for Line class to also set string of words
Assumptions - 
Pre-condition: Creating Line object
Post-condition: Line object is created, string is set, and id is random
*/
Line::Line(string phrase)
{
	str = phrase; 
	id = rand();
}
/*
Purpose: Constructor for Line object to set string of words and ID
Assumptions - 
Pre-condition: Creating Line object
Post-condition: String of words is set, id is set, and object is created
*/
Line::Line(string phrase, int num)
{
	str = phrase;
	id = num;
}
/*
Purpose: Destructor for Line Class
Assumptions - 
Pre-condition: Line object is created
Post-condition: String of words is cleared
*/
Line::~Line()
{
	str.clear(); 
}
/*
Purpose: Returns the array of strings of words in each sentence
Assumptions - 
Pre-condition: Line object is created and words is set
Post-condition: Array of strings of words is returned
*/
string* Line::parseWords()
{
	string* words = new string[wordCount];

	int wordStart = 0;
	int wordsCounter = 0;

	for ( int i = 0; i < charCount; i++ )
	{
		if (isalpha(str[i]))
		{
		}
		else
		{
			int wordLength = i - wordStart;
			if (wordLength > 0)
			{
				words[wordsCounter] = str.substr(wordStart,wordLength);
				wordsCounter++;
			}
			wordStart = i + 1;
		}
	}
	return words;
}
/*
Purpose: Return the array of characters for the Line
Assumptions - 
Pre-condition: Line object is createdand character count is set
Post-condition: Array of characters is returned
*/
char* Line::parseChar()
{
	char* characts = new char[getCharCt()];
	for ( int i = 0; i < getCharCt(); i++ )
	{
		characts[i] = str[i];
	}
	return characts;
}
/*
Purpose: Returns the array of characters given a string
Assumptions - 
Pre-condition: String is given and object is created
Post-condition: Array of characters is returned for that string
*/
char* Line::parseChar(string* arrString) 
{
	int stringNum = 0;
	int sizeOfarr = sizeof(arrString) / sizeof(arrString[0]); 
	int* numChar; 

	for ( int i = 0; i < sizeOfarr; i++ )
	{
		string characTs = arrString[i];
		numChar[i] = sizeof(characTs) / sizeof(characTs[0]);		
	}
	int totalChar = 0;

	for ( int j = 0; j < sizeOfarr; j++ )
	{
		totalChar += numChar[j]; 
	}
		 
	char* charactArr = new char[totalChar]; 
	string copyString; 
	int key = 0;

	for ( int k = 0; k < sizeOfarr; k++ )
	{
		copyString = arrString[k];
		for ( int f = key; f < numChar[k]+key; f++ )
		{
			charactArr[f] = copyString[f]; 
			key = numChar[k];
		}
	}

	return charactArr;
}