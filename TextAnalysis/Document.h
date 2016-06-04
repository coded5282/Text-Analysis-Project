/*
Edward Chen
Header File for Document Class
Overview of Document Class: The overarching class that contains 
all of the information regarding the document such as the number of words, 
characters, sentences, and more. 
Functions in this file:
void setLoc(string theLoc) -- Sets the location of document
string getLoc() -- Returns location of document
void setLineCt(int num) -- Sets the sentence count of document
void setWordCt(int count) -- Sets the word count of document
int getLineCt() -- Returns the sentence count of document
int getdWordCt() -- Returns word count of document
int getdCharCt() -- Returns the character count of document
void setName(string namo) -- Sets the name of the document
string getName() -- Returns the name of the document
Document(string theName) -- Constructor for the Document class
Document(string getName, int num) -- Constructor for Document class 
Document() -- Constructor for Document class
~Document() -- Destructor for Document class
void outputDocument(string nameOf) -- Outputs document to different location
void loadDocument(string name) -- Loads document to a name location
string* parseWords() -- Returns an array of strings containing the words of the Document
char* parseChar() -- Returns an array of characters containing the characters of the Document
void lineLengths() -- Creates a linked list of lines and stores the end symbol and word count
void reverseCompare(Document doc) -- Checks if words between 2 documents are same or different
int hashWord(char *v, int m) -- Hash function for each word
int hashChar(char v, int m) -- Hash function for each character
void createHashWords() -- Creates hash table of words and sorts them
void createHashChars() -- Creates hash table of characters and sorts them
void insertWord(Node** theArr, int Thash, string key) -- Inserts word into hash table
void insertChar(Node** theHash, int tHash, char key) -- Inserts character into hash table
void caesarCipher(char* theArr, int numChar, int offSet) -- Encryption and decryption with caesar cipher
void vigenereEncrypt(char* theArr, int numChar, string keyWord) -- Encryption with vigenere cipher
void vigenereDecrypt(char* theArr, int numChar, string keyWord) -- Decryption with veigenere cipher
*/

#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
#include <string>
#include "Line.h"
#include "Node.h"
using namespace std;


class Document
{
private:
	int lineCount;
	int wordCount; 
	string name;
	Line *arr;   
	string location;
public:
	void setLoc(string theLoc);
	string getLoc();
	int id;
	void setLineCt(int num);
	void setWordCt(int count);
	int getLineCt();
	int getdWordCt();
	int getdCharCt();
	void setName(string namo);
	string getName();
	Document(string theName);
	Document(string getName, int num);
	Document();
	~Document(); 
	Line* getLines();
	void outputDocument(string nameOf);
	void loadDocument(string name);
	string* parseWords();
	char* parseChar();
	void lineLengths(); 
	int reverseCompare(Document doc); 
	int hashWord(string v, int m); 
	int hashChar(char v, int m);
	string* createHashWords(int theK, bool top, int* freqWords); 
	void createHashChars();
	void insertWord(Node** theArr, int Thash, string key);
	void insertChar(Node** theHash, int tHash, char key);
	void caesarCipher(char* theArr, int numChar, int offSet);
	void vigenereEncrypt(char* theArr, int numChar, string keyWord);
	void vigenereDecrypt(char* theArr, int numChar, string keyWord);
};

#endif