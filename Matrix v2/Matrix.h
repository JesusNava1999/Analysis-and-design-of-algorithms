/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: El Algoritmo de Strassen
Nombre del archivo: Matrix.h
*/
#ifndef Matrix_h
#define Matrix_h

#include <stddef.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

class Matrix {  
    int columns, rows;
    int** matrix;
public:
    
    Matrix(int,int,int);
    Matrix(Matrix,int,int,int,int);
    ~Matrix();

    void redim();
    int read(int,int);
    void write(int,int,int);
    void printM();

    Matrix add(Matrix,Matrix); 
    Matrix rest(Matrix,Matrix); 

    Matrix Strassen(Matrix,Matrix);

    Matrix join(Matrix,Matrix,Matrix,Matrix);
    
    int getColumns();
    int getRows();  
};
#endif