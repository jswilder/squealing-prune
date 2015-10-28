// Jeremy Wilder
// Assignment 2

#ifndef PoINT_STACK_H
#define PoINT_STACK_H

#include <vector>
#include "Point.h"
using namespace std;

class Node {

	private:
		Point data;
		Node *next;

		Node(const Point & d) : data(d), next(NULL)  
		{
		}
		friend class PointStack;
};

class PointStack {

	private:
		Node *stackTop;
		int count;

	public:
		PointStack( );
		~PointStack( );
		void push(const Point & item);
		Point pop( );
		Point & peek( );
		Point & peekUnder( );
		bool isEmpty( );
};

/*-------------------*/

	//Default constructor
PointStack::PointStack(){

		//So I will know the total in the list at any given time
			//Also quite handy for knowing when to add to the list or start it
			//should it be empty
	count = 0;
}

/*-------------------*/

	//Default destructor
PointStack::~PointStack()
{
}

/*-------------------*/

	//Adds an item to the PointStack in the count position
void PointStack::push(const Point & item){

			//If nothing is in the list, it creates it
	if( count == 0){

		stackTop = new Node(item);
	}
			//If something is in the list already, the new item becomes stackTop,
				// The previous stackTop becomes the next of the new item
	if( count > 0 ){

		Node *node = new Node(item);

		node->next = stackTop;
		stackTop = node;
	}
		//Increment list total **VERY IMPORTANT
	count++;
}

/*-------------------*/

	//Removes and returns an item from the PointStack
Point PointStack::pop( ){

	Node *kill = stackTop;	//Current first item, the item destroyed/returned
	Node *first = stackTop;	//Becomes first item
	Point a(stackTop->data);

	kill = stackTop;
	first = stackTop->next;
	stackTop = first;
	delete(kill);
	count--;			//Decrement list total **VERY IMPORTANT

return a;
}

/*-------------------*/

	//Returns the point that is the stackTop
Point &PointStack::peek( ){

	return stackTop->data;
}

/*-------------------*/

	//Returns the point beneath the stackTop
Point &PointStack::peekUnder( ){

	return stackTop->next->data;
}

/*-------------------*/

	//This is pretty self-explanatory...
bool PointStack::isEmpty( ){

	if( count == 0 )
		return true;

return false;
}

/*-------------------*/

#endif

