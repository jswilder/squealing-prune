// Jeremy Wilder
// Assignment 2

#include <vector>
#include <cmath>
using namespace std;
#include "Point.h"
#include "PointStack.h"

double angle(Point &A, Point &B) {
	return atan2( B.getY()-A.getY(), B.getX() - A.getX() );
}

void sortByAngleFromFirst(vector<Point> &list){
	for( int round=1; round<list.size(); round++) {
		int i=round; 
		Point newPoint = list[round];
		double newAngle = angle(list[0], newPoint );
		while( i>1 && ( newAngle < angle(list[0], list[i-1]) ) ) {
			list[i]=list[i-1];
			i--;
		}
	list[i] = newPoint;
	}
} 

void moveLeftmostFirst( vector<Point> &list ) {
	int leftmost=0;
	for(int i=1; i<list.size(); i++)
		if( list[i].getX() < list[leftmost].getX() ) 
		leftmost=i;
		Point temp = list[leftmost];
		list[leftmost] = list[0];
		list[0] = temp;
}

bool isLeftTurn( Point &A, Point &B, Point &C ) {
	return (B.getY()-A.getY())*(C.getX()-B.getX()) < 
		(C.getY()-B.getY())*(B.getX()-A.getX());
}

void debugDump( vector<Point> &list) {

	cout << "****";
	for(int i=0; i<list.size(); i++) 
		cout << list[i] << ",";
	cout << endl;
}

void print( vector<Point> &list) {

	cout << "Hull points are : ";
	for(int i=0; i<list.size(); i++) 
		cout << list[i];
	cout << endl;
}

vector<Point> convexHull( vector<Point> &list) {

	vector<Point> hull;
	int i, count, j;

	for(i=0; i<list.size(); i++){
		hull.push_back( list[i] );
	}
		//Finds the left-most point
	moveLeftmostFirst( hull );
		//Sort the list by angle from the left-most point
	sortByAngleFromFirst( hull );

	j = hull.size();
	i = 0;

	while( i < j-2 ){
		if( ! ( isLeftTurn(hull[i], hull[i+1], hull[i+2] ) ) ){
				//Removes if not a left turn
			hull.erase( hull.begin() + (i+1) );
			i--;
			j--;
		}
		else
			i++;
	}
	print( hull );

return hull;			//Return what's left
}

void convexLayers( vector<Point> &list ) {

	int i,j;
	vector<Point> temp;

		//Every shape triangle and larger
	while( list.size() > 2 ){

		temp = convexHull( list );
			//Remove everything already found to be in a hull
		for(i=0; i<list.size(); i++)
			for(j=0; j<temp.size(); j++){
				if( list[i] == temp[j] ){
					list.erase( list.begin() + i );
					i--;
				}
			}
	}
		//If there isnt enough to make a hull print, *less than 3 points
	if( list.size() < 3 && list.size() != 0 ){
		print( list );
	}
}
