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
	int n; 
	int s; 
	int* data; 
public:
	Vector(int);
	Vector(Vector*,int);
	~Vector();
	
	void push(int);
	int pop();
	bool empty();
	bool full();

	int getQuantity();
	int getSize();

	void printV();	
};

#endif
