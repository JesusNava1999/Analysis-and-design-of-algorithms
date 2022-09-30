#ifndef tabla_h
#define tabla_h

#include <stddef.h>
#include <string>
#include <set>
#include <map>

using namespace std;

class tabla {
	
	typedef map<int, string> nodo;
	typedef map<int, nodo> grado;
	typedef map<int, grado> gradoError;
	typedef map<string, gradoError> color;	
	
	nodo list;
	grado d;
	gradoError gE;		
	color k;
	
	
	
public:
	tabla();
	
	void print();
	void insertGradoError(int,int,int);
	void insertGrado(int,int);
	void getGradoError(int,int,int&);
	void insertColor(map<int, string>);
	int* setOrder();
	void orderColor(map<int, string>,int,int);
	int getGradoMayor();
	int getGradoEMayor();
	int getGradoEMenor();
	
};
#endif
