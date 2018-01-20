#ifndef listaIngr_h
#define listaIngr_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//ESTRUCTURAS
const int MAX = 50;
typedef struct{
	string nombre;
	int calorias;
}tIngrediente;
typedef tIngrediente *tIngrPtr; // puntero a tIngrediente
typedef struct {
	tIngrPtr tArray[MAX];//array de punteros a tIngrediente
	int cont;
}tLista;
//PROTOTIPOS
void insertar(tLista &listaIngr);
void carga(tLista &listIngr, string nombreArchivo);
string selectIngred(const tLista &listIngr);
int buscar(const tLista &listIngr, string nombre,int ini, int fin);

#endif // !listaIngr_H
