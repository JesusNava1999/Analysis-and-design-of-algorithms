/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: El Vector Dinámico
Nombre del archivo: main.cpp
*/

#include <iostream>
#include <ctime>
#include "Vector.h"

using namespace std;

int main(){
	
	int n, fact, op, temp;
	Vector* v;
	srand((unsigned)time(NULL));
	v = new Vector(1);
	
	cout << "Type (n): ";
	cin >> n;	
	cout << endl;		
	
	for(int i=0; i<((4*n)); i++){	
		fact = (rand() % (10*n)) + 1; //random fact
		op = (rand() % 2) + 1; //random choose
		if((v->getSize()==2)and(v->getAmountOfData()==0)){
			delete v;
			v = new Vector(1);
		}
		if(op==1){					
			if(v->getSize()==v->getAmountOfData()){
				Vector aux(v->getSize());
				while(v->getAmountOfData()!=0){
					aux.push(v->lastFact());
					v->pop();
				}
				delete v;
				v = new Vector(aux.getSize()*2);
				while(aux.getAmountOfData()!=0){
					v->push(aux.lastFact());
					aux.pop();
				}
			}
			v->push(fact);
			cout << "ins " << fact << ":\t";
			v->printData();			
		} else if(op==2){
			temp = v->lastFact();
			if(v->getAmountOfData()==0){
				cout << "out 0:\t";
			} else if(v->getAmountOfData()==(v->getSize()/(4))){								
				Vector aux(v->getSize());
				while(v->getAmountOfData()!=0){
					aux.push(v->lastFact());
					v->pop();
				}
				delete v;
				v = new Vector(aux.getSize()/2);
				while(aux.getAmountOfData()!=0){
					v->push(aux.lastFact());
					aux.pop();
				}		
				v->pop();
				cout << "out " << temp << ":\t";	
			} else {
				v->pop();
				cout << "out " << temp << ":\t";	
			}	
			v->printData();
		}				
	}
	delete v;
	return 0;
}
