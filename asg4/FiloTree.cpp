// Jeremy Wilder
// Asg4

#ifndef FILOTREE_CPP
#define FILOTREE_CPP

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "FiloTree.h"

FiloTree::FiloTree(string fileName){

	int i, j;

			// Read in the file of course..
	ifstream infile;
	infile.open( fileName.c_str() );

	if( ! infile ) {
		cout << "could not open file" << fileName << endl;
		return;
	}
		// Read in size
	infile >> size;

	double array[size][size];
	string word[size];

		//Reads in the words
	for( i=0; i<size; i++){

		infile >> word[i];
	}
		//Reads in the numbers as doubles
	for( i=0; i<size; i++){
		for(j=0; j<size; j++){

			infile >> array[i][j];
		}
	}

	infile.close( );

/*---------------------------------------------------------------------------*/
		
	int x, y, z;	// i & j storage for min
	double min;

	for( z=0; z<size-1; z++){	// Begin finding neighbors

		min = 100000000000000000;

			//finds two closest values   -  O( n^2 )
		for(i=0; i< size; i++){
			for( j=0; j<size; j++){
				if( array[i][j] != 0 && min > array[i][j] ){
					min = array[i][j];
					x = i;
					y = j;
				}
			}
		}
			//Creates nodes out of the closest strings
				//Add them to the vector of nodes for the tree	- constant time
		Node *Parent = new Node( word[x], word[y] );
		nodes.push_back( *Parent );

			// Replaces first word in the vector with combined word
				// erases the other
		word[x] = Parent->name;
		word[y] = "";

			// Calculates new vals, storing them in [i][x] & [x][i]
				// [i][y] & [y][i] become zeros		- O( n );
		for(i=0; i<size; i++){

			array[x][i] = ( ( array[x][i] + array[y][i] ) / 2 );
			array[i][x] = array[x][i];
			array[y][i] = array[i][y] = 0;

			if( x == i )
				array[x][i] = 0;
		}
	} //Ends Neighbor-Finding loop
}

/*-------*/

FiloTree::~FiloTree( ){
	nodes.clear( );
}
/*-------*/

void FiloTree::dump( ) const{

	int s = nodes.size();

	cout << "\n\n\t****Dumping tree****\n";

	while( s != 0 ){
		cout << "\nMerge " << s-- << endl;
		cout << "........." << nodes[s].left->name << endl;
		cout << "........." << nodes[s].right->name << endl;
	}
	cout << endl << endl;
}

/*-------*/

void FiloTree::compare( const FiloTree &A, const FiloTree &B){

		// A simple check, if the tree sizes dont match they can't be equal
	if( A.nodes.size() != B.nodes.size() ){
		cout << "\nThe trees are NOT equal\n\n";
		return;
	}

	int count, i, j, x;
	count = 0;

	for( i=0; i< A.nodes.size( ); i++){
		for( j=0; j< B.nodes.size(); j++){

			x = 0;

				// Compares all children agaisnt each other
					// if any node matches another, count is incremented
					// if count equals the size, the trees match
			if( A.nodes[i].left->name == B.nodes[j].left->name)
				x++;
			if( A.nodes[i].right->name == B.nodes[j].right->name)
				x++;
			if( A.nodes[i].left->name == B.nodes[j].right->name)
				x++;
			if( A.nodes[i].right->name == B.nodes[j].left->name)
				x++;
			if( x == 2 )
				count++;
		}
	}

	if( count == A.nodes.size( ) )
		cout << "\nThe trees are equal\n\n";
	if( count != A.nodes.size() )
		cout << "\nThe trees are NOT equal\n\n";
}

void FiloTree::printNodes( FiloTree &A ){

	int s = A.nodes.size();

	cout << endl;

	while( s != 0 ){
		s--;
		cout << A.nodes[s].left->name << " , " << A.nodes[s].right->name << endl;
	}
}

/*-------*/

//-----------------------------------------------------------------------------
//-----------NODE IMPLEMENTATION-----------------------------------------------
//-----------------------------------------------------------------------------

	//Creates a child
Node::Node( string word ){

	name = word;
	parent = NULL;
	left = NULL;
	right = NULL;
}

	//Creates a parent node
Node::Node( string a , string b ){

	Node *A = new Node( a );
	Node *B = new Node( b );

	if( a[0] < b[0] ){
		name = a + b;
		this->left = A;
		this->right = B;
	}
	else{
		name = b + a;
		this->left = B;
		this->right = A;
	}
}

#endif
