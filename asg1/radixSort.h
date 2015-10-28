//	Jeremy Wilder
//	Assignment 1
//	Incredibly massive yet simple file that performs a radixSort;
//	Part of the stringQueue class to make it easier to call and
//	Manipulate the data within

#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

#include "stringQueue.h"

void stringQueue::radixSort( ){

		// 26 arrays in total, one for each letter
	string A[capacity];	string B[capacity];	string C[capacity];
	string D[capacity];	string E[capacity];	string F[capacity];
	string G[capacity];	string H[capacity];	string I[capacity];
	string J[capacity];	string K[capacity];	string L[capacity];
	string M[capacity];	string N[capacity];	string O[capacity];
	string P[capacity];	string Q[capacity];	string R[capacity];
	string S[capacity];	string T[capacity];	string U[capacity];
	string V[capacity];	string W[capacity];	string X[capacity];
	string Y[capacity];	string Z[capacity];

		//Each queue gets its own counter; 
		//Used when ordering the final list
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,count;

	a = b = c = d = e = f = g = h = i = j = k = l = m = n =
	o = p = q = r = s = t = u = v = w = x = y = z = count = 0;

	int pos = this->pos;

//-------------------------------------------------------------------------

		//Sorting method - 
		//divide them up by letter; Store in individual queues

	for( count=0; count < this->capacity; count++){

		if( this->list[count][pos] == 'a'){
			A[a] = this->list[count];
			a++;
		}
		if( this->list[count][pos] == 'b'){
			B[b] = this->list[count];
			b++;
		}
		if( this->list[count][pos] == 'c'){
			C[c] = this->list[count];
			c++;
		}
		if( this->list[count][pos] == 'd'){
			D[d] = this->list[count];
			d++;
		}
		if( this->list[count][pos] == 'e'){
			E[e] = this->list[count];
			e++;
		}
		if( this->list[count][pos] == 'f'){
			F[f] = this->list[count];
			f++;
		}
		if( this->list[count][pos] == 'g'){
			G[g] = this->list[count];
			g++;
		}
		if( this->list[count][pos] == 'h'){
			H[h] = this->list[count];
			h++;
		}
		if( this->list[count][pos] == 'i'){
			I[i] = this->list[count];
			i++;
		}
		if( this->list[count][pos] == 'j'){
			J[j] = this->list[count];
			j++;
		}
		if( this->list[count][pos] == 'k'){
			K[k] = this->list[count];
			k++;
		}
		if( this->list[count][pos] == 'l'){
			L[l] = this->list[count];
			l++;
		}
		if( this->list[count][pos] == 'm'){
			M[m] = this->list[count];
			m++;
		}
		if( this->list[count][pos] == 'n'){
			N[n] = this->list[count];
			n++;
		}
		if( this->list[count][pos] == 'o'){
			O[o] = this->list[count];
			o++;
		}
		if( this->list[count][pos] == 'p'){
			P[p] = this->list[count];
			p++;
		}
		if( this->list[count][pos] == 'q'){
			Q[q] = this->list[count];
			q++;
		}
		if( this->list[count][pos] == 'r'){
			R[r] = this->list[count];
			r++;
		}
		if( this->list[count][pos] == 's'){
			S[s] = this->list[count];
			s++;
		}
		if( this->list[count][pos] == 't'){
			T[t] = this->list[count];
			t++;
		}
		if( this->list[count][pos] == 'u'){
			U[u] = this->list[count];
			u++;
		}
		if( this->list[count][pos] == 'v'){
			V[v] = this->list[count];
			v++;
		}
		if( this->list[count][pos] == 'w'){
			W[w] = this->list[count];
			w++;
		}
		if( this->list[count][pos] == 'x'){
			X[x] = this->list[count];
			x++;
		}
		if( this->list[count][pos] == 'y'){
			Y[y] = this->list[count];
			y++;
		}
		if( this->list[count][pos] == 'z'){
			Z[z] = this->list[count];
			z++;
		}
	}

//-----------------------------------------------------------------------

			//Compile them back into ONE ORDERED list

	int total = 0;

	if(total < this->capacity){

		for( count = 0; count < a; count++){
			this->list[total] = A[count];
			total++;
		}
		for( count = 0; count < b; count++){
			this->list[total] = B[count];
			total++;
		}
		for( count = 0; count < c; count++){
			this->list[total] = C[count];
			total++; 
		}
		for( count = 0; count < d; count++){
			this->list[total] = D[count];
			total++;
		}
		for( count = 0; count < e; count++){
			this->list[total] = E[count];
			total++;
		}
		for( count = 0; count < f; count++){
			this->list[total] = F[count];
			total++;
		}
		for( count = 0; count < g; count++){
			this->list[total] = G[count];
			total++;
		}
		for( count = 0; count < h; count++){
			this->list[total] = H[count];
			total++;
		}
		for( count = 0; count < i; count++){
			this->list[total] = I[count];
			total++;
		}
		for( count = 0; count < j; count++){
			this->list[total] = J[count];
			total++;
		}
		for( count = 0; count < k; count++){
			this->list[total] = K[count];
			total++;
		}
		for( count = 0; count < l; count++){
			this->list[total] = L[count];
			total++;
		}
		for( count = 0; count < m; count++){
			this->list[total] = M[count];
			total++;
		}
		for( count = 0; count < n; count++){
			this->list[total] = N[count];
			total++;
		}
		for( count = 0; count < o; count++){
			this->list[total] = O[count];
			total++;
		}
		for( count = 0; count < p; count++){
			this->list[total] = P[count];
			total++;
		}
		for( count = 0; count < q; count++){
			this->list[total] = Q[count];
			total++;
		}
		for( count = 0; count < r; count++){
			this->list[total] = R[count];
			total++;
		}
		for( count = 0; count < s; count++){
			this->list[total] = S[count];
			total++;
		}
		for( count = 0; count < t; count++){
			this->list[total] = T[count];
			total++;
		}
		for( count = 0; count < u; count++){
			this->list[total] = U[count];
			total++;
		}
		for( count = 0; count < v; count++){
			this->list[total] = V[count];
			total++; 
		}
		for( count = 0; count < w; count++){
			this->list[total] = W[count];
			total++; 
		}
		for( count = 0; count < x; count++){
			this->list[total] = X[count];
			total++; 
		}
		for( count = 0; count < y; count++){
			this->list[total] = Y[count];
			total++; 
		}
		for( count = 0; count < z; count++){
			this->list[total] = Z[count]; 
			total++;
		}
	}	
}
#endif
