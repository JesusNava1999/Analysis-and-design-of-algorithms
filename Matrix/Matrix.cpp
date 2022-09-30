#include "Matrix.h"

using namespace std;

Matrix::Matrix(int x, int y){
    srand((unsigned)time(NULL)*rand());
    columns = x;
    rows = y;
    matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }                 

    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){              
            matrix[i][j] = (rand() % 100) + 1;
        }
    }  
}

void Matrix::printM(){
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){          
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }  
}

int** Matrix::getMatrix(){
    return matrix;
}

int Matrix::getColumns(){
    return columns;
}

int Matrix::getRows(){
    return rows;
}

void Matrix::add(Matrix M1){
    cout << "Suma (M1 + M2)" << endl;
    int** auxM1;
    int** MSuma;
    auxM1 = new int*[M1.getRows()];    
    for (int i = 0; i < M1.getRows(); i++) {
        auxM1[i] = new int[M1.getColumns()];
    }

    MSuma = new int*[M1.getRows()];    
    for (int i = 0; i < M1.getRows(); i++) {
        MSuma[i] = new int[M1.getColumns()];
    } 
    
    auxM1 = M1.getMatrix();
    for(int i = 0; i < M1.getColumns(); i++){
        for(int j = 0; j < M1.getRows(); j++){  
            MSuma[i][j] = matrix[i][j] + auxM1[i][j];
        }
    }  
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){          
            cout << MSuma[i][j] << "\t";
        }
        cout << endl;
    } 
}

void Matrix::rest(Matrix M1){
    cout << "Resta (M1 - M2)" << endl;
    int** auxM1;
    int** MResta;
    auxM1 = new int*[M1.getRows()];    
    for (int i = 0; i < M1.getRows(); i++) {
        auxM1[i] = new int[M1.getColumns()];
    }

    MResta = new int*[M1.getRows()];    
    for (int i = 0; i < M1.getRows(); i++) {
        MResta[i] = new int[M1.getColumns()];
    } 
    
    auxM1 = M1.getMatrix();
    for(int i = 0; i < M1.getColumns(); i++){
        for(int j = 0; j < M1.getRows(); j++){  
            MResta[i][j] = matrix[i][j] - auxM1[i][j];
        }
    }  
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){          
            cout << MResta[i][j] << "\t";
        }
        cout << endl;
    } 
}

void Matrix::mult(Matrix M1){
    cout << "Multiplicacion (M1 * M2)" << endl;
    int** auxM1;
    int** MMult;
    auxM1 = new int*[M1.getRows()];    
    for (int i = 0; i < M1.getRows(); i++) {
        auxM1[i] = new int[M1.getColumns()];
    }

    MMult = new int*[M1.getRows()];    
    for (int i = 0; i < M1.getRows(); i++) {
        MMult[i] = new int[M1.getColumns()];
    } 

    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){          
            MMult[i][j] = 0;
        }
    }
    
    auxM1 = M1.getMatrix();
    for(int i = 0; i < M1.getColumns(); i++){
        for(int j = 0; j < M1.getRows(); j++){            
            // cout << "---(" << j << " - " << i << ")---" << endl;
            for(int k = 0; k < M1.getColumns(); k++){               
                for(int l = 0; l < M1.getRows(); l++){
                    if(j==k){
                        // cout << k << " " << l << " - " << l << " " << i << endl;
                        MMult[j][i] = MMult[j][i] + (matrix[k][l] * auxM1[l][i]);
                    }                                        
                }
            }            
        }
    }     
    
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){          
            cout << MMult[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix::mult(Matrix M1){
    cout << "Multiplicacion (M1 * M2)" << endl;
    int** auxM1;
    int** MMult;
    auxM1 = new int*[M1.getRows()];    
    for (int i = 0; i < M1.getRows(); i++) {
        auxM1[i] = new int[M1.getColumns()];
    }

    MMult = new int*[M1.getRows()];    
    for (int i = 0; i < M1.getRows(); i++) {
        MMult[i] = new int[M1.getColumns()];
    } 

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){          
            MMult[i][j] = 0;
        }
    }
    
    auxM1 = M1.getMatrix();
    for(int i = 0; i < M1.getRows(); i++){
        for(int j = 0; j < M1.getColumns(); j++){            
            // cout << "---(" << j << " - " << i << ")---" << endl;
            for(int k = 0; k < M1.getRows(); k++){               
                for(int l = 0; l < M1.getColumns(); l++){
                    if(j==k){
                        // cout << k << " " << l << " - " << l << " " << i << endl;
                        MMult[j][i] = MMult[j][i] + (matrix[k][l] * auxM1[l][i]);
                    }                                        
                }
            }            
        }
    }     
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){          
            cout << MMult[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix::redim(){
    int newSize;
    if((getColumns()!=pow(2,ceil(log2(getColumns())))) or (getRows()!=pow(2,ceil(log2(getRows()))))){
        if(getColumns()>getRows()){
            newSize = pow(2,ceil(log2(getColumns())));
        } else {
            newSize = pow(2,ceil(log2(getRows())));
        }

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

        for(int i = 0; i < columns; i++){
            for(int j = 0; j < rows; j++){ 
                matrix[i][j] = auxM[i][j];
            }
        }  
        columns = newSize;
        rows = newSize;
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < rows; j++){ 
                if((matrix[i][j] < 0) or (matrix[i][j] > 101)){
                    matrix[i][j] = 0;
                }
            }
        }            
    }
}
