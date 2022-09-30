/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: El Vector Dinámico
Nombre del archivo: Vector.h
*/

#ifndef Vector_h
#define Vector_h

#include "stddef.h"
#include <iostream>

class Vector{
	int n; // max size
	int s; // amount of data
	int* data; // vector's data
public:
	Vector(int);
	~Vector();
	
	void push(int);
	void pop();
	bool empty(); //
	int getAmountOfData();
	int getSize();
	void printData();
	
	int lastFact();	
	
};

#endif
