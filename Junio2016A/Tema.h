#ifndef Tema_h
#define Tema_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//ESTRUCTURAS 
typedef struct {
	string titulo;
	string interprete;
	int seg;
}tTema;

//PROTOTIPOS

void cargar(tTema &actual);
void mostrar(const tTema &actual);

#endif