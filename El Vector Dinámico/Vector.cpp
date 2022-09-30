/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: El Vector Dinámico
Nombre del archivo: Vector.cpp
*/

#include "Vector.h"

using namespace std;

Vector::Vector(int x){
	n = x;
	s = 0;
	data = new int[n];
}

Vector::~Vector(){
	delete [] data;
}

void Vector::push(int x){
	data[s] = x;	
	s++;
}

void Vector::pop(){
	data[s--] = '\0';
}

bool Vector::empty(){
	if(s==0){
		return true;
	} else {
		return false;
	}
}

int Vector::getAmountOfData(){
	return s;
}

int Vector::getSize(){
	return n;
}

void Vector::printData(){
	cout << "[\t";
	for(int i=0; i<n; i++){
		if( (data[i]<(10*n)) and (data[i]!='\0') and (s!=0) ){
			cout << data[i] << "\t";
		} else {
			cout << "\t";
		}
	}
	cout << "]" << endl;	
}

int Vector::lastFact(){
	int aux;
	s--;
	aux = data[s];	
	s++;
	return aux;
}
