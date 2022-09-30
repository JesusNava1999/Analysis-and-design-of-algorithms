/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: El Vector Dinámico
Nombre del archivo: main.cpp
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Vector.h"

using namespace std;

int main(){
	srand(time(NULL)*rand());
	int n=0;
	cin >> n;
	Vector* v1;
	v1 = new Vector(1);	

	for (int i=0; i<(4*n); i++){		
		int aux = rand() % 2;
		int num = ((rand() % (n*10)) + 1);	
		if(aux==1){			
			if(v1->full()){
				Vector v2(v1, v1->getSize()*2);
				delete v1;
				v1 = new Vector(&v2,v2.getSize());
				v1->push(num);			
				cout << "ins\t" << num << ":\t";	
				v1->printV();
			} else {
				v1->push(num);			
				cout << "ins\t" << num << ":\t";
				v1->printV();
			}					
		} else {
			int p;
			if(((v1->getQuantity()==0)and(v1->getSize()==1))or((v1->getQuantity()==0)and(v1->getSize()==2))){
				cout << "out\t" << 0 << ":\t";
				v1->printV();			
			} else {				
				if((v1->getQuantity()==v1->getSize()/4)or((v1->getQuantity()==1)and(v1->getSize()==2))){
					Vector v2(v1, v1->getSize()/2);
					delete v1;
					v1 = new Vector(&v2,v2.getSize());
					p = v1->pop();					
					cout << "out\t" << p << ":\t";
					v1->printV();
				} else {
					p = v1->pop();					
					cout << "out\t" << p << ":\t";
					v1->printV();
				}								
			}			
		}			
	}

	return EXIT_SUCCESS;
}
