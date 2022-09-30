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
    
    Matrix(int,int);
    void printM();
    int** getMatrix();
    int getColumns();
    int getRows();
    
    void add(Matrix);
    void rest(Matrix);
    void mult(Matrix);
    void redim();
};
#endif