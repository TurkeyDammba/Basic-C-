#ifndef ListaGrupos_h
#define ListaGrupos_h

//BIBLIOTECAS A UTILIZAR
#include "ListaEstudiantes.h";

//ESTRUCTURA
const int MAXG = 10;
typedef struct {
	string ident;
	tListaEstudiantes listaAl;
}tGrupo;

typedef tGrupo *tGrupoPtr;
typedef tGrupoPtr tListaPunteros[MAXG];

typedef struct {
	tListaPunteros listaP;
	int cont;
}tListaGrupos;

//PROTOTIPOS
void cargar(tListaGrupos &listaG, string nomArchivo, bool &ok);
void mostrar(const tListaGrupos &listaG);
string buscar(const tListaGrupos &listaG, string nif, int pos);
void destruir(tListaGrupos &listaG);


#endif