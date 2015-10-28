#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "CharRecord.h"

typedef CharRecord ItemType; 

const ItemType ERROR = -1;

class PriorityQueue {

	public:
		virtual void insertItem(ItemType)=0;
		virtual ItemType removeMin()=0;
		virtual bool isEmpty() const =0;
		virtual int getCount() const =0;
};

#endif
