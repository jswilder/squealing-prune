
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

int main () {

	int x, y;

	for( int c =0; c < 10; c++){
	x = rand() % 10 + 5;

	y = rand() % 100;

	cout << x << " , " << y << endl;

	}

return 0;
}
