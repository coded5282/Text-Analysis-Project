/*
Edward Chen
Header file for Plot class
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

#ifndef PLOT_H
#define PLOT_H
#include <iostream>
#include <string>
using namespace std;

class Plot
{
private:
	int id;
	string* xlabel;
	string* ylabel;
	int numPoints;
public:
	void setId(int num);
	int getId();
	void setnumPoints(int nums);
	int getnumPoints();
	Plot();
	~Plot();
	void plot2D(double x[], double y[], int n); 
	void histogram(int freq[],int amount); 
}; 

#endif