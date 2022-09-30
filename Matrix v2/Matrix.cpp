/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: El Algoritmo de Strassen
Nombre del archivo: Matrix.cpp
*/
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int x, int y, int max){
    srand((unsigned)time(NULL)*rand());
    columns = y;
    rows = x;
    matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    } 

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){              
            matrix[i][j] = (rand() % max);
        }
    }
}

Matrix::Matrix(Matrix src, int down, int adove, int left, int right){
   rows = adove - down;
   columns = right - left;
   int a=0, b=0;

    matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    } 

    for(int i = left; i < right; i++){  
        b=0;      
        for(int j = down; j < adove; j++){   
            matrix[a][b] = src.read(i,j);
            b++;
        }
        a++;
    }
} 

Matrix::~Matrix(){

}

void Matrix::redim(){
    int newSize, oldRows, oldColumns;
    if(((getColumns()!=pow(2,ceil(log2(getColumns())))) or ((getRows()!=getColumns())) or (getRows()!=pow(2,ceil(log2(getRows()))))) or (getRows()!=getColumns())){
        if(getColumns()>getRows()){
            newSize = pow(2,ceil(log2(getColumns())));
        } else {
            newSize = pow(2,ceil(log2(getRows())));
        }

        oldRows = getRows();
        oldColumns = getColumns();

        int** auxM;
        auxM = new int*[rows];
        for (int i = 0; i < rows; i++) {
            auxM[i] = new int[columns];
        }                   
        auxM = matrix;       
        
        matrix = new int*[newSize];
        for (int i = 0; i < newSize; i++) {
            matrix[i] = new int[newSize];
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){ 
                matrix[i][j] = auxM[i][j];
            }
        } 

        columns = newSize;
        rows = newSize;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){ 
                if((i >= oldRows) or (j >= oldColumns)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

int Matrix::read(int col, int row){
    return matrix[col][row];
}

void Matrix::write(int col, int row, int value){
    matrix[col][row] = value;
}

void Matrix::printM(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){          
            cout << read(i,j) << "\t";
        }
        cout << endl;
    }  
}

Matrix Matrix::add(Matrix a, Matrix b){
    if((a.getRows()==b.getRows())and(a.getColumns()==b.getColumns())){       
        Matrix MSuma(a.getColumns(), a.getRows(), 1);
        for(int i = 0; i < a.getRows(); i++){
            for(int j = 0; j < a.getColumns(); j++){  
                MSuma.write(i,j,(a.read(i,j) + b.read(i,j)));
            }
        }
        return MSuma;
    }
}

Matrix Matrix::rest(Matrix a, Matrix b){
   if((a.getRows()==b.getRows())and(a.getColumns()==b.getColumns())){       
        Matrix MRest(a.getColumns(), a.getRows(), 1);
        for(int i = 0; i < a.getRows(); i++){
            for(int j = 0; j < a.getColumns(); j++){  
                MRest.write(i,j,(a.read(i,j) - b.read(i,j)));
            }
        }
        return MRest;
    }   
}

Matrix Matrix::Strassen(Matrix a, Matrix b){         
    if(a.getColumns()>2){
        Matrix p1(a.getColumns()/2,a.getRows()/2,1);
        Matrix p2(a.getColumns()/2,a.getRows()/2,1);
        Matrix p3(a.getColumns()/2,a.getRows()/2,1);
        Matrix p4(a.getColumns()/2,a.getRows()/2,1);        
        Matrix p5(a.getColumns()/2,a.getRows()/2,1);
        Matrix p6(a.getColumns()/2,a.getRows()/2,1);
        Matrix p7(a.getColumns()/2,a.getRows()/2,1); 

        Matrix aux1(a.getColumns()/2,a.getRows()/2,1);
        Matrix aux2(a.getColumns()/2,a.getRows()/2,1);
        Matrix aux3(a.getColumns()/2,a.getRows()/2,1);
        
        Matrix A(a, 0, (a.getColumns()/2), 0, (a.getRows()/2));  
        Matrix B(a, (a.getColumns()/2), a.getColumns(), 0, (a.getRows()/2));
        Matrix C(a, 0, (a.getColumns()/2), (a.getRows()/2), a.getRows()); 
        Matrix D(a, (a.getColumns()/2), a.getColumns(), (a.getRows()/2), a.getRows());
        
        Matrix E(b, 0, (b.getColumns()/2), 0, (b.getRows()/2));     
        Matrix F(b, (b.getColumns()/2), b.getColumns(), 0, (b.getRows()/2));    
        Matrix G(b, 0, (b.getColumns()/2), (b.getRows()/2), b.getRows());     
        Matrix H(b, (b.getColumns()/2), b.getColumns(), (b.getRows()/2), b.getRows());
       
        
        p1 = Strassen(A, rest(F,H));
        p2 = Strassen(add(A,B),H);
        p3 = Strassen(add(C,D),E);
        p4 = Strassen(D,rest(G,E));
        p5 = Strassen(add(A,D),add(E,H));
        p6 = Strassen(rest(B,D),add(G,H));
        p7 = Strassen(rest(A,C),add(E,F));

        Matrix C_11((b.getColumns()/2),(b.getRows()/2),1);
        Matrix C_12((b.getColumns()/2),(b.getRows()/2),1);
        Matrix C_21((b.getColumns()/2),(b.getRows()/2),1);
        Matrix C_22((b.getColumns()/2),(b.getRows()/2),1);   
                
        Matrix X((b.getColumns()),(b.getRows()),1); 

        aux1 = add(p5,p4);
        aux2 = rest(aux1,p2);
        aux3 = add(aux2,p6);
        C_11 = aux3;

        C_12 = add(p1,p2);

        C_21 = add(p3,p4);

        aux1 = add(p1,p5);
        aux2 = rest(aux1,p3);
        aux3 = rest(aux2,p7);
        C_22 = aux3;

        X = X.join(C_11, C_12, C_21, C_22);

        return X;
    } else {
        Matrix C(2,2,1);
        int m1=0, m2=0, m3=0, m4=0, m5=0, m6=0, m7=0;

        m1 = (a.read(0,0)+a.read(1,1)) * (b.read(0,0)+b.read(1,1)); 
        m2 = (a.read(1,0)+a.read(1,1)) * (b.read(0,0));  
        m3 = (a.read(0,0)) * (b.read(0,1)-b.read(1,1)); 
        m4 = (a.read(1,1)) * (b.read(1,0)-b.read(0,0)); 
        m5 = (a.read(0,0)+a.read(0,1)) * (b.read(1,1)); 
        m6 = (a.read(1,0)-a.read(0,0)) * (b.read(0,0)+b.read(0,1));  
        m7 = (a.read(0,1)-a.read(1,1)) * (b.read(1,0)+b.read(1,1)); 

        C.write(0,0,(m1+m4-m5+m7));
        C.write(0,1,(m3+m5));
        C.write(1,0,(m2+m4));
        C.write(1,1,(m1-m2+m3+m6));    

        return C;
    }     
} 

Matrix Matrix::join(Matrix a, Matrix b, Matrix c, Matrix d){
    int op1=0, op2=0;
    Matrix X(a.getColumns()*2,a.getRows()*2,1);
    
    for(int i = 0; i < X.getRows()/2; i++){
        for(int j = 0; j < X.getColumns()/2; j++){ 
            X.write(i,j,a.read(op1,op2));             
            op2++;
        }
        op2 = 0;
        op1++;
    }
    op1=0;
    for(int i = 0; i < X.getRows()/2; i++){
        for(int j = X.getColumns()/2; j < X.getColumns(); j++){
            X.write(i,j,b.read(op1,op2));               
            op2++;
        }
        op2 = 0;
        op1++;
    }
    op1=0;
    for(int i = X.getColumns()/2; i < X.getColumns(); i++){
        for(int j = 0; j < X.getColumns()/2; j++){      
            X.write(i,j,c.read(op1,op2));          
            op2++;
        }
        op2 = 0;
        op1++;
    }
    op1=0;
    for(int i = X.getColumns()/2; i < X.getColumns(); i++){
        for(int j = X.getColumns()/2; j < X.getColumns(); j++){ 
            X.write(i,j,d.read(op1,op2));               
            op2++;
        }
        op2 = 0;
        op1++;
    }
    op1=0;
    return X;
}

int Matrix::getColumns(){
    return columns;
}

int Matrix::getRows(){
    return rows;
}
