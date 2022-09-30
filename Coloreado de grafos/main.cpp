#include <iostream>
#include <string>
#include <stddef.h>
#include <map>
#include "grafo.h"
#include "tabla.h"
using namespace std;

int main(){	
	int aux = 0, mayor = 0;
	tabla t;
	int *v;	
	//t.print();
	
	map<int, string> color;
	
	color[4]="Azul";
	color[3]="Rojo";
	color[2]="Verde";
	color[1]="Amarillo";
	
	//t.setColor(color);
	
	grafo g(11,20);		
	
	g.set(1,2);
	g.set(1,5);
	g.set(2,3);
	g.set(2,4);
	g.set(2,5);
	g.set(3,4);
	g.set(3,7);
	g.set(4,5);
	g.set(4,6);
	g.set(4,7);
	g.set(5,6);
	g.set(5,8);
	g.set(5,9);
	g.set(6,7);
	g.set(6,9);
	g.set(6,10);
	g.set(7,11);
	g.set(8,9);
	g.set(9,10);
	g.set(10,11);	
	// g.print();
	cout << endl;
	
	for(int i = 1; i <= 11; i++){
		for(int j = 1; j <= 11; j++){
			g.N(i,j,aux);			
		}
		t.insertGrado(i,aux);
		aux = 0;
	}
	mayor = t.getGradoMayor();
	for(int i = 1; i <= 11; i++){
		for(int j = 1; j <= 11; j++){
			g.gE(i,j,t,aux);			
		}
		t.insertGradoError(i,aux,mayor);
		aux = 0;
	}
	
	t.insertColor(color);	
	
	v = t.setOrder();
	for(int i=0; i<=10; i++){
		//cout << " - " << v[i] << endl;
		for(int j = 11; j >= 1; j--){
			if(g.iC(v[i],j)){
				//cout << v[i] << " es vecino de " << j << endl;
				//t.orderColor(color,v[i],j);
			}
		}
	}
	
	
	
	
	cout << endl;
	t.print();
	return 0;	
}
	
