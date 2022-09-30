/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Fibonacci con programación dinámica
Nombre del archivo: Vector.h
*/

#ifndef Vector_h
#define Vector_h

#include "stddef.h"
#include <iostream>

class Vector{
	int n; 
	int s; 
	long* data; 
public:
	Vector(int);
	~Vector();
	
	bool empty();
	bool full();

	int getQuantity();
	int getSize();

	void printV();	

	void add(int,long);
	long get(int);
};

#endif
