/*
Edward Chen
Source file for Plot class
Overview of Plot Class: Class used to plot various data
Functions:
void setId(int num) -- Sets the id of class
int getId() -- Returns the id 
void setnumPoints(int nums) -- Sets the number of points in object
int getnumPoints() -- Returns the number of points
Plot() -- Constructor for Plot class
~Plot() -- Destructor for Plot class
void plot2D(double x[], double y[], int n) -- Plots data given 2 arrays
void histogram(int freq[], int amount) -- Plots frequency of data given array and size
*/

#include <iostream>
#include <string>
#include "Plot.h"
using namespace std;

/*
Purpose: Sets the id of Plot object 
Assumptions - 
Pre-condition: Id is given and valid
Post-conditon: Id is set
*/
void Plot::setId(int num)
{
	id = num;
}
/*
Purpose: Returns the id of Plot object
Assumptions - 
Pre-condition: Plot object is created and id is set
Post-conditon: Id is returned
*/
int Plot::getId()
{
	return id;
}
/*
Purpose: Sets the number of points for object
Assumptions - 
Pre-condition: Object is created and number is valid
Post-conditon: Number of points is set
*/
void Plot::setnumPoints(int nums)
{
	numPoints = nums;
}
/*
Purpose: Returns the number of points in Plot
Assumptions - 
Pre-condition: Object is created and number of points is set
Post-conditon: Number of points is returned
*/
int Plot::getnumPoints()
{
	return numPoints;
}
/*
Purpose: Constructor for Plot class
Assumptions - 
Pre-condition: Creating Plot object
Post-conditon: Plot object is created
*/
Plot::Plot()
{
}
/*
Purpose: Destructor for Plot class
Assumptions - 
Pre-condition: Plot object is created
Post-conditon: Plot object is destructed
*/
Plot::~Plot()
{
}
/*
Purpose: Plots data given x and y values in array, as well as size
Assumptions - 
Pre-condition: X and Y values of data, as well as size, are valid
Post-conditon: X and Y values are plotted and values stay same
*/
void Plot::plot2D(double x[], double y[], int n)
{
	// start
	double maxY = 0;
	//int* arr;
	//int* arrX;
	double maxX = 0;
	double minY = 1000;
	double minX = 1000;

	for ( int i = 0; i < n; i++ ) // Find max value of Y and X
	{
		if (y[i] > maxY)
		{
			maxY = y[i];
		}
		if (x[i] > maxX)
		{
			maxX = x[i];
		}
		if (y[i] < minY)
		{
			minY = y[i];
		}
		if (x[i] < minX)
		{
			minX = x[i];
		}
	}

	if ( maxY > 25.0 ) // Scale output if the max value of Y surpasses the the amount of Y values the output screen can show
	{
		double factorY = (25.000) / (maxY);

		for ( int i = 0; i < n; i++ )
		{
			y[i] *= factorY;
			//y[i] += 2;
		}

		maxY *= factorY;
	}

	if ( maxX > 78 ) // Scale output if the max value of X surpasses the amount of X values the output screen can show 
	{
		double factorX = (80.0) / (maxX);

		for ( int i = 0; i < n; i++ )
		{
			x[i] *= factorX;
		}

		maxX *= factorX;
	}

	char screen[80][25];
	
	//makes screen
	for(int g = 0; g < 80; g++)
	{
		for(int j = 0; j < 25; j++)
		{
			screen[g][j] = ' ';
		}
	}

	//makes ruler
	for(int g = 0; g < 25; g++)
	{
		screen[0][g] = '-';
		if(g%2==0)
		{
			screen[1][g] = '-';
		}
	}

	for ( int d = 0; d < 80; d++ )
	{
		screen[d][24] = '|';
		if (d%2==0)
		{
			screen[d][23] = '|';
		}
	}

	for(int i = 0; i < n; i++)
	{
		int x_pos = x[i] + 2; //plus 2 to account for ruler dashes
		int y_pos = y[i] + 2;
		if(y_pos == 0) // to prevent rolling over as position 25 is one greater than array contains: 0-24
			y_pos++;
		screen[x_pos][25 - y_pos] = '*';
	}

	//prints out screen
	for(int g = 0; g < 25; g++)
	{
		for(int j = 0; j < 80; j++)
		{
			cout << screen[j][g];
		}
		
	}	
}
/*
Purpose: Plots the histogram of given data based on frequency and size
Assumptions - 
Pre-condition: Frequency array and size are valid
Post-conditon: Frequency array is plotted and values stay same
*/
void Plot::histogram(int freq[],int amount)
{
	int maxFreq = 0;

	for ( int i = 0; i < amount; i++ )
	{
		if ( freq[i] > maxFreq )
		{
			maxFreq = freq[i];
		}
	}

	for ( int i = maxFreq; i > 0; i-- )
	{
		for ( int j = 0; j < amount; j++ )
		{
			if ( freq[j] < i )
			{
				cout << ".";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}
