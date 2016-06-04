/*
Edward Chen
Source file for Document Class
Overview of Document Class: The overarching class that contains 
all of the information regarding the document such as the number of words, 
characters, sentences, and more. 
Functions in this file:
void setLoc(string theLoc) -- Sets the location of the document
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

#include "Document.h"
#include <iostream>
#include "Line.h"
#include "Node.h"
#include "Stack.h"
#include "Metrics.h"
#include <string>
#include <fstream>
using namespace std; 

/*
Purpose: To set the number of sentences in the document
Assumptions - 
Pre-condition: Document object is created
Post-condition: Number of sentences is set
*/
void Document::setLineCt(int num)
{
	lineCount = num; 
}
/*
Purpose: To set the word count in the document
Assumptions - 
Pre-condition: Document object is created
Post-condition: Word count is set
*/
void Document::setWordCt(int count)
{
	wordCount = count; 
}
/*
Purpose: To return the number of sentences in the document
Assumptions - 
Pre-condition: There is a line count set
Post-condition: Line count is returned to user
*/
int Document::getLineCt()
{
	return lineCount; 
}
/*
Purpose: To get the word count of the document
Assumptions - 
Pre-condition: There is a word count set
Post-condition: Word count is returned to user
*/
int Document::getdWordCt()
{
	int num = 0;

	for (int i = 0; i < getLineCt(); i++)
	{
		num += arr[i].getWordCt();
	}
	wordCount = num; 
	
	return wordCount;
}
/*
Purpose: To set the name of the document
Assumptions - 
Pre-condition: Document object is created
Post-condition: Name of document is set
*/
void Document::setName(string namo)
{
	name = namo;
}
/*
Purpose: To get the name of the document returned
Assumptions - 
Pre-condition: Document object is set and name is set
Post-condition: Document name is returned
*/
string Document::getName()
{
	return name;
}
/*
Purpose: Constructor to initialize Document object
Assumptions:
Pre-condition: Name is inputted
Post-condition: Name and id are set
*/
Document::Document(string theName)
{
	name = theName;
	id = rand();
}
/*
Purpose: Constructor to initialize name and id of document
Assumptions - 
Pre-condition: Name and id are chosen
Post-condition: Name and id are initialized
*/
Document::Document(string getName, int num)
{
	name = getName;
	id = num;
}
/*
Purpose: Set location of the file
Assumptions - 
Pre-condition: Location is valid
Post-condition: Location is set
*/
void Document::setLoc(string theLoc)
{
	location = theLoc;
}
/*
Purpose: Return location of file
Assumptions - 
Pre-condition: Object is created and location is set
Post-condition: Location is returned 
*/
string Document::getLoc()
{
	return location;
}
/*
Purpose: Outputs the document to a location given by the string
Assumptions - 
Pre-condition: Document object is created and location is valid
Post-condition: Document is outputted to location
*/
void Document::outputDocument(string nameOf) 
{
	char docChar; 
	ofstream theFile;
	theFile.open(nameOf);
	ifstream theDoc;
	theDoc.open(location);

	if (!theFile.is_open() || !theDoc.is_open())
	{
		cout << "File didn't open." << endl; 
	}

	if (theFile.is_open() && theDoc.is_open())
	{
		while (theDoc.get(docChar))
		{
			theFile << docChar;
		}
	}
}
/*
Purpose: Read in a text file and create a new Line for each sentence read
Assumptions - 
Pre-condition: Location is valid and Document object is created
Post-condition: new Line classes are created for each sentence
*/
void Document::loadDocument(string name)
{
	//ifstream myFile(name);
	ifstream myFile;
	
	myFile.open(name);
	
	if(!myFile.is_open())
	{
		cout << "File didn't open" << endl;
	}
	
	int numOflines = 0; 
	string theLine;
	char words;	
	
	while (myFile.get(words))
	{
		switch (words)
		{
		case '.':
			numOflines++;
			break;
		case '?':
			numOflines++;
			break;
		case '!':
			numOflines++;
			break;
		}
	}

	lineCount = numOflines; 
	setLineCt(numOflines);
	arr = new Line[lineCount];
	myFile.close();
	char theChar;
	ifstream myFile2;
	myFile2.open(name);
	int count = 0;
	int wordCount = 0;
	if (myFile2.is_open())
	{
		for ( id = 0; id < lineCount; id++ )
		{
			count = 0;
			wordCount= 0;
			while (myFile2>> noskipws>>theChar && theChar != '.' && theChar != '!' && theChar != '?') // Changed from || to &&
			{
				if (theChar == ' ')
				{
					wordCount++;
				}
				theLine += theChar;
				count++;
			}			
			wordCount = wordCount + 2;
			theLine += theChar;
			count++;
			myFile2>>theChar;
			arr[id].setWordCt(wordCount);
			arr[id].setStr(theLine);
			arr[id].setCharCt(count);
			theLine.clear();
		}
	}
}
/*
Purpose: Return an array of strings containing the words in the document
Assumptions - 
Pre-condition: Document is open and created
Post-condition: Array of strings of words is returned
*/
string* Document::parseWords()
{
	string* words = new string[getdWordCt()];

	int totalLines = getLineCt();
	int count = 0;
	for ( int i = 0; i < totalLines; i++ )
	{
		int numWords = arr[i].getWordCt();
		string* lineWords = arr[i].parseWords();

		for ( int j = 0; j < numWords; j++ )
		{
			
			int f = 0;
			words[count+j] = lineWords[f];
			f++;
		}
		count = count+numWords;
	}
	return words;
}
/*
Purpose: Return array of characters in the document
Assumptions - 
Pre-condition: Document is created and open
Post-condition: Array of characters is returned
*/
char* Document::parseChar()
{
	int totalChar = 0; 
	for ( int i = 0; i < getLineCt(); i++ )
	{
		totalChar += arr[i].getCharCt();
	}

	char* charactArr = new char[totalChar];
	int z = 0;
	string tempStr;
	int key = 0;

	for ( int i = 0; i < getLineCt(); i++ )
	{
		tempStr += arr[i].getStr(); 
		z = 0;
		for ( int j = key; j < (key + arr[i].getCharCt()); j++ )
		{			
			charactArr[j] = tempStr[z];
			z++;
		}
		key = key + arr[i].getCharCt();
	}

	return charactArr;
}
/* 
Purpose: Constructor for Document object
Assumptions - 
Pre-condition: Need to create Document object
Post-condition: Document object is created
*/
Document::Document()
{
}
/*
Purpose: Destructor for Document object
Assumptions - 
Pre-condition: Document is created
Post-condition: Document is destructed
*/
Document::~Document()
{
}
/*
Purpose: Return the array of lines in document
Assumptions - 
Pre-condition: Array of lines is created
Post-condition: Array is returned
*/
Line* Document::getLines()
{
	return arr;
}
/*
Purpose: Create linked list that contains word count of each sentence as well as end symbol
Assumptions - 
Pre-condition: Document object is created and line count functions work
Post-condition: Linked list is created
*/
void Document::lineLengths()
{
	Node* head = NULL;
	Node* temp = head;

	for ( int i = 0; i < getLineCt(); i++ )
	{
		Node* newLine = NULL;
		int numWords = arr[i].getWordCt();
		int numChar = arr[i].getCharCt();
		newLine->setWordCt(numWords);

		string theLine = arr[i].getStr();
		char symb = theLine[numChar-1];
		newLine->setSymb(symb);

		temp->setNext(newLine);
		temp = newLine;
	}
}
/*
Purpose: Return the number of characters in document
Assumptions - 
Pre-condition: Document object is created 
Post-condition: Number of characters in document is returned
*/
int Document::getdCharCt()
{
	int count = 0;
	int l = getLineCt();

	for ( int i = 0; i < l; i++ )
	{
		int c = arr[i].getCharCt();
		count += c;
	}

	return count;
}
/*
Purpose: To compare 2 different words in 2 documents and say whether same or different
Assumptions - 
Pre-condition: Document objects are created and set
Post-condition: Words are different or same
*/
int Document::reverseCompare(Document doc)
{
	Stack docWords;
	int numWords = getdWordCt();
	string* dWords = parseWords();

	for ( int i = 0; i < getdWordCt(); i++ )
	{
		docWords.Push(dWords[i]);
	}
	
	int docCount = doc.getdWordCt();
	string* ofWords = doc.parseWords();
	int diffCount = 0;
	for ( int i = docCount; i > 0; i-- )
	{
		if (ofWords[i] == docWords.Pop())
		{
			cout << "Same" << endl;
		}
		else
		{
			cout << "Different" << endl;
			diffCount++;
		}
	}
	return diffCount;
}
/*
Purpose: Hash function to return hash key for each word
Assumptions - 
Pre-condition: Document word is ready
Post-condition: Hash key is returned
*/
int Document::hashWord(string v, int m)
{
	int h = 0;
	int a = 127;
	
	for(int i=0; i<v.length(); i++)
	{
		h = (a*h + v[i]) % m;
		
	}
	return h;
}
/*
Purpose: Hash function to return hash keys for characters
Assumptions - 
Pre-condition: Character is available
Post-condition: Hash key is returned
*/
int Document::hashChar(char v, int m)
{
	int h = 0;

	h = v / m;

	return h;
}
/*
Purpose: To create a hash table of the words in the document and sort
Assumptions - 
Pre-condition: Functions within work and Document object is created
Post-condition: Hash table of words is created and sorted
*/
string* Document::createHashWords(int theK, bool top, int* freqWords)
{
	Node* headsp[97];

	for ( int i = 0; i < 97; i++ )
	{
		headsp[i] = NULL;
	}
	string* allWords = parseWords();
	
	int numWords = getdWordCt();
	 
	for ( int i = 0; i < numWords; i++ ) // Creating hash table and inserting words in correct positions
	{
		
		string word = allWords[i];
		 
		int k = hashWord(word,97);
		 
		insertWord(headsp,k,allWords[i]);
	}
	
	for ( int i = 0; i < 97; i++ )
	{
		Node* temp = headsp[i];
		int size = 0;

		while (temp != NULL) // Count size of that one chain
		{
			size++;
			temp = temp->getNext();
		}

		int* countArr = new int[size]; // Create count array of that size
		temp = headsp[i];

		for ( int j = 0; j < size; j++ ) // Setting the count values in the new array
		{
			countArr[j] = temp->getCount();
			temp = temp->getNext();
		}
		
		Metrics<int> theSort;
		theSort.mergeSort(countArr,size); // Merge sorting the frequency array
		// Does print after here
		temp = headsp[i];
		Node* front;
		if (temp != NULL)
		{
			front = temp->getNext();
		}
		//Node* front = temp->getNext();
		Node* headPtr = headsp[i];

		for ( int k = 0; k < size; k++ ) // Swapping the values of each count for the nodes 
		{
			while ( temp != NULL )
			{
				if ( temp->getCount() == countArr[k] ) // Sorting that one chain
				{
					string tempWord = headPtr->getWord();
					int tempCount = headPtr->getCount();
					headPtr->setWord(temp->getWord());
					headPtr->setCount(temp->getCount());
					temp->setWord(tempWord);
					temp->setCount(tempCount);
					headPtr = headPtr->getNext();
					temp = headPtr;
					break;
				}
				temp = temp->getNext();
			}
		}

	} // End of loop


	string* thekWords = new string[theK];
	//int* freqWords = new int[theK];
	if ( top == true )
	{
		for ( int z = 0; z < theK; z++ )
		{
			freqWords[z] = 1;
		}
	}
	else
	{
		for ( int w = 0; w < theK; w++ )
		{
			freqWords[w] = 100;
		}
	}
	bool greater = false;
	bool done = false;
	bool lesser = false;
	// Finding top/bottom k words and returning string of them
	if (top == true)
	{
		for ( int i = 0; i < 97; i++ ) // Loop through heads of hash table
		{
			Node* temp = headsp[i];

			while (temp != NULL) // Loop through each chain
			{
				for ( int q = 0; q < theK; q++ ) // Loop through frequency array
				{
					if (temp->getCount() > freqWords[q])
						greater = true;
					if (temp->getCount() > freqWords[q] && freqWords[q] == 1)
					{
						freqWords[q] = temp->getCount();
						thekWords[q] = temp->getWord();
						done = true;
						break;
					}
				} // After for loop
				if (greater == true && done == false) // If the word count is greater than one of the frequency and it's not equal to 1, then store that replace that count with the min
				{
					int min = 1000;
					for ( int i = 0; i < theK; i++ )
					{
						if (freqWords[i] < min)
							min = i;
					}
					freqWords[min] = temp->getCount();
					thekWords[min] = temp->getWord();
					greater = false;
					done = false;
				}
				greater = false;
				done = false;
				temp = temp->getNext();
			} // End of while temp
		}
	} // End of finding top k words
	else // Finding bottom k words
	{
		for ( int i = 0; i < 97; i++ )
		{
			Node* temp = headsp[i];

			while (temp)
			{
				for ( int y = 0; y < theK; y++ )
				{
					if (temp->getCount() < freqWords[y])
						lesser = true;
					if (temp->getCount() < freqWords[y] && freqWords[y] == 100)
					{
						freqWords[y] = temp->getCount();
						thekWords[y] = temp->getWord();
						done = true;
						break;
					}
				} // After for loop
				if (lesser == true && done == false)
				{
					int max = 0;
					for ( int a = 0; a < theK; a++ )
					{
						if (freqWords[a] > max)
							max = a;
					}
					freqWords[max] = temp->getCount();
					thekWords[max] = temp->getWord();
					lesser = false;
					done = false;
				}
				lesser = false;
				done = false;
				temp = temp->getNext();
			}
		}
	}
	return thekWords;
}
/*
Purpose: To create a hash table of characters in the document
Assumptions - 
Pre-condition: Funcitons within work and Document object is created
Post-condition: Hash table of characters is created and sorted
*/
void Document::createHashChars()
{
	Node* headsp[32];

	char* allChars = parseChar();
	int numChar = getdCharCt();

	for ( int i = 0; i < numChar; i++ )
	{
		int k = hashChar(allChars[i],32);
		insertChar(headsp,k,allChars[i]);
	}

	 // From here 

	for ( int i = 0; i < 32; i++ )
	{
		Node* temp = headsp[i];
		int size = 0;

		while (temp != NULL)
		{
			size++;
			temp = temp->getNext();
		}

		int* countArr = new int[size];
		temp = headsp[i];

		for ( int j = 0; j < size; j++ ) // Setting the count values in the new array
		{
			countArr[j] = temp->getCount();
			temp = temp->getNext();
		}

		Metrics<int> theSort;
		theSort.mergeSort(countArr,size);

		temp = headsp[i];
		Node* front = temp->getNext();
		Node* headPtr = headsp[i];

		for ( int k = 0; k < size; k++ ) // Swapping the values of each count for the nodes 
		{
			while ( temp != NULL )
			{
				if ( temp->getCount() == countArr[i] )
				{
					char tempChar = headPtr->getChar();
					int tempCount = headPtr->getCount();
					headPtr->setChar(temp->getChar());
					headPtr->setCount(temp->getCount());
					temp->setChar(tempChar);
					temp->setCount(tempCount);
					headPtr = headPtr->getNext();
					temp = headPtr->getNext();
					break;
				}
				temp = temp->getNext();
			}
		}

	}
}
/*
Purpose: Insert function to insert nodes for linear probing in the hash table of words
Assumptions - 
Pre-condition: Hash table is created and hash key is available
Post-condition: Node with the key is placed in the hash table at correct spot
*/
void Document::insertWord(Node** theArr, int Thash, string key)
{
	if (theArr[Thash] == NULL)
	{
		theArr[Thash] = new Node;
		theArr[Thash]->setWord(key);
		theArr[Thash]->setNext(NULL);
		theArr[Thash]->setCount(0);
	}
	else
	{
		bool found = false;
		Node* temp = theArr[Thash];
		while (temp != NULL)
		{
			if (temp->getWord() == key)
			{
				found = true;
				int c = temp->getCount();
				c++;
				temp->setCount(c);
				break;
			}
			temp = temp->getNext();
		}
		if (found == false)
		{
			Node* temp = new Node;
			temp->setWord(key);
			temp->setNext(theArr[Thash]);
			temp->setCount(0);
			theArr[Thash] = temp;
		}
	}
}
/*
Purpose: Insert function to insert character node in hash table
Assumptions - 
Pre-condition: Hash table is created and hash key is available
Post-condition: Node with the data is inserted in the correct spot
*/
void Document::insertChar(Node** theHash, int tHash, char key)
{
	if (theHash[tHash] == NULL)
	{
		theHash[tHash] = new Node;
		theHash[tHash]->setChar(key);
		theHash[tHash]->setNext(NULL);
	}
	else
	{
		bool found = false;
		Node* temp = theHash[tHash];
		while (temp)
		{
			if (temp->getChar() == key)
			{
				found = true;
				int c = temp->getCount();
				c++;
				temp->setCount(c);
				break;
			}
			temp = temp->getNext();
		}
		if ( found == false )
		{
			Node* temp = new Node;
			temp->setChar(key);
			temp->setNext(theHash[tHash]);
			theHash[tHash] = temp;
		}
	}
}
/*
Purpose: To encrypt and decrypt a string of words
Assumptions - 
Pre-condition: String is available and converted to character array and offset is given
Post-condition: Message is encrypted/decrypted 
*/
void Document::caesarCipher(char* theArr, int numChar, int offSet)
{
	for ( int i = 0; i < numChar; i++ )
	{
		if (isalpha(theArr[i]))
		{
			char base = islower(theArr[i])? 'a' : 'A';
			theArr[i] = base + (theArr[i] - base + offSet) % 26;
		}
		else
		{
			theArr[i] = theArr[i];
		}
	}
}
/*
Purpose: To encrypt the message with a vigenere cipher given a keyword 
Assumptions - 
Pre-condition: Keyword is given and string is in character array
Post-condition: Message is encrypted through the vigenere cipher
*/
void Document::vigenereEncrypt(char* theArr, int numChar, string keyWord)
{
	int j = 0;

	for ( int i = 0; i < numChar; i++ )
	{
		int offSet = keyWord[j] - 97;

		if (isalpha(theArr[i]))
		{
			char base = islower(theArr[i])? 'a' : 'A';
			theArr[i] = base + ((theArr[i] - base + offSet) % 26);
			
			j = ( j + 1 ) % keyWord.length();
		}
		else
		{
			theArr[i] = theArr[i];
		}
	}	
}
/*
Purpose: To decrypt the message with a vigenere cipher given the original keyword
Assumptions - 
Pre-condition: String is converted to character array and keyword is given
Post-condition: Message is decrypted to original form
*/
void Document::vigenereDecrypt(char* theArr, int numChar, string keyWord)
{
	int j = 0;

	for ( int i = 0; i < numChar; i++ )
	{
		int offSet = keyWord[j] - 97;
		offSet = 26 - offSet;

		if (isalpha(theArr[i]))
		{
			char base = islower(theArr[i])? 'a' : 'A';
			theArr[i] = base + ((theArr[i] - base + offSet) % 26);
			
			j = ( j + 1 ) % keyWord.length();
		}
		else
		{
			theArr[i] = theArr[i];
		}
	}
}




