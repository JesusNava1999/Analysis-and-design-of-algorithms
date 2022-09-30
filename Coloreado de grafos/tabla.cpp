#include <iostream>
#include "tabla.h"
#include "grafo.h"
using namespace std;
tabla::tabla(){	
	list[1]="WA";
	list[2]="OR";
	list[3]="CA";
	list[4]="NV";
	list[5]="ID";
	list[6]="UT";
	list[7]="AZ";
	list[8]="MT";
	list[9]="WY";
	list[10]="CO";
	list[11]="NM";
}

void tabla::print(){
	/*for (map<int, grado>::iterator it=gE.begin(); it!=gE.end(); ++it){
		for (map<int, nodo>::iterator it_1=it->second.begin(); it_1!=it->second.end(); ++it_1){		
			for (map<int, string>::iterator it_2=it_1->second.begin(); it_2!=it_1->second.end(); ++it_2){	
				cout << it->first << " " << it_1->first << " " << it_2->first << " " << it_2->second << endl;
			}	
		}
	}*/
	for (auto it = k.crbegin(); it != k.crend(); ++it){
		for (auto it_1 = gE.crbegin(); it_1 != gE.crend(); ++it_1){
			for (auto it_2 = it_1->second.crbegin(); it_2 != it_1->second.crend(); ++it_2){
				for (auto it_3 = it_2->second.crbegin(); it_3 != it_2->second.crend(); ++it_3){	
					cout << it->first << " " << it_1->first << " " << it_2->first << " " << it_3->first << " " << it_3->second << endl;
				}					
			}			
		}
	}
}

void tabla::insertGrado(int x, int y){
	for (map<int, string>::iterator it=list.begin(); it!=list.end(); ++it){			
		if(x==it->first){
			d[y][it->first]=it->second;
		}		
	}	
}	

void tabla::insertGradoError(int x, int y, int mayor){	
	for (map<int, nodo>::iterator it=d.begin(); it!=d.end(); ++it){
		for (map<int, string>::iterator it_1=it->second.begin(); it_1!=it->second.end(); ++it_1){					
			if(x==it_1->first){	
				if(it->first==mayor){
					gE[mayor+3][it->first][it_1->first]=it_1->second;
				} else {				
					gE[y][it->first][it_1->first]=it_1->second;
				}
			}				
		}
	}	
}

void tabla::getGradoError(int x, int y, int &aux){
	int auxGradoP=0;
	string auxNodoP="";
	for (map<int, nodo>::iterator it=d.begin(); it!=d.end(); ++it){
		for (map<int, string>::iterator it_1=it->second.begin(); it_1!=it->second.end(); ++it_1){		
			if(x==it_1->first){
				auxGradoP = it->first;
				auxNodoP = it_1->second;
			}	
		}	
	}	
	for (map<int, nodo>::iterator it=d.begin(); it!=d.end(); ++it){
		for (map<int, string>::iterator it_1=it->second.begin(); it_1!=it->second.end(); ++it_1){		
			if(y==it_1->first){
				if((it->first>=auxGradoP)and(auxGradoP!=0)){
					aux++;
				}
			}	
		}	
	}
}
int tabla::getGradoMayor(){
	int mayor=0;
	for (map<int, nodo>::iterator it=d.begin(); it!=d.end(); ++it){
		for (map<int, string>::iterator it_1=it->second.begin(); it_1!=it->second.end(); ++it_1){				
			if(mayor<it->first){
				mayor = it->first;
			}
		}	
	}
	return mayor;
}

int tabla::getGradoEMayor(){
	int mayor=0;
	for (map<int, grado>::iterator x=gE.begin(); x!=gE.end(); ++x){
		for (map<int, nodo>::iterator it=d.begin(); it!=d.end(); ++it){
			for (map<int, string>::iterator it_1=it->second.begin(); it_1!=it->second.end(); ++it_1){				
				if(mayor<x->first){
					mayor = x->first;
				}
			}	
		}
	}
	return mayor;
}

int tabla::getGradoEMenor(){
	int menor=0;
	for (map<int, grado>::iterator x=gE.begin(); x!=gE.end(); ++x){
		for (map<int, nodo>::iterator it=d.begin(); it!=d.end(); ++it){
			for (map<int, string>::iterator it_1=it->second.begin(); it_1!=it->second.end(); ++it_1){				
				if(menor>x->first){
					menor = x->first;
				}
			}	
		}
	}
	return menor;
}

void tabla::insertColor(map<int, string> c){	
	auto a = c.crbegin();
	for (auto it_1 = gE.crbegin(); it_1 != gE.crend(); ++it_1){
		for (auto it_2 = it_1->second.crbegin(); it_2 != it_1->second.crend(); ++it_2){
			for (auto it_3 = it_2->second.crbegin(); it_3 != it_2->second.crend(); ++it_3){	
				if(it_1->first==getGradoEMayor()){
					// cout << it_1->first << " " << getGradoEMayor() << endl;
					k[a->second][it_1->first][it_2->first][it_3->first]=it_3->second;						
				}				
			}					
		}			
	}	
}

void tabla::orderColor(map<int, string> c, int x, int vecino){
	auto a = c.crbegin();
	string auxColor="";
	for (auto it = k.crbegin(); it != k.crend(); ++it){
		for (auto it_1 = gE.crbegin(); it_1 != gE.crend(); ++it_1){
			for (auto it_2 = it_1->second.crbegin(); it_2 != it_1->second.crend(); ++it_2){
				for (auto it_3 = it_2->second.crbegin(); it_3 != it_2->second.crend(); ++it_3){	
					// cout << it->first << " " << it_1->first << " " << it_2->first << " " << it_3->first << " " << it_3->second << endl;
					if(it_3->first==x){
						auxColor=it->first;
					}
				}					
			}			
		}
	}
	// cout << "C " << auxColor << endl; 
	for (auto it = k.crbegin(); it != k.crend(); ++it){
		for (auto it_1 = gE.crbegin(); it_1 != gE.crend(); ++it_1){
			for (auto it_2 = it_1->second.crbegin(); it_2 != it_1->second.crend(); ++it_2){
				for (auto it_3 = it_2->second.crbegin(); it_3 != it_2->second.crend(); ++it_3){	
					if((it_3->first==vecino)and(auxColor==it->first)){
						a--;
						k[a->second][it_1->first][it_2->first][it_3->first]=it_3->second;							
					}
					// cout << it->first << " " << it_1->first << " " << it_2->first << " " << it_3->first << " " << it_3->second << endl;
				}					
			}			
		}
	}
}

int* tabla::setOrder(){
	int *v;
	v = new int[11];
	int id=0;
	for (auto it_1 = gE.crbegin(); it_1 != gE.crend(); ++it_1){
		for (auto it_2 = it_1->second.crbegin(); it_2 != it_1->second.crend(); ++it_2){
			for (auto it_3 = it_2->second.crbegin(); it_3 != it_2->second.crend(); ++it_3){	
				v[id]=it_3->first;
				id++;
			}					
		}			
	}
	return v;
}


