#include "Venta.h";


void muestra(const tVenta &venta){
	cout << venta.hora << ":   " << venta.codigo << "  " << venta.unidades <<
		" x   " <<venta.precio << "$ =    " << totalVenta(venta) << endl;
}

double totalVenta(const tVenta &venta){
	return venta.precio*venta.unidades;
}