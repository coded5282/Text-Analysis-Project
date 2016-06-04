/*
Edward Chen
Header file for Metrics class
Overview of Metrics Class: Primary class used for sorting data
Functions:
Metrics() -- Constructor for Metrics class
~Metrics() -- Destructor for Metrics class
void selectionSort(T *arr, int n) -- Selection sort for a given array and size of data
void insertionSort(T *arr, int n) -- Insertion sort for a given array and size of data
void merge(T *a, int numA, T *b, int numB, T *c) -- Merge function to be used in merge sort function. This is to combine the data in an orderly fashion.
void mergeSort(T *arr, int n) -- Main merge sort function that contains the recursive algorithm of merging and sorting for data.
*/

#ifndef METRICS_H
#define METRICS_H
#include <iostream>
using namespace std;

template <class T>
class Metrics
{
private:
	int id;
public:
	Metrics();
	~Metrics();
	void selectionSort(T *arr, int n);
	void insertionSort(T *arr, int n);
	void merge(T *a, int numA, T *b, int numB, T *c);
	void mergeSort(T *arr, int n);
};



#endif