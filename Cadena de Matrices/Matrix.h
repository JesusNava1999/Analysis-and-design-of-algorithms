/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Cadena de Matrices
Nombre del archivo: Matrix.h
*/
#ifndef Matrix_h
#define Matrix_h

#include <stdlib.h>
#include <iostream>

using namespace std;

class Matrix{
    int** matrix;
    int rows;
    int columns;
public:
    Matrix(int);

    int read(int,int);
    void write(int,int,int);    

    void printMatrix();
};
#endif