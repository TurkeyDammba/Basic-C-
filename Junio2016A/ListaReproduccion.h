#ifndef ListaReproduccion_h
#define ListaReproduccion_h

#include "ListaTemas.h";

//ESTRUCTURAS

typedef struct {
	temaPtr puntero;
	int valoracion;
}tElemento;

typedef struct {
	tElemento *arrayD; //puntero a array
	string nombre;
	int cont;
	int cap;
}tListaRep;

//PROTOTIPOS
tListaRep nueva(string nombre, int cap);

void insertar(tListaRep &listaR, tElemento elemento);

bool buscar(const tListaRep &listaR, string titulo, int pos);

void mostrarL(const tListaRep &listaR);

void modificarOrden(tListaRep &listaR, int org, int dest);

void creaListaRep(tListaRep & listaR,const tListaTemas &listaT);

void destruir(tListaRep &lista);
#endif
