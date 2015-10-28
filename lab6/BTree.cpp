#include <iostream>
using namespace std;
#include "BTreeNode.h"

class BTree {
  
  private:
    BTreeNode *root;

  public:
    BTree( ) : root(NULL) 
    {
    }

    void insert(int item) 
    {
      if( root==NULL ) 
         root = new BLeaf();
      int newKey;
      BTreeNode *split = root->insert(item, newKey);
      if(split!=NULL) {      
	 cout << "Splitting root " << endl;
         BInternal *newRoot = new BInternal();
         newRoot->child[0] = root;
         newRoot->child[1] = split;
         newRoot->marker[1] = newKey;
         newRoot->currChildren = 2;
         root = newRoot;
      }
    }

    void dump() {
      root->dump(0);
    }
};


   int main( ) {
      BTree B;
      int add;
      do{
	cout << "Enter next val (0 to quit) ";
        cin >> add;
        if( add>0 ) {
           B.insert(add); 
           B.dump();
	}
      } while(add>0);
      return 0;
   }


