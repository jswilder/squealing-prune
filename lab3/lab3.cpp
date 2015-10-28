//Jeremy Wilder
//Lab 3 


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Recursion {

public:
Recursion(string filename);
int array[10][10];
int CrapArray[10][10];
void print( );
void printGroupWith();
void check(int i,int j);

private:
};

//Recursive Function
void Recursion::check(int i,int j){

int x = 0;

if( array[i+1][j] == 1 && CrapArray[i+1][j] != 0 ){
CrapArray[i+1][j] = 0;
//WOOOOO!!!! RECURSION!!
check(i+1,j);
x++;
cout<< "(" << i+1 << "," << j << ")";

}

if( array[i-1][j] == 1 && CrapArray[i-1][j] != 0 ){
CrapArray[i-1][j] = 0;
//WOOOOO!!!! RECURSION!!
check(i-1,j);
x++;
cout<< "(" << i-1 << "," << j << ")";

}

if( array[i][j+1] == 1 && CrapArray[i][j+1] != 0 ){
CrapArray[i][j+1] = 0;
//WOOOOO!!!! RECURSION!!
check(i,j+1);
x++;
cout<< "(" << i << "," << j+1 << ")";

}

if( array[i][j-1] == 1 && CrapArray[i][j-1] != 0 ){
CrapArray[i][j-1] = 0;
//WOOOOO!!!! RECURSION!!
check(i,j-1);
x++;
cout<< "(" << i << "," << j-1 << ")";

}

//Insures that it is touched
if(x > 0 && CrapArray[i][j] != 0){
cout<< "(" << i << "," << j << ")";
CrapArray[i][j] = 0;
}
}

Recursion::Recursion(string filename){

char c;
int i, j;

ifstream infile;
infile.open( filename.c_str() );

if( ! infile ) {

cout << "could not open file" << filename << endl;
return;
}

for(i =0; i < 10; i++ )
for(j =0; j < 10; j++ ) {

infile >> c;
//Copies values directly into both arrays
if( c == '.'){
array[i][j] = 0;
CrapArray[i][j] = 0;
}
if( c == 'X'){
array[i][j] = 1;
CrapArray[i][j] = 1;
}
}

infile.close( );

//Test Printer
cout << "\nBefore groups are removed\n";

for(i =0; i < 10; i++ ){
cout << "row" << i << " -- ";
for(j =0; j < 10; j++ ) {

cout << array[i][j];
}
cout << endl;
}
cout << "\n";
}

void Recursion::printGroupWith( ){

int i, j;

int x = 1;

for(i =0; i < 10; i++ )
for(j =0; j < 10; j++ ) {


if( array[i][j] == 1 && CrapArray[i][j] != 0 ) {

cout<< "group" << x << ": ";
check( i, j );
x++;
cout<<endl;
}
}

cout<< "\nAfter groups are removed\n";
for(i =0; i < 10; i++ ){
cout << "row" << i << " -- ";
for(j =0; j < 10; j++ ) {

cout << CrapArray[i][j];
}
cout <<endl;
}

}

//------------------------------------------------------------------------------
//-------------------------------------MAIN-------------------------------------
//------------------------------------------------------------------------------

int main ( int argc, char *argv[] ) {

string filename (argv[1]);
Recursion *recur = new Recursion(filename);

recur->printGroupWith();

return 0;
}
