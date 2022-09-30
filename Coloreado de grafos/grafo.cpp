#include <iostream>
#include "grafo.h"
#include "tabla.h"
using namespace std;
int grafo::f(int i,int j){
	if (i < j) {
		int k = i;
		i = j;
		j = k;
	}
	return (i-1)*(i-2)/2+j-1;
}
grafo::grafo(int order, int edges):n(order),m((n*(n-1)/2)){
	a = new bool[m];
	for (int i=0; i<m; i++) a[i] = false;
}

grafo::~grafo(){delete[] a;}

void grafo::set(int i, int j){
	if (i!=j && i<=n && j<=n) a[f(i, j)] = true;
}

void grafo::unset(int i, int j) {
	if (i!=j && i<=n && j<=n) a[f(i, j)] = false;
}

bool grafo::edge(int i, int j) {
	return (i!=j && i<=n && j<=n) ? a[f(i,j)] : false;
}

void grafo::print() {
	for (int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){
			if(i==j){
				cout << " " << false;
			} else{
				cout << " " << a[f(i,j)];	
			}			
		}	
		cout << endl;	
	}
	
}

void grafo::N(int x, int y, int &aux){
	bool *b = a;
	if ((b[f(x,y)]==true)and(x!=y)){	
		aux++;		
	} 		
}
void grafo::gE(int x, int y, tabla t, int &aux){
	bool *b = a;	
	if ((b[f(x,y)]==true)and(x!=y)){	
	aux++;
	} 	
	if ((b[f(x,y)]==true)and(x!=y)){			
		t.getGradoError(x,y,aux);		
	} 	
}
bool grafo::iC(int x, int y){
	bool *b = a;
	if ((b[f(x,y)]==true)and(x!=y)){	
		return true;
	} else {
		return false;
	}
}

