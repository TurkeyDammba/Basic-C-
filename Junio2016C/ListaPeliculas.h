#ifndef ListaPeliculas_h
#define ListaPeliculas_h

#include "Pelicula.h";

//ESTRCTURAS
const int MAXP = 50;
typedef tPelicula *tPeliPtr;//puntero a tipo tPelicula
typedef  tPeliPtr tListaPelis[MAXP]; //array de punteros a tPelicula
typedef struct {
	tListaPelis peliculas;
	int cont;
}tLista;

//PROTOTIPOS
void cargarLP(tLista &lista, string nombreArchivo);
tLista vacia();
tLista filtrarPorActor(const tLista &lista, string actor);
void mostarLP(const tLista &lista);
void ordenarGenero(tLista &lista);
void ordenarValoracion(tLista &lista);
void destruirLP(tLista &lista);
#endif