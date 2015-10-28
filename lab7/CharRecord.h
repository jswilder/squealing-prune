// Jeremy Wilder

using namespace std;
#include <string.h>

#ifndef CHAR_RECORD_H
#define CHAR_RECORD_H

class CharRecord : public Heap {

	public:
		CharRecord();
		CharRecord( const string i, int c);
		string getCharString() const;
		int getCount() const;
//		void operator=(CharRecord& other);
		bool operator<(CharRecord& other);
		bool operator>(CharRecord& other);

	private:
		const char item;
		int count;
};

CharRecord::CharRecord(){

}

CharRecord::CharRecord( const string i, int c ) : item(i), count(c)
{
}

int CharRecord::getCount()const{

	return count;
}

string CharRecord::getCharString()const{

	return item;
}

bool CharRecord::operator<(CharRecord &other){

	if( this < other )
		return true;

return false;
}

bool CharRecord::operator>(CharRecord &other){

	if( this > other )
		return true;

return false;
}

#endif
