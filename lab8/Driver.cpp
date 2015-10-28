// Jeremy Wilder
// Lab 8

#include "WordHash.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void read(WordHash & hash, char* fileName) {
	// delimiters used in StringTokenizer
	string delimiters = " .,!?:;@#$%^&*-_=+1234567890";

	string line;

	ifstream in ( fileName );
	if( !in ) {
	cerr << "Cannot open " << fileName;
	}

	else {
		while( getline(in, line) ) {
			int lineLen = line.length();

			for(int i=0; i<lineLen; i++) 
				if( line[i]>='A' && line[i]<='Z' )
					line[i] += 'a'-'A' ;
					int start = line.find_first_not_of(delimiters,0);

				while( start>=0 && start<lineLen ) {
					int stop = line.find_first_of(delimiters,start);
				if( stop<0 || stop>lineLen)
					stop = lineLen;
					hash.addWord( line.substr( start, stop-start ) );
					start = line.find_first_not_of( delimiters, stop+1);
				} // end while 
		} // end while
	} // end else

		//Prints the most common word found
	cout << "\n\nThe most common word is '";
	cout << hash.findCommon() << "' " << endl << endl;
}

int main(int argc, char *argv[]) {

	// check for input
	if(argc != 2) {
		cerr << "Please specify filename to read";
		return 1;
	}

	int size = 103;
	WordHash *hash = new WordHash(size);
	read( *hash, argv[1] );

return 0;
}
