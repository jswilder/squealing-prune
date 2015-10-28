// Jeremy Wilder
// Assignment 4

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

class pixel{

	private:

	public:
	int r,g,b;
};


bool check( int a[40][40], int x, int y ){

	if( a[x+1][y] == 0 && a[x-1][y] == 0 && a[x][y+1] == 0 && a[x][y-1] == 0 ){

		return true;
	} 

return false;
}

bool probability( float p ){

	if( ( rand() % 100 ) < ( p * 100 ) );
		return true;

return false;
}

int main(){

	int MAXVAL = 255;
	int BLOCK_SIZE = 20;

	int r,c,x,y;
	int I_set[40][40];

	for( r=0; r<40; r++)
		for( c=0; c<40; c++){

			I_set[r][c] = 0;
		}

		// Probability // Evolutions
	float p;
	int e;;

	cout << "How many evolutions would you like to perform?" << endl;
	cin >> e;

	cout << "What probability would you like to use? Between 0 and 1, ex: .5 ";
	cout << endl;
	cin >> p;

/*-------------*/

		//Picks random numbers between 0-40, checks corresponding cells
			//Then calculates a probabilty of it being filled
	for(int z=0; z< e; z++){

		x = rand() % 40;
		y = rand() % 40;

		if( check( I_set, x, y ) ){

			if( (( x + y ) % 2) == 0){

				if( probability ( p ) ){
					I_set[x][y] = 2;
				}
			}
			if( (( x + y ) % 2) != 0){

				if( probability ( p ) ){
					I_set[x][y] = 1;
				}
			}
		}
	}
/*-------------*/

//	test printer // cout

	for( x=0; x<40; x++){
		for( y=0; y<40; y++){

		cout<< I_set[x][y];
		}
	cout << endl;
	}

	cout << endl << "Above is a numerical representation of the ppm image. 1's\n";
	cout << "for red, 2's for blue, 0's for white." << endl;

	cout << endl << "Open image in img.ppm " << endl << endl;

/*-------------*/

    FILE *file = NULL;
    file = fopen("img.ppm", "w");

	fprintf(file,"P6\n");
	fprintf(file,"%d %d %d\n", 40, 40, MAXVAL);

	for( r=0; r < 40 ; r++){
		for( c=0; c < 40 ; c++){

			if( I_set[r][c] == 2 ){
				//print blue
				fprintf(file,"%c%c%c",0,0,255);
			}
			if( I_set[r][c] == 1 ){
				//print red
				fprintf(file,"%c%c%c",255,0,0);
			}
				//print white
			else{
				fprintf(file,"%c%c%c",255,255,255);
			}
		}
	}

    fclose(file);

/*-------------*/
return 0;
}

