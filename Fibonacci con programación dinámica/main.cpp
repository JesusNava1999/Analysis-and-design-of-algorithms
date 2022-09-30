/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Fibonacci con programación dinámica
Nombre del archivo: main.cpp
*/

#include <iostream>
#include "Vector.h"
using namespace std;

long fibonacci(int,Vector*&);
int times=0;

int main(){
	int i=0;
	cout << "i = ";
	cin >> i;

	Vector* v1;
	v1 = new Vector(1);	
	v1->add(1,1);
	v1->add(2,1);

	cout << endl << "Resultado: " << fibonacci(i,v1) << endl;
	cout << "Se ejecuto " << times << " veces" << endl << endl;

	return EXIT_SUCCESS;
}

long fibonacci(int i, Vector*& v1){	
	times++;
	if((i==1)or(i==2)){					
		return 1;
	} else {		
		if(i==v1->getQuantity()+1){
			v1->add(i,v1->get(i-1) + v1->get(i-2));			
			return v1->get(i-1) + v1->get(i-2);			
		} else {	
			return fibonacci(i-1,v1) + fibonacci(i-2,v1);
		}			
	}		
} 
 