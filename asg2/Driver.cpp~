// Jeremy Wilder
// Assignment 2

// **Compile instructions**
// I included grahamScan as a .h file
// Simply g++ Driver.cpp and it will run the grahamScan,
// then of course run the ./a.out
// I couldn't work out another way to run it wihtout a
// bunch of errors

#include <stack> 
#include <vector>
#include <deque>
#include <iostream>
#include "PointStack.h"
#include "grahamScan.h"
using namespace std;

int main ( ){

	vector<Point> myPoints;

	int X, Y, x, i;

	cout << "\nHow many sets of points would you like?\n";

	cin >> x;

	cout << "\nPlease enter the points now..\n";

		//Adds points to the list
	for( i=0; i<x; i++){

		cin >> X;
		cin >> Y;
		Point p(X,Y);
		myPoints.push_back(p);
	}
	cout << endl;

	convexLayers( myPoints );

return 0;
}
