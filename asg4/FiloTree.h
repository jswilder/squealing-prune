// Jeremy Wilder
// Asg4

#ifndef FILOTREE_H
#define FILOTREE_H

#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "Node.h"

class FiloTree{

	public:
		FiloTree(string fileName);
		~FiloTree( );
		void dump( ) const;
		static void compare( const FiloTree &A, const FiloTree &B);
		static void printNodes( FiloTree &A );

	private:
		int size;
		vector<Node> nodes;
};

#endif
