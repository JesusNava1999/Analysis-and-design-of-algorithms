/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: El Vector Dinámico
Nombre del archivo: Vector.cpp
*/

#include "Vector.h"

using namespace std;

Vector::Vector(int x){
	data = new int[x];
	n = x;
	s = 0;
	for(int i=0; i<n; i++){
		data[i] = 0;
	}
}

Vector::Vector(Vector* a, int x){
	data = new int[x];
	n = x;
	s = a->getQuantity();
	for (int i=(a->s-1); i>=0; i--){
		data[i] = a->pop();
	}
}

Vector::~Vector(){

}

void Vector::push(int x){
	data[s] = x;
	s++;
}

int Vector::pop(){	
	int aux = data[s-1]; 
	data[s-1] = 0;
	s--;
	return aux;
}

bool Vector::empty(){
	return (s==0) ? true : false;
}

bool Vector::full(){
	return (s==n) ? true : false;
}

int Vector::getQuantity(){
	return s;
}

int Vector::getSize(){
	return n;
}

void Vector::printV(){
	cout << "[ ";
	for (int i=0; i<n; i++){
		if((data[i]>(1000)or(data[i]<=0))){
			cout << " ";
		} else {
			cout << data[i] << " ";
		}		
	}
	cout << " ]" << endl;
}
