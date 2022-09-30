#ifndef grafo_h
#define grafo_h

#include <stddef.h>
#include <string>
#include <set>
#include <map>

#include "tabla.h"
using namespace std;

class grafo {
	
	int n; // orden del grafo(numero de vertices)
	int m; //tamaño del grafo(numero de aristas)
	bool* a;//arreglo
	int f(int, int);
public:
	grafo(int,int);
	~grafo();
	
	void set(int, int);//poner
	void unset(int, int);//quitar
	bool edge(int, int);
	void print();
	
	void N(int,int,int&);
	void gE(int,int,tabla,int&);
	bool iC(int,int);
};
#endif // grafo_h
