// BTreeNode.h wdg 2008
#include <iostream>
using namespace std;

class BTreeNode 
{
  public:
    static const int MAX=3;  
    virtual BTreeNode *insert(int item, int &newKey) = 0;
    virtual void dump(int depth) = 0;
    void indent(int depth) 
    {
      for(int i=0; i<depth; i++)
	 cout << "..."; 
    }  
};

class BLeaf : public BTreeNode 
{
  private:
    int value[MAX+1];  // need to go temporarily over
    int elements;

  public:
    BLeaf() : elements(0)
    {
    }

    BLeaf * insert(int item, int& newKey) 
    {
       int pos=elements-1;
       while(pos>=0 && item<value[pos]) {
         value[pos+1]=value[pos];
         pos--;
       }
       value[pos+1] = item;
       elements++;
       if(elements<=MAX)
          return NULL;
       else {
	// cout << "Splitting " << endl;
         BLeaf *sibling = new BLeaf();
         for(int i=0; i<(MAX+1)/2; i++)
	     sibling->value[i] = value[i + (MAX+2)/2];
         sibling->elements = (MAX+1)/2;
         elements -= (MAX+1)/2;
         newKey = sibling->value[0];
         return sibling;
       }
    }

    void dump(int depth) 
    {
      indent(depth);
      if( elements> 0 ) {
        for(int i=0; i<elements; i++)
           cout << value[i] << ",";
      }
      else 
         cout << "Empty";
      cout << endl;
    }

};     
   

class BInternal : public BTreeNode 
{
   
   private:
     BTreeNode * child[MAX+1];
     int marker[MAX+1];
     int currChildren;

     // note: marker[0] is not used
     // child[0] - marker[1] - child[1] - marker[2] - child[2] etc

     friend class BTree;

   public:

    BInternal() : currChildren(0) 
    {      
    }

    BInternal *insert(int item, int &newKey) 
    {
      int pos=0;
      while(pos<currChildren-1 && item>=marker[pos+1])
         pos++;
      int addedKey;
      BTreeNode *split = child[pos]->insert(item,addedKey);

      if(split!=NULL) {
         for(int i = currChildren-1; i>=pos+1; i--) {
             marker[i+1] = marker[i];
             child[i+1] = child[i];             
         }
         child[pos+1] = split;
         marker[pos+1] = addedKey;
         currChildren++;          

         if(currChildren>MAX) {
            BInternal *sibling = new BInternal();
            for(int i=0; i<(MAX+1)/2;  i++) 
	      sibling->child[i] = child[i+(MAX+2)/2];
            for(int i=1; i<(MAX+1)/2;  i++) 
	      sibling->marker[i] = marker[i+(MAX+2)/2];               
            sibling->currChildren = (MAX+1)/2;
            currChildren -= (MAX+1)/2;
            newKey = marker[ (MAX+2)/2 ];
            return sibling;
         }
      }
      // if reach here 
      return NULL;
    } 

   void dump(int depth) 
   {
      indent(depth);
      cout << "(";
      for(int i=1; i<currChildren; i++)
        cout << marker[i] << ",";
      cout <<")" << endl;
      for(int i=0; i<currChildren; i++) 
          child[i]->dump(depth+1);           
   }

};     

