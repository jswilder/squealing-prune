// Jeremy Wilder
// Lab 8

#ifndef WORDHASH_H
#define WORDHASH_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class WordHash{

	public:
		string words[103];
		int count[103];
		int size;
		WordHash(int s);
		void addWord(string word);
		string findCommon();
};

WordHash::WordHash(int s){

	size = s;

	string str1 = "";
	for( int i=0; i<size; i++){

		count[i] = 0;
		words[i] = str1;
	}
}

string WordHash::findCommon(){

	int x,i,j;

	x = count[0];
	j = 0;

	for(i=0; i<103; i++){

		if( count[i] > x ){
			x = count[i];
			j = i; 
		}
		else{
			x = x;
			j = j;
		}
	}
return words[j];
}

void WordHash::addWord(string word){

		//Takes the ascii of the first letter for hash calculation
	int a = (int)word[0];
		//Calculates the position in array
	a = (( 37*a ) % 103 );

	int x, i;

		//If its not empty, but it is the same word, increment count
	if( count != 0 && word == words[a] ){
		count[a]++;
	}
		//If empty, add the word
	if( count[a] == 0 ){
		words[a] = word;
		count[a]++;
	}
		//If not equal zero but the words arent the same, PROBE!!!
	if( count!= 0 && word != words[a] ){

		i = 1;

		while( i<103 ){
			x = (( a + i ) % 103);

				//If words are equal, increment count, quit loop
			if( word == words[x] ){
				count[x]++;
				i = 5000;	//Ends the loop
			}
				//If it finds and empty slot, add the word, quit loop
			if( count[x] == 0 ){
				words[x] = word;
				count[x]++;
				i = 5000;	//Ends the loop
			}
				//If conditions aren't met, move to the next position
			if( count != 0 || word != words[x] ){	
				i++;
			}
		}
	}
}

#endif