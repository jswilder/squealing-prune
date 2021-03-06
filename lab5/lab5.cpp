// Jeremy Wilder
// Lab 5

// Giggletree creation and printing

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

#include "giggleTree.h"

bool compare( string a, string b){

	if( a[0] > b[0] )
		return true;

return false;
}

int main(int argc, char* argv[]){

	string list[argc-1];
	string temp;
	int i, count =1;

	cout << endl;

	for(i=0; i<argc-1; i++){

		list[i] = argv[i+1];
		cout << list[i] << endl;
	}

	cout << endl;

	GiggleTree tree( argv[1]);

	for(i=0; i<argc-1; i++){
		tree.buildTree( argv[i+1] );
	}
	tree.print();

return 0;
}
