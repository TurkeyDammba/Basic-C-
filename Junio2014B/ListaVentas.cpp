#include "ListaVentas.h";
void insertaVenta(tListaVentas &listaV, tVenta actual){
	if (listaV.cont >= MAXV){
		cout << "ERROR LISTA LLENA LOKO\n";
	}
	else {
		listaV.listaVentas[listaV.cont] = actual;
	}
}
void muestraLV(const tListaVentas &listaV){
	for (int i = 0; i < listaV.cont; i++){
		muestra(listaV.listaVentas[i]);
	}
}
double totalVentas(const tListaVentas &listaV){
	double total = 0;
	for (int i = 0; i < listaV.cont; i++){
		total = total + totalVenta(listaV.listaVentas[i]);
	}
	return total;
}
void destruye(tListaVentas &listaV){
	delete[] listaV.listaVentas;
	listaV.cont = 0;
}
