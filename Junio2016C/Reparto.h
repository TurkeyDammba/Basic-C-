#ifndef Reparto_h
#define Reparto_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//ESTRUCTURA
const int MAXA = 10;
typedef string tActores[MAXA];
typedef struct {
	tActores actores;
	int cont;
}tReparto;

//SUBPROGRAMAS
void cargarR(tReparto &reparto, ifstream &archivo, int numActores);
bool aparece(const tReparto &reparto, string actor, int ini, int fin);
int buscar(const tReparto &reparto, string nombre);//dado un nombre devuelve pos
#endif