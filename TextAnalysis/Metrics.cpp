/*
Edward Chen
Source file for Metrics class
Overview of Metrics Class: Primary class used for sorting data
Functions:
Metrics() -- Constructor for Metrics class
~Metrics() -- Destructor for Metrics class
void selectionSort(T *arr, int n) -- Selection sort for a given array and size of data
void insertionSort(T *arr, int n) -- Insertion sort for a given array and size of data
void merge(T *a, int numA, T *b, int numB, T *c) -- Merge function to be used in merge sort function. This is to combine the data in an orderly fashion.
void mergeSort(T *arr, int n) -- Main merge sort function that contains the recursive algorithm of merging and sorting for data.
*/

#include <iostream>
#include <string>
#include "Metrics.h"
using namespace std;

/*
Purpose: Constructor for Metrics class with template
Assumptions - 
Pre-condition: Creating Metrics object
Post-condition: Metrics object is created while instantiating template
*/
template <class T>
Metrics<T>::Metrics()
{
}
/*
Purpose: Destructor for Metrics class with template
Assumptions - 
Pre-condition: Metrics object is created
Post-condition: Instantiation is destructed
*/
template <class T>
Metrics<T>::~Metrics()
{

}
/*
Purpose: To use selection sort on a given array of data and size
Assumptions - 
Pre-condition: Array of data and size are valid
Post-condition: Array of data is sorted
*/
template <class T>
void Metrics<T>::selectionSort(T *arr, int n)
{
	for ( int i = 0; i < n; i++ )
	{
		int minIndex = i;

		for ( int j = i; j < n; j++ )
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}

		T temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}
/*
Purpose: To use insertion sort on a given array of data and size
Assumptions - 
Pre-condition: Array of data and size are valid
Post-condition: Array of data is sorted and size is same
*/
template <class T>
void Metrics<T>::insertionSort(T *arr, int n)
{
	for ( int i = 1; i < n; i++ )
	{
		int j = i;

		while ( j > 0 && arr[j] < arr[j-1] )
		{
			T temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
}
/*
Purpose: To merge 2 arrays together in order
Assumptions - 
Pre-condition: Arrays of data and size are valid
Post-condition: Array values and size are same, and are combined in order
*/
template <class T>
void Metrics<T>::merge(T *a, int numA, T *b, int numB, T *c)
{
	int i, j, k;
	i = j = k = 0;

	while ( i < numA && j < numB )
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}
		else
		{
			c[k] = b[j];
			j++;
			k++;
		}
	}

	while ( i < numA )
	{
		c[k] = a[i];
		i++;
		k++;
	}

	while ( j < numB )
	{
		c[k] = b[j];
		j++;
		k++;
	}
}
/*
Purpose: Main merge sort function to use merge sort on a given array of data and size
Assumptions - 
Pre-condition: Array of data is given and size is valid
Post-condition: Values in data is same, but sorted and size is same
*/
template <class T>
void Metrics<T>::mergeSort(T *arr, int n)
{
	if ( n < 10 ) 
	{
		insertionSort(arr,n);
		return;
	}

	int mid = n / 2;
	int mid2 = n - mid;

	T *Left = new T[mid];
	T *Right = new T[mid2];

	for ( int i = 0; i < mid; i++ )
	{
		Left[i] = arr[i];
	}

	for ( int i = 0; i < mid2; i++ )
	{
		Right[i] = arr[mid+i];
	}

	mergeSort(Left, mid);
	mergeSort(Right,mid2); 
	merge(Left,mid,Right,mid2,arr);
	delete [] Left;
	delete [] Right;
}

template Metrics<int>;
template Metrics<char>;
template Metrics<string>;
