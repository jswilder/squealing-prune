#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int main( ){

	int val, i, temp;
	vector<int> myVec;

	cout << "\nEnter your number in decimal\n\n";
	cin >> val;

	while( val != 0 ){

		temp = val % 2;
		myVec.push_back( temp );
		i++;
		val = val / 2;
	}

	while( i != 0 ){
		cout << myVec.pop_back();
		i--;
	}

	cout << endl << endl;

return 0;
}
