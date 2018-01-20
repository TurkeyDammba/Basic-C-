#ifndef Mreceta_h
#define Mreceta_h

#include "Mcomponente.h";

//ESTRUCTURAS
const int MAXC = 20;
typedef struct {
	tComponente *componentes;//puntero a array de componentes
	int cont;
	int cap;
}tListaRecetas;

//PROTOTIPOS

tListaRecetas crea();

void insertarC(tListaRecetas &listaR,tComponente comp);

void muestraC(const tListaRecetas &listaR);

void destruirMEM(tListaRecetas &listaR, tLista &listaIngr);
#endif