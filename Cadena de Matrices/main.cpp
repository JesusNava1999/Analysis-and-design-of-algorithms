/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Cadena de Matrices
Nombre del archivo: main.cpp
*/
#include "Vector.h"

#include <iostream>

using namespace std;

int main(){
    int n = 0;
    cout << "Type n: ";
    cin >> n;
    Vector v(n);
    cout << "\nDim vector: "; 
    v.printVector();
    cout << "Number of solutions: " << v.catalan(n) << endl; 
    v.matrix_Chain_Order(); 
    cout << "Optimal parenthesizing: " << endl;
    v.optimal_Parens(1,n);
    cout << endl << endl << "Cost of the solution: " << v.getResult() << endl << endl;
    return EXIT_SUCCESS;
}
