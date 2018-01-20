#ifndef ListaVentas_h
#define ListaVentas_h


#include "Venta.h";

//ESTRUTURAS
const int  MAXV = 300;
typedef struct {
	tVenta *listaVentas; //puntero a array de tVenta
	int cont;
}tListaVentas;

//PROTOTIPOS

void insertaVenta(tListaVentas &listaV, tVenta actual);
void muestraLV(const tListaVentas &listaV);
double totalVentas(const tListaVentas &listaV);
void destruye(tListaVentas &listaV);
#endif