#include "Matrix.h"

#include <iostream>

using namespace std;

int main(){
    Matrix m1(2,2);
    cout << "M1" << endl;
    m1.printM();
    cout << endl;

    Matrix m2(2,2);
    cout << "M2" << endl;
    m2.printM();
    cout << endl;

    m1.add(m2);    
    cout << endl;

    m1.rest(m2);
    cout << endl;

    m1.mult(m2);
    cout << endl;

    m1.redim();
    cout << endl << "Redimensioned M1: " << endl;
    m1.printM();

    m2.redim();   
    cout << endl << "Redimensioned M2: " << endl;
    m2.printM();

    return EXIT_SUCCESS;
}