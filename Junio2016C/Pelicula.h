#ifndef Pelicula_h
#define Pelicula_h

#include "Reparto.h";

//ESTRUCTURAS
typedef struct{
	string titulo;
	string director;
	string genero;
	double valoracion;
	tReparto reparto;
}tPelicula;

//PROTOTITPOS
void cargar(tPelicula &pelicula, ifstream &archivo);
bool interviene(const tPelicula &pelicula, string actor);
void mostrar(const tPelicula &pelicula);
#endif