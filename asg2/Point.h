// Jeremy Wilder
// Assignment 2

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point 
{
   private:
     int X,Y;

   public:
      Point(int x, int y);
      Point( const Point& other);
      int getX( );
      int getY( );
      bool operator==(const Point & other);
      friend ostream & operator<<(ostream &out, const Point & P );
};

Point::Point( int x, int y) : X(x), Y(y)
{
}

Point::Point( const Point& other) : X(other.X), Y(other.Y)
{
}

int Point::getX( ){

return this->X;
}

int Point::getY( ){

return this->Y;
}

bool Point::operator==(const Point & other){

	if( this->X == other.X && this->Y == other.Y)
		return true;

return false;
}

ostream & operator<<(ostream &out, const Point & P ){

	cout << "(" << P.X << "," << P.Y << ") ";

return out;
}


#endif

