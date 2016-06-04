// Edward Chen
// CMPSC 122 Section 001
// Text Analysis Project
// May 6 2014

#include "Document.h"
#include "Line.h"
#include "Plot.h"
#include "Metrics.h"
#include "Node.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;


int main()
{
	Document* myDocs = new Document[10];
	int docCount = 0;
	bool menu = true;
	int userInput = 0;
	while ( menu == true )
	{
		//int userInput = 0; 
		userInput = 0;
		cout << "----------------MENU----------------" << endl << endl;
		cout << " --------(1) LOAD DOCUMENT (1)--------- " << endl << endl;
		cout << "--------(2) OUTPUT DOCUMENT (2)--------" << endl << endl;
		cout << " --------(3) ANALYZE DOCUMENT (3)-------- " << endl << endl;
		cout << " ------(4) COMPARE TWO DOCUMENTS (4)------ " << endl << endl; 
		cout << " ----------(5)  ENCRYPT  (5)---------- " << endl << endl; 
		cout << "-----------(6)  DECRYPT  (6)----------" << endl << endl;
		cout << "-------------(7) EXIT (7)--------------" << endl << endl; 

		cin >> userInput;
		string docName;
		string outputLoc;

		switch (userInput)
		{
		case 1: // Load Document
			{
				string inputLoc;
				cout << "Please input the document name:" << endl;
				cin >> docName;
				myDocs[docCount].setName(docName);
				myDocs[docCount].id = docCount;
				cout << "Input Location: " << endl;
				cin >> inputLoc; 
				myDocs[docCount].setLoc(inputLoc);
				myDocs[docCount].loadDocument(inputLoc);
				docCount++;
				break;
			}
		case 2: // Output Document
			{
				cout << "Please specify the name of the output document:" << endl;
				cin >> docName;
				cout << "Please specify the output location:" << endl;
				cin >> outputLoc;
				myDocs[docCount].setName(docName);
				myDocs[docCount].id = docCount;
				myDocs[docCount].setLoc(outputLoc);
				docCount = docCount - 1;
				myDocs[docCount].outputDocument(outputLoc);
				docCount = docCount + 2;
				break;
			}
		case 3: // Analyze Document
			{
				bool stay = true;
				while (stay == true)
				{
					cout << "------ Analyze Document ------" << endl;
					cout << "---(1) Print Character Count (1)----" << endl;
					cout << "---(2) Print Word Count (2)----" << endl;
					cout << "---(3) Print Sentence Count (3)----" << endl;
					cout << "---(4) Character Histogram (4)----" << endl;
					cout << "---(5) Character Histogram Offset (5)---" << endl;
					cout << "---------(6) Top k Words (6)----------" << endl;
					cout << "--------(7) Bottom k Words (7)--------" << endl;
					cout << "----------(8) Word Trace K (8)---------" << endl;
					cout << "----------(9) Back (9)----------" << endl;

					int charFreq[26];
					int input = 0; // Changed to equal zero 
					cin >> input; 
					switch (input)
					{
					case 1: // Print character count
						{
							cout << "Document name: " << endl;
							cin >> docName;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							cout << myDocs[q].getdCharCt() << endl;
							break;
						}
					case 2: // Print word count
						{
							cout << "Document name: " << endl;
							cin >> docName;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							cout << myDocs[q].getdWordCt() << endl;
							break;
						}
					case 3: // Print sentence count
						{
							cout << "Document name: " << endl;
							cin >> docName;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							cout << myDocs[q].getLineCt() << endl;
							break;
						}
					case 4: // Character Histogram
						{
							cout << "Document name: " << endl;
							cin >> docName;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							char* tcharArr = myDocs[q].parseChar();
							Metrics<char> charSort;
							charSort.mergeSort(tcharArr,myDocs[q].getdCharCt());
							//int charFreq[26];
							int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,theQ,r,s,t,u,v,w,x,y,z;
							a=b=c=d=e=f=g=h=i=j=k=l=m=n=o=p=theQ=r=s=t=u=v=w=x=y=z = 0;
							for ( int i = 0; i < myDocs[q].getdCharCt(); i++ )
							{
								switch (tcharArr[i])
								{
								case 'a':
									a++;
									charFreq[0] = a;
									break;
								case 'b':
									b++;
									charFreq[1] = b;
									break;
								case 'c':
									c++;
									charFreq[2] = c;
									break;
								case 'd':
									d++;
									charFreq[3] = d;
									break;
								case 'e':
									e++;
									charFreq[4] = e;
									break;
								case 'f':
									f++;
									charFreq[5] = f;
									break;
								case 'g':
									g++;
									charFreq[6] = g;
									break;
								case 'h':
									h++;
									charFreq[7] = h;
									break;
								case 'i':
									i++;
									charFreq[8] = i;
									break;
								case 'j':
									j++;
									charFreq[9] = j;
									break;
								case 'k':
									k++;
									charFreq[10] = k;
									break;
								case 'l':
									l++;
									charFreq[11] = l;
									break;
								case 'm':
									m++;
									charFreq[12] = m;
									break;
								case 'n':
									n++;
									charFreq[13] = n;
									break;
								case 'o':
									o++;
									charFreq[14] = o;
									break;
								case 'p':
									p++;
									charFreq[15] = p;
									break;
								case 'q':
									theQ++;
									charFreq[16] = theQ;
									break;
								case 'r':
									r++;
									charFreq[17] = r;
									break;
								case 's':
									s++;
									charFreq[18] = s;
									break;
								case 't':
									t++;
									charFreq[19] = t;
									break;
								case 'u':
									u++;
									charFreq[20] = u;
									break;
								case 'v':
									v++;
									charFreq[21] = v;
									break;
								case 'w':
									w++;
									charFreq[22] = w;
									break;
								case 'x':
									x++;
									charFreq[23] = x;
									break;
								case 'y':
									y++;
									charFreq[24] = y;
									break;
								case 'z':
									z++;
									charFreq[25] = z;
									break;
								} // End of switch
							} // End of loop
							Plot histPlot;
							histPlot.histogram(charFreq,26);
							break;
						}
					case 5: // Character Histogram Offset
						{
							int offSet = 0;
							cout << "Offset: " << endl;
							cin >> offSet;
							cout << "Document name: " << endl;
							cin >> docName;
							int q = 0;
							while ( myDocs[q].getName() != docName )
							{
								q++;
							}
							offSet = offSet % 26;
							for ( int i = 0; i < 26; i++ )
							{
								int temp = charFreq[i];
								int newShift = (i + offSet) % 26;
								charFreq[i] = charFreq[newShift];
								charFreq[newShift] = temp;
							}
							Plot histPlot;
							histPlot.histogram(charFreq,26);
							break;
						}
					case 6: // Top k Words
						{
							int k = 0;
							int j = 0;
							int userID = 0;
							cout << "------(1) Hash Method (1)-------" << endl;
							cout << "------(2) Sort Method (2)-------" << endl;
							cin >> userID;

							switch (userID)
							{
							case 1: // Hash Method Top K Words
								{
									clock_t d1,d2;
									cout << "K: " << endl;
									cin >> k;
									cout << "Document name: " << endl;
									cin >> docName;
									d1 = clock();
									int q = 0;
									while (myDocs[q].getName() != docName)
									{
										q++;
									}
									int* theFreqWords = new int[k];
									for ( int i = 0; i < k; i++ )
									{
										theFreqWords[i] = 0;
									}
									string* topWords;
									topWords = myDocs[q].createHashWords(k,true,theFreqWords); // Fix 
									cout << "Top " << k << " words: " << endl;
									for ( int d = 0; d < k; d++ )
									{
										cout << topWords[d] << endl;
									}
									Plot wordFreqHist;
									wordFreqHist.histogram(theFreqWords,k);
									d2 = clock();
									cout << "Time:  " << ((double)(d2-d1))/(CLOCKS_PER_SEC)<<endl;
									break;
								}
							case 2: // Sort Method top k words
								{
									cout << "K: " << endl;
									cin >> j;
									cout << "Document name: " << endl;
									cin >> docName;
									clock_t d1,d2;
									d1 = clock();
									int q = 0;
									while (myDocs[q].getName() != docName)
									{
										q++;
									}
									
									string* allWords;
									allWords = myDocs[q].parseWords();
									Metrics<string> wordSorting;
									
									wordSorting.mergeSort(allWords,myDocs[q].getdWordCt());
									
									int* freqWords = new int[j];
									string* topWords = new string[j];
									for ( int w = 0; w < j; w++ )
									{
										freqWords[w] = 1;
									}
									bool greater = false;
									bool done = false;
									for ( int t = 0; t < myDocs[q].getdWordCt(); t++ )
									{
										int count = 0;
										int b = t;

										for ( int same = t+1; same < myDocs[q].getdWordCt(); same++ )
										{
											if (allWords[same] == allWords[same-1])
											{
												count++;
											}
											else
											{
												break; 
											}
										}
										
										for ( int s = 0; s < j; s++ )
										{
											if (count > freqWords[s])
												greater = true;
											if (greater == true && freqWords[s] == 1)
											{
												freqWords[s] = count;
												topWords[s] = allWords[t];
												done = true;
												break;
											}
										}
										if (greater == true && done == false)
										{
											int min = 1000;
											for ( int a = 0; a < j; a++ )
											{
												if (freqWords[a] < min)
													min = a;
											}
											freqWords[min] = count;
											topWords[min] = allWords[t];
										}
									} // End of big for loop
									cout << "Top " << j << " words: " << endl;
									for ( int theTop = 0; theTop < j; theTop++ )
									{
										cout << topWords[theTop] << endl;
									}
									Plot topwordSort;
									topwordSort.histogram(freqWords,j);
									d2 = clock();
									cout << "Time:  " << ((double)(d2-d1))/(CLOCKS_PER_SEC)<<endl;
									break;
								} // End of case
							}
							break;
						}
					case 7: // Bottom k Words
						{
							int userID2 = 0;
							cout << "------(1) Hash Method (1)------" << endl;
							cout << "------(2) Sort Method (2)------" << endl;
							cin >> userID2;

							switch (userID2)
							{
							case 1: // Bottom k words hash method
								{
									int k = 0;
									clock_t d1,d2;
									cout << "K: " << endl;
									cin >> k;
									cout << "Document name: " << endl;
									cin >> docName;
									d1 = clock();
									int q = 0;
									while (myDocs[q].getName() != docName)
									{
										q++;
									}
									int* theFreqWords = new int[k];
									for ( int i = 0; i < k; i++ )
									{
										theFreqWords[i] = 0;
									}
									string* botWords;
									botWords = myDocs[q].createHashWords(k,false,theFreqWords);
									cout << "Bottom " << k << " words: " << endl;
									for ( int d = 0; d < k; d++ )
									{
										cout << botWords[d] << endl;
									}
									Plot wordFreqHist;
									wordFreqHist.histogram(theFreqWords,k);
									d2 = clock();
									cout << "Time:  " << ((double)(d2-d1))/(CLOCKS_PER_SEC)<<endl;		
									break;
								}

							case 2:
								{
									int numBot = 0;
									cout << "K: " << endl;
									cin >> numBot;
									cout << "Document name: " << endl;
									cin >> docName;
									clock_t d1,d2;
									d1 = clock();
									int q = 0;
									while (myDocs[q].getName() != docName)
									{
										q++;
									}
									string* allWords;
									allWords = myDocs[q].parseWords();
									Metrics<string> wordSorting;
									wordSorting.mergeSort(allWords,myDocs[q].getdWordCt());
									int* freqWords = new int[numBot];
									string* botWords = new string[numBot];
									for ( int w = 0; w < numBot; w++ )
									{
										freqWords[w] = 100;
									}
									bool lesser = false;
									bool done = false;
									for ( int t = 0; t < myDocs[q].getdWordCt(); t++ )
									{
										int count = 0;
										int b = t;

										for ( int same = t+1; same < myDocs[q].getdWordCt(); same++ )
										{
											if (allWords[same] == allWords[same-1])
											{
												count++;
											}
											else
											{
												break; 
											}
										}
										
										for ( int s = 0; s < numBot; s++ )
										{
											if (count < freqWords[s])
												lesser = true;
											if (lesser == true && freqWords[s] == 100)
											{
												freqWords[s] = count;
												botWords[s] = allWords[t];
												done = true;
												break;
											}
										}
										if (lesser == true && done == false)
										{
											int max = 0;
											for ( int a = 0; a < numBot; a++ )
											{
												if (freqWords[a] > max)
													max = a;
											}
											freqWords[max] = count;
											botWords[max] = allWords[t];
										}
									} // End of big for loop
									cout << "Bottom " << numBot << " words: " << endl;
									for ( int theBot = 0; theBot < numBot; theBot++ )
									{
										cout << botWords[theBot] << endl;
									}
									Plot topwordSort;
									topwordSort.histogram(freqWords,numBot);
									d2 = clock();
									cout << "Time:  " << ((double)(d2-d1))/(CLOCKS_PER_SEC)<<endl;
									break;
								}
							}
							break;
						}
					case 8: // Word Trace K
						{
							int numWords = 0;
							string docName;
							cout << "K: " << endl;
							cin >> numWords;
							cout << "Document Name: " << endl;
							cin >> docName;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							string* theWords = new string[numWords];
							double* xArr = new double[numWords];
							double* yArr = new double[numWords];
							for ( int te = 0; te < numWords; te++ )
							{
								xArr[te] = 1;
								yArr[te] = 1;
							}
							Line* allLines;
							allLines = myDocs[q].getLines();
							for ( int i = 0; i < numWords; i++ )
							{
								string userWord;
								cout << "Word: " << endl;
								cin >> userWord;
								theWords[i] = userWord;
							}
							for ( int j = 0; j < myDocs[q].getLineCt(); j++ ) // Loop through all lines to find where last seen
							{
								string* wordsinLine;
								wordsinLine = allLines[j].parseWords(); // Stores the words of that one line into wordinLine
								
								for ( int f = 0; f < numWords; f++ ) // Loops through array of words to find
								{
									for ( int p = 0; p < allLines[j].getWordCt()-1; p++ ) // Loops through that one line's words
									{
										if (theWords[f] == wordsinLine[p]) // if the words is equal to one of them in the line
										{
											yArr[f] = j + 1;
											break;
										}
									}
								}
							} // End of loop to find where last seen
							bool* updated = new bool[numWords];
							for ( int i = 0; i < numWords; i++ )
							{
								updated[i] = false;
							}
							for ( int y = 0; y < myDocs[q].getLineCt(); y++ ) // Loop through to find where first seen
							{
								string* thewordsinLine;
								thewordsinLine = allLines[y].parseWords(); // Sets thewordsinLine equal to all words in that one line
								for ( int u = 0; u < numWords; u++ ) // Loop through number of words to find
								{
									for ( int e = 0; e < allLines[y].getWordCt(); e++ ) // Loop through all words in that line
									{
										if (theWords[u] == thewordsinLine[e] && updated[u] == false)
										{
											xArr[u] = y + 1;
											updated[u] = true;
										}
									}
								}
							} // End of loop to find where first seen
							Plot toTrace;
							toTrace.plot2D(xArr,yArr,numWords);
							break;
						}
					case 9:
						{
							stay = false;
							break;
						}
					}
				}
				break;
			}
		case 4: // COMPARE TWO DOCUMENTS
			{
				bool here = true;
				while ( here == true )
				{
					int theChoice = 0;
					cout << "--------(1) Input Document Names (1)--------" << endl;
					cout << "--------(2) Clear Document Names (2)--------" << endl;
					cout << "----------(3) Compare Different (3)---------" << endl;
					cout << "------------------(4) Back (4)----------------" << endl;
					cin >> theChoice;
					string tdocOne;
					string tdocTwo;
					switch (theChoice)
					{
					case 1: // Input Document Names
						{
							cout << "Document One Name: " << endl;
							cin >> tdocOne;
							cout << "Document Two Name: " << endl;
							cin >> tdocTwo;
							break;
						}
					case 2: // Clear Document Names
						{
							tdocOne.clear();
							tdocTwo.clear();							
							break;
						}
					case 3: // Compare Different and count the number of words different
						{
							int first = 0;
							int second = 0;
							while (myDocs[first].getName() != tdocOne)
							{
								first++;
							}
							while (myDocs[second].getName() != tdocTwo)
							{
								second++;
							}
							int countDiff = 0;
							countDiff = myDocs[first].reverseCompare(myDocs[second]);	
							cout << countDiff << " words are different" << endl;
							break;	
						}
					case 4: // Go Back
						{
							here = false;
							break;
						}
					}
				}
				break;
			}
		case 5: // ENCRYPT
			{
				bool present = true;
				while ( present == true )
				{
					int theChoice = 0;
					cout << "----------(1) Caesar Cipher (1)---------" << endl; 
					cout << "----------(2) Vigenere Cipher (2)--------" << endl;
					cout << "---------------(3) Back (3)---------------" << endl;
					cin >> theChoice;

					switch (theChoice)
					{
					case 1: // Caesar Cipher
						{
							int offSet = 0;
							string docName;
							cout << "Offset: " << endl;
							cin >> offSet;
							cout << "Document Name: " << endl;
							cin >> docName;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							char *docChar;
							docChar = myDocs[q].parseChar();
							myDocs[q].caesarCipher(docChar,myDocs[q].getdCharCt(),offSet);
							break;
						}
					case 2: // Vigenere Cipher
						{
							string keyWord;
							string docName;
							cout << "Keyword: " << endl;
							cin >> keyWord;
							cout << "Document Name: " << endl;
							cin >> docName;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							char *docChar;
							docChar = myDocs[q].parseChar();
							myDocs[q].vigenereEncrypt(docChar,myDocs[q].getdCharCt(),keyWord);
							break;
						}
					case 3:
						{
							present = false;
							break;
						}
					}
				}
				break;
			}
		case 6: // DECRYPT
			{
				bool available = true;
				while ( available == true )
				{
					int theChoice = 0;
					cout << "----------(1) Caesar Cipher (1)-----------" << endl;
					cout << "----------(2) Vigenere Cipher (2)----------" << endl;
					cout << "----------------(3) Back (3)--------------" << endl;
					cin >> theChoice;

					switch (theChoice)
					{
					case 1: // Caesar Cipher
						{
							int offSet = 0;
							string docName;
							cout << "Offset: " << endl;
							cin >> offSet;
							cout << "Document Name:  " << endl;
							cin >> docName;
							offSet = 26 - offSet;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							char* docChar;
							docChar = myDocs[q].parseChar();
							myDocs[q].caesarCipher(docChar,myDocs[q].getdCharCt(),offSet);
							break;
						}
					case 2: // Vigenere Cipher
						{
							string keyWord;
							string docName;
							cout << "Keyword: " << endl;
							cin >> keyWord;
							cout << "Document Name: " << endl;
							cin >> docName;
							int q = 0;
							while (myDocs[q].getName() != docName)
							{
								q++;
							}
							char *docChar;
							docChar = myDocs[q].parseChar();
							myDocs[q].vigenereDecrypt(docChar,myDocs[q].getdCharCt(),keyWord);
							break;
						}
					case 3:
						{
							available = false;
							break;
						}
					}
				}
				break;
			}
		case 7:
			{
				cout << "Thanks and have a good day!" << endl; 
				return 0;
				break;
			}
		default:
			{
				break; 
			}
		}
	}

	cout << "Thanks and have a good day!" << endl; 

	return 0; 
}