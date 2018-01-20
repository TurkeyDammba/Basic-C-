#ifndef ListaTemas_h
#define ListaTemas_h

#include "Tema.h";

//ESTRUCTURAS
const int MAXL = 50;

typedef tTema *temaPtr; // puntero a tTema
typedef temaPtr tArrayPtr[MAXL];//array punteros a tTema
typedef struct{
	tArrayPtr arrayTemas;
	int contador;
}tListaTemas;

//PROTOTIPOS
bool cargarL(tListaTemas &listaT);
void destruir(tListaTemas &listaT);
#endif