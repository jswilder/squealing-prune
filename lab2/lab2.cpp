// Jeremy Wilder 2014
// LAB 2 - polynomial equations storage and manipulation

#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {

	private:
		int coeff[100];
		int power[100];
		int count;

	public:
		Polynomial( );

		void incrementBy(int c, int p );
		bool operator==(Polynomial& other);

		friend ostream &operator<<( ostream &out, Polynomial& myPoly);
};

	//default constructor, initializes all values to 0
Polynomial::Polynomial( ) {

	int i;

	for(i=0; i<100; i++){
		coeff[i] = 0;
		power[i] = 0;
	}
		//the purpose of this is to maintain a count of what position we are in
		//in each array to remove the need to run a loop
	count = 0;
}
//----------------

	//Increments the polynomial array by a given power and coeffecient
void Polynomial::incrementBy(int c, int p ) {

	coeff[count] = c;
	power[count] = p;

	count++;
}

	//Checks to see if two polynomials are equal
bool Polynomial::operator==( Polynomial& other) {

	int i;

	for(i=0; i < 100; i++){

		if(coeff[i] != other.coeff[i])
			return false;
		if(power[i] != other.power[i])
			return false;
	}

return true;
}

	//Overloaded cout operator
ostream &operator<<( ostream &out, Polynomial& myPoly) {

	int i;

	for( i=0; i <= myPoly.count; i++){
		out << myPoly.coeff[i] << "X" << "^" << myPoly.power[i] << "\t";
	}

return out;
}

//============================================================================//
//================================MAIN========================================//
//============================================================================//

int main( ) {

	Polynomial A, B;
	int cof, pow;
	cout << "Enter first " << endl;

	do {
		cout << "Enter pair (0,0 to finish) ";
		cin >> cof >> pow;
		A.incrementBy( cof, pow );
	} while ( !(cof==0 && pow==0) );

	cout << "Enter second " << endl;

	do {
		cout << "Enter pair (0,0 to finish) ";
		cin >> cof >> pow;
		B.incrementBy( cof, pow );
	} while ( !(cof==0 && pow==0) );

	cout << endl;
	cout << "A is " << A << endl;
	cout << "B is " << B << endl;
	cout << (A==B ? "Equal" : "Not equal" ) << endl;

	return 0;
}
