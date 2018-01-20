#ifndef ListaEstudiantes_h
#define ListaEstudiantes_h

//BIBLIOTECA A UTILIZAR
#include "Estudiante.h";

//ESTRUCTURA
const int MAXE = 10;
typedef struct {
	tEstudiante *estudiantes; // puntero a rray dinamico
	int cont;
}tListaEstudiantes;

//PROTOTIPOS
void cargar(ifstream &archivo, tListaEstudiantes &listaE);
bool buscar(const tListaEstudiantes &listaE,string nif);
void insertar(tListaEstudiantes &listaE, tEstudiante actual);
void mostrar(const tListaEstudiantes &listaE);
void destruir(tListaEstudiantes &listaE);
void ordenar(tListaEstudiantes &listaE);
#endif