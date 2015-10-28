// Jeremy Wilder 2014
// lab1.cpp

#include <iostream>
#include <cmath>
using namespace std;

class NumberCount {

	private:
		int min,max;
		int *A;
		int total;

	public:
		NumberCount( );
		NumberCount(int min,int max);

		bool addElement(int number);
		bool removeElement(int number);
		void display( );
		int getCount( );
};

NumberCount::NumberCount() {

	min = 0;
	max = 0;
}

NumberCount::NumberCount(int minn, int maxx) {

	min = minn;
	max = maxx;

	A = new int[max-min+1];
}

	//Adds 1 to the respective value
bool NumberCount::addElement(int number) {

	if(number > max || number < min) {
        cout <<  number << " out of range" << endl;
		return false;
	}

	int count = 0;

    while(count + min <= number){
        count++;
    }

    int x = A[count];
    A[count] = x + 1;

	total = total + 1;

return true;
}

bool NumberCount::removeElement(int number) {

	int count = 1;

    while(count + min <= number){
        count++;
    }

	if(A[count] == 0) {
		cout << number << " not present" << endl;
		return false;
	}

    A[count] = A[count] - 1;

	total = total - 1;

return true;
}

	//Function displays results in a histogram using a " * " to represent the
	// value in the chart
void NumberCount::display(){

    int count;
    int x;
	int y = 0;

    for(count = 1; count < ( max-min+1 ); count++) {

		cout << min+y << ":";
		x = A[count];

		while(x > 0) {

        	cout << " * ";
			x--;
    	}
		cout << endl;
		y++;
	}
}

int NumberCount::getCount(){

return total;
}


//---------------------------------------------------------------------------//
//-----------------------------MAIN------------------------------------------//
//---------------------------------------------------------------------------//

int main(){

	int min,max;

	cout << "Enter a min and a max" << endl;
	cin >> min >> max;

	NumberCount N(min,max);

	N.addElement(2);
	N.addElement(2);
	N.addElement(2);
	N.addElement(4);
	N.addElement(7);
	N.addElement(3);
	N.removeElement(1);
	N.removeElement(3);

	N.display();

return 0;
}
