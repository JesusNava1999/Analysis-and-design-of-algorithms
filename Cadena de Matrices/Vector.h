/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Cadena de Matrices
Nombre del archivo: Vector.h
*/
#ifndef Vector_h
#define Vector_h

#include <stddef.h>
#include "Matrix.h"

class Vector {
    int* vector;
    int n;
    Matrix* m;
    Matrix* s;
    int result;

public:
    Vector(int);

    int getSize();
    int getValue(int);
    void printVector();
    
    long double factorial(int);
    long double catalan(int);

    void matrix_Chain_Order();
    void optimal_Parens(int,int);
    int getResult();
};
#endif