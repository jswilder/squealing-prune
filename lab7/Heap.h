// Heap.h - wdg 2008
#ifndef HEAP_H
#define HEAP_H
#include "PriorityQueue.h"

class Heap : public PriorityQueue 
{
 public:
   Heap();
   void insertItem(ItemType);
   ItemType removeMin();
   bool isEmpty() const;
   int getCount() const;

 private:
   int count;
   ItemType A[100];
};
#endif
