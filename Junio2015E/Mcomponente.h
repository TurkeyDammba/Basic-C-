#ifndef Mcomponente_h
#define Mcomponente_h

#include "listaIngr.h";

//ESTRUCTURA
typedef struct{
	tIngrPtr puntero;
	int gramos;
}tComponente;

//PROTOTIPOS

tComponente leeComponente(tLista &listaIngr);
void muestra(tComponente &actual);



#endif // !Mcomponente_h



