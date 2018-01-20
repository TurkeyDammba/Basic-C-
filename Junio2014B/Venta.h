#ifndef Venta_h
#define Venta_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//ESTRUTURAS
typedef struct{
	int codigo;
	double precio;
	int unidades;
	string hora;
}tVenta;

//PROTOTIPOS
void muestra(const tVenta &venta);
double totalVenta(const tVenta &venta);



#endif
