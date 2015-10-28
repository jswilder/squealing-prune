#ifndef GIGGLETREE_H
#define GIGGLETREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

#include "gatewayNode.h"

class GiggleTree {

	private:
		GatewayNode	*parent;

	public:
		GiggleTree( string current ) : parent(new GatewayNode(current))
		{
			cout << "Parent " << parent->data->element << endl;
		}
		void buildTree(string current);
		void print();
	friend class GatewayNode;
	friend class DataNode;
};

// Functions go right and left

void GatewayNode::go_left( string current ){

	if( left == 0 ){
		GatewayNode *newGate = new GatewayNode(current);
		this->left = newGate;
		cout << "current key\t" << this->left->key << endl;
		cout << "new left\t" << this->left->data->element << endl;
	}

	if( current[0] == this->left->key){
		DataNode *a = new DataNode(current, 0);
		this->left->data->next = a;
		cout << "current key\t" << this->left->key << endl;
		cout << "new left\t" << this->left->data->next->element << endl;
	}

	if( current[0] < left->key ){
		this->left->go_left( current );
	}

	if( current[0] > right->key ){
		this->left->go_right( current );
	}
}

void GatewayNode::go_right( string current ){

	if( right == 0 ){
		GatewayNode *newGate = new GatewayNode(current);
		this->right = newGate;
		cout << "current key\t" << this->right->key << endl;
		cout << "new right\t" << this->right->data->element << endl;
	}

	if( current[0] == this->right->key){
		DataNode *a = new DataNode(current, 0);
		this->right->data->next = a;
		cout << "current key\t" << this->right->key << endl;
		cout << "new right\t" << this->right->data->next->element << endl;
	}

	if( current[0] < left->key ){
		this->right->go_left( current );
	}

	if( current[0] > right->key ){
		this->right->go_right( current );
	}
}

void GiggleTree::buildTree( string current ){

	if( current[0] == parent->key){
		DataNode *a = new DataNode(current, 0);
		parent->data->next = a;
		cout << "Parent next " << parent->data->next->element << endl;
	}

	if( current[0] < this->parent->key ){

		parent->go_left( current );
	}

	if( current[0] > this->parent->key ){

		parent->go_right( current );
	}
}

void GiggleTree::print(){
/*
	cout << parent->data->element << endl;

	cout << parent->data->next->element << endl;

	cout << parent->left->data->element << endl;
	cout << parent->left->data->next->element << endl;
*/
	cout << endl;
}

#endif
