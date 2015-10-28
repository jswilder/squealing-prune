// checkered.cpp
// prints out image that is RW  for R=Red, W=White
//                          WG     and G=Green

#include <iostream>
#include <fstream>
using namespace std;

int main( ) {

	const int MAXVAL = 255;
	const int BLOCK_SIZE = 100;
	int r,c,x,y;


	printf("P6\n");
	printf("%d %d %d\n", 10*BLOCK_SIZE, 10*BLOCK_SIZE, MAXVAL);

	for(x=0; x<10; x++){
		for(y=0; y<10; y++){

			for(r=0; r<BLOCK_SIZE; r++) {
				for(c=0; c<BLOCK_SIZE; c++)
				printf("%c%c%c", MAXVAL, 0, 0);
				for(c=0; c<BLOCK_SIZE; c++)
				printf("%c%c%c", MAXVAL, MAXVAL, MAXVAL);
			}
			for(r=0; r<BLOCK_SIZE; r++) {
				for(c=0; c<BLOCK_SIZE; c++)
				printf("%c%c%c", MAXVAL, MAXVAL, MAXVAL);
				for(c=0; c<BLOCK_SIZE; c++)
				printf("%c%c%c", 0, 0, MAXVAL);
			}
		}
	}

/*
	for(r=0; r<BLOCK_SIZE; r++) {
		for(c=0; c<BLOCK_SIZE; c++)
		printf("%c%c%c", MAXVAL, MAXVAL, MAXVAL);
		for(c=0; c<BLOCK_SIZE; c++)
		printf("%c%c%c", 0, 0, MAXVAL);
	}
*/
return 0;
}
