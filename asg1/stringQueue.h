//	Jeremy Wilder
//	Assignment 1
//	Header file containing all of the stringQueue functions EXCEPT for
//	radixSort which I deemed too large to share a file
//
//	File also contains the recursive word ladder solver functions

#ifndef STRING_QUEUE_H
#define STRING_QUEUE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

class stringQueue {

	private: 

	public:
		stringQueue( );
        stringQueue(int cap);
		void print();
		void radixSort( );
		void ladderSolver( );
		bool check( string compare , string compare2);
		bool alreadyFound( string compare, string list[]);

		int capacity;
		int count;
		int moves, sum, AF, AP;
		int pos, strlen;
		string start, goal;
		string list[2000];
		string temp[2000];
		string temp2[2000];
		string already_found[2000];
		string already_printed[2000];
};

stringQueue::stringQueue(int cap){

	capacity = cap;
	count = 0;
	sum = 0;
	AF = 0;
}

void stringQueue::print(){

	int i;

	cout << endl;

	for( i=0; i<capacity; i++){

		cout << list[i] << endl;
	}

	cout << endl;
}

	//Makes sure the word found has not already been used
bool stringQueue::alreadyFound( string compare, string list[]){

	int i;

	for( i=0; i< capacity; i++){
		if( compare == list[i])
			return true;
	}

return false;
}

	//Checks to see if the word is one letter different from compare
bool stringQueue::check(string compare, string compare2 ){

	int i, count = 0;

	for(i=0; i<strlen; i++){
		if( compare[i] == compare2[i] ){
			count++;
		}
		if( ( count == strlen-1 ) && ( compare != compare2 ) ){
			return true;
		}
	}
	
return false;
}

void stringQueue::ladderSolver( ){

		//Printer to make sure the values are being passed correctly from Main
	cout << "Start word : " << start << endl;
	cout << "Goal word : " << goal << endl;
	cout << "Number of moves allowed : " << moves << endl;
	cout << endl;
	cout << "\t\tLadder Solver" << endl;

		//Let the function begin...

	int i,j, count, AP = 0;
	string compare;

	compare = start;

	AF = 1;
	already_found[0] = start;

		//-----------------------------------------------------------------

		//Loop to see if first round victory is possible
			//This is only done to make it print an appropriate message
	for( this->sum=0; this->sum < 1; this->sum++ ){

		for(i=0; i<capacity; i++){

			if( check( start, this->list[i] ) ){

				this->temp[this->count] = this->list[i];
				if( !( alreadyFound( list[i], already_found) ) ){

					already_found[AF] = this->list[i];
					AF++;
				}
				this->count++;
			}
		}

			//Check to see if first found the goal word
		for( i=0; i<this->count; i++){

			if( this->temp[i] == goal ){

				cout << endl << "Success in 1 move!!" << endl << endl;

				this->sum = moves + 1;
				return;
			}
		}
	}

	cout << endl << "1st move list" << endl;

	for( i=0; i<this->count; i++){

		if( !(alreadyFound( temp[i], already_printed )) ){
			cout << temp[i] << endl;
			already_printed[AP] = temp[i];
			AP++;
		}
	}

		//----------------------------------------------------------------
	
		//If it cant be done in one move, this loop runs
	for( this->sum=1; this->sum < moves; this->sum++ ){

		count = this->count;
		this->count=0;

		for(i=0; i<count; i++){
			for(j=0; j<capacity; j++){

				if( check( this->temp[i], this->list[j] ) ){

					this->temp2[this->count] = this->list[j];
					if( !( alreadyFound( list[i], already_found ))){

						already_found[AF] = this->list[j];
						AF++;
					}
					this->count++;
				}
			}
		}

			//Prints the current possible move list
		cout << endl << this->sum+1 << " move list" << endl;

		for( i=0; i< this->count; i++){

			if( !(alreadyFound( temp2[i], already_printed )) ){
				cout << temp2[i] << endl;
				already_printed[AP] = temp2[i];
				AP++;
			}
		}

			//Check to see if goal word found
		for( i=0; i<this->count; i++){

			if( this->temp2[i] == goal ){

				cout << endl;
				cout << "Success in " << this->sum+1 << " moves!!" << endl;
				cout << endl;

				this->sum = moves + 1;
				return;
			}
	
		}

		for(i=0; i<this->count; i++){

			this->temp[i] = this->temp2[i];
		}
	}

		//-----------------------------------------------------------------

		//If the ladder can't be solved it will print an appropriate message

	if( this->sum >= moves ){
		cout << "No more moves :/" << endl;
		cout << "Could not be solved" << endl << endl;
	}
}

#endif


