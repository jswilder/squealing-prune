//	Jeremy Wilder
//	Assignment 1
//
//	Word ladder

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

#include "radixSort.h"

//------------------------------------------------------------------------------
//-------------------------------------MAIN-------------------------------------
//------------------------------------------------------------------------------

int main ( int argc, char *argv[] ) {

	int x, i, moves;	
	string c;

	x = 0;

	string start, goal;

	start = argv[2];
	goal = argv[3];
	moves = atol(argv[4]);

		//Handles opening/closing the file, finding number of strings in file
	string filename (argv[1]);
	ifstream infile;
	infile.open( filename.c_str() );

	if( ! infile ) {
		cout << "could not open file" << filename << endl;
	}

	if( argc != 5 ){
		cout << "Error:: Too few arguments" << endl;
	}

	while( infile >> c){
		x++;
	}

	infile.close( );

		//-------------------------------------------------------------------

		//Stores the data into the string list
	stringQueue *string = new stringQueue(x);

	infile.open( filename.c_str() );
		//arbitrarily large number to ensure the end isn't reached

	for(i =0; i < x; i++ ){

		if(infile >> c){
		string->list[i] = c;
		}
	}

	infile.close( );

		//-----------------------------------------------------------------

		// Loop to call radixSort()....

	string->pos = string->list[0].length();

	int word_length = string->list[0].length();

	for( i=0; i < word_length; i++){

			//Subtracts one each time so the array's position is accurate
		string->pos = string->pos - 1;
		string->radixSort( );	
	}

	cout << "\t\tAfter radixSort is performed" << endl;
	string->print();

		//-----------------------------------------------------------------

		//Word ladder solver....

	string->strlen = string->list[0].length();
	string->moves = moves;
	string->start = start;
	string->goal = goal;

	if( moves < 1 ){
		cout << "Error: You must provide an integer larger than 0" << endl;
	}
	if( moves > 0){
	string->ladderSolver( );	
	}

	free(string);

return 0;
}
