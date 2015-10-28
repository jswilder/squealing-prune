#include <string>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
using namespace std;

int main () {
/*
	int x = 'A' - 'a';
	int y = 'b' - 'B';

	string str1 = "hello, world!";
	string str2 = "HELLO, WORLD!";

	if( boost::iequals(str1 ,str2 ) )
		cout << "\n\nIt works!\n\n";

	cout << "\n\n" << x << endl << y << endl << endl;

	cout << "rand numbers?\n";

	int i;

	for(i=0; i<10; i++){

		x = rand() % 101;
		cout << x << " , ";
		x = rand() % 203;
		cout << x << endl;
	}

	cout << (int)str1[2] << endl;

	x = 'l';

	cout << x << endl;

	cout << 99 % 103 << endl;
	cout << 82 % 103 << endl;
	cout << 104 % 103 << endl;
*/
	int array[10];
	int i;

	for ( i=0; i<10; i++){

		array[i] = 0;
	}

	cout << endl;

	for(i=0; i<3; i++){

		array[1]++;
		cout << array[1] << endl;
	}


return 0;
}
