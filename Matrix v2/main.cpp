/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: El Algoritmo de Strassen
Nombre del archivo: main.cpp
*/
#include "Matrix.h"

#include <iostream>

using namespace std;

int main(){
    int a, b, c, s;
    cin >> a >> b >> c;
    s = a * c;

    Matrix A(a,b,s);
    cout << "\nMatriz A:" << endl;
    A.printM();
    cout << endl;

    Matrix B(b,c,s);
    cout << "Matriz B:" << endl;
    B.printM();
    cout << endl;      

    A.redim();
    cout << endl << "Redimensionamiento de A:" << endl;
    A.printM();

    B.redim();   
    cout << endl << "Redimensionamiento de B:" << endl;
    B.printM(); 

    cout << endl << "Producto" << endl; 
    Matrix C(A.getColumns(),A.getRows(),1);
    C = C.Strassen(A,B);
    C.printM();

    return EXIT_SUCCESS;
}