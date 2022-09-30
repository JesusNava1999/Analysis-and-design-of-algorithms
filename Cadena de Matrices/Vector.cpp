/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Cadena de Matrices
Nombre del archivo: Vector.h
*/
#include "Vector.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

Vector::Vector(int x){   
    result = 0; 
    n = x;
    srand((unsigned)time(NULL)*rand());
    vector = new int[n+1];
   /*  for(int i=0; i<=n; i++){
        vector[i] = (rand() % 10) + 1;
    }   */
    vector[0]=2;
    vector[1]=3;
    vector[2]=8;
    vector[3]=10;
    vector[4]=5;
    vector[5]=6;
    m = new Matrix(getSize());
    s = new Matrix(getSize());
}

int Vector::getSize(){
    return n;
}

int Vector::getValue(int x){
    return vector[x];
}

void Vector::printVector(){
    cout << "<  ";
    for(int i=0; i<=n; i++){
        cout << vector[i] << "  ";
    }
    cout << ">\n";
}


long double Vector::factorial(int f){
    long double fac = 1;
    for(int i = 1; i<=f; i++){
        fac *= i;
    }
    return fac;
}

long double Vector::catalan(int c){
    long double aux=0;
    aux = (long double)(factorial((2*c)-2)) / (long double)((factorial(c))*(factorial(c-1)));
    return aux;
}

void Vector::matrix_Chain_Order(){
    int j = 0, q = 0;
    for(int i = 1; i<=n; i++){
        m->write(i,i,0);
    }
    cout << endl;
    for(int length = 2; length<=n; length++){
        for(int i=1; i<=(n - length + 1); i++){
            j = (i + length - 1);
            m->write(i,j,10000000);
            for(int k = i; k <=(j-1); k++){
                q = m->read(i,k) + m->read(k+1,j) + (getValue(i-1)*getValue(k)*getValue(j));
                if(q < m->read(i,j)){
                    m->write(i,j,q);
                    s->write(i,j,k);
                }
            }
        }
    }
} 

void Vector::optimal_Parens(int i, int j){    
    if(i==j){                     
        cout << "A_" << i;          
    } else {         
        cout << "(";            
        optimal_Parens(i,s->read(i,j));                
        optimal_Parens(s->read(i,j)+1,j);
        cout << ")";
    }
}


int Vector::getResult(){
    result = m->read(1,n);
    return result;
}