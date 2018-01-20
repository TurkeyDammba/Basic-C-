#ifndef ListaDias_h
#define ListaDias_h


#include "ListaVentas.h";

//ESTRUCTURAS
typedef struct {
	string fecha;
	tListaVentas vendidos;
}tDia;

const int MAXD = 200;
typedef tDia *tDiaPtr; //puntero a tDia
typedef tDiaPtr tDiaPtrArray[MAXD];
typedef struct {
	tDiaPtrArray arrayDias;
	int cont;
}tListaDias;

//PROTOTIPOS

int encuentra(const tListaDias &listaD, string fecha,int ini, int fin);
double totalVentas(const tListaDias &listaD);
void insertaDia(tListaDias &listaD, string fecha, tVenta &venta);
void carga(tListaDias &listaD, string nArchivo, bool &ok);
void muestra(const tListaDias &listaD);
void destruye(tListaDias &listaD);
void inicializarlista(tListaDias &listaD);

#endif