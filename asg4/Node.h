// Jeremy Wilder
// Asg 4

#ifndef NODE_H
#define NODE_H
#include <cstddef>
#include <stack>

class Node{

	public:
		string name;
		Node *left, *right, *parent;
		Node( string word );
		Node( string a, string b );
};

#endif
