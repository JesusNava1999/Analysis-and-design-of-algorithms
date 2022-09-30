/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Fibonacci con programación dinámica
Nombre del archivo: Vector.cpp
*/

#include "Vector.h"

using namespace std;

Vector::Vector(int x){
	data = new long[x];
	n = x;
	s = 0;
	for(int i=0; i<n; i++){
		data[i] = 0;
	}
}

Vector::~Vector(){

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
		if((data[i]>(10000)or(data[i]<=0))){
			cout << " ";
		} else {
			cout << data[i] << " ";
		}		
	}
	cout << " ]" << endl;
}

void Vector::add(int i, long f){
	if(full()){
		n = n*2;
		for(int i=s; i<n; i++){
			data[i] = 0;
		}
		data[i-1] = f;
		s++;
	} else {
		data[i-1] = f;
		s++;
	}	
}

long Vector::get(int i){
	return data[i-1];
}