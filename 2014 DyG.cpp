#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NP = 5;

/*typedef enum {
	papeleria, alimentacion, limpieza, informatica
}tTipo;*/
typedef struct {
	string cif;
	string clase;
	int pedidos;
	double gasto;
}tproveedor ;
typedef tproveedor tArrayProv[NP];

int menu();
void leerFichero(tArrayProv &listaProveedores);
void parte1(tArrayProv &listaProveedores);
int buscarCif(tArrayProv &listaProveedores, string cif);
void mostrarIntervalo(tArrayProv &listaProveedores, int minimo, int maximo);
void totalesXclase(tArrayProv &listaProveedores);

int main() {
	tArrayProv listaProveedores;
	leerFichero(listaProveedores);
	system("PAUSE");
}
int menu(){
	int opcion = -1;
	while (opcion < 0 || opcion > 3){
		cout << "--------------MENU DEL PROGRAMA-------------\n"
			<< "1. Nuevo pedido\n"
			<< "2. Proveedores con numero de pedido en un intervalo\n"
			<< "3. Gastos por clase de proveedor\n"
			<< "0. Salir\n";
		cin >> opcion;
	}
	return opcion;
}
int buscarCif(tArrayProv &listaProveedores,string cif){
	int posicion = -1;
	for (int i= 0; i < NP; i++){
		if (listaProveedores[i].cif == cif){ posicion= i; }
	}
	return posicion;
}
void leerFichero(tArrayProv &listaProveedores){
	ifstream proveedores;
	tproveedor proveedorActual;
	string cif;
	double factura;
	int posicion = 0;
	int i = 0;
	char aux;
	int opcion;
	int minimo;
	int maximo;
	proveedores.open("proveedores.txt");
	if (!proveedores.is_open()){
		cout << "Archivo inexistente. No se ha podido cargar la lista\n";
	}
	else{
		proveedores >> proveedorActual.cif;
		while ((proveedorActual.cif != "X") && i < NP){
			proveedores >> proveedorActual.clase;
			proveedores >> proveedorActual.pedidos;
			proveedores >> proveedorActual.gasto;
			proveedores.get(aux);
			listaProveedores[i] = proveedorActual;
			i++;
			proveedores >> proveedorActual.cif;
		}
		proveedores.close();
		if (i != NP){ cout << "Archivo incorrecto, menos proveedores.\n"; }
		else {
			opcion = menu();
			switch (opcion){
			case 0: {}break;
			case 1:	{
						cout << "Introduzca el cif:\n";
						cin >> cif;
						posicion =buscarCif(listaProveedores, cif);
						if (posicion == -1){
							cout << "Cif eroneo. No existe proveedores\n";
						}
						else{
							cout << "Introduce una factura:\n";
							cin >> factura;
							listaProveedores[posicion].gasto = listaProveedores[posicion].gasto + factura;
							listaProveedores[posicion].pedidos++;
						}
			}break;
			case 2: {
						cout << "Introduzca el minimo de pedidos:\n";
						cin >> minimo;
						cout << "Introduzca el maximo de pedidos:\n";
						cin >> maximo;
						mostrarIntervalo(listaProveedores, minimo, maximo);
			}break;

			case 3: {totalesXclase(listaProveedores); }break;
			}
			}

		}

	}
void mostrarIntervalo(tArrayProv &listaProveedores, int minimo, int maximo){
	for (int t = 0; t < NP; t++){
		if ((listaProveedores[t].pedidos > minimo)
			&& (listaProveedores[t].pedidos <= maximo)){
			cout << listaProveedores[t].cif << setw(3)
				<< listaProveedores[t].clase << setw(3)
				<< listaProveedores[t].pedidos << setw(3)
				<< listaProveedores[t].gasto << endl;
		}
	}
}
void totalesXclase(tArrayProv &listaProveedores){
	double papeleriaTotal = 0;
	double alimentacionTotal = 0;
	double limpiezaTotal = 0;
	double informaticaTotal = 0;

	for (int t = 0; t < NP; t++){
		if (listaProveedores[t].clase == "papeleria"){
			papeleriaTotal = papeleriaTotal + listaProveedores[t].gasto;
		}
		if (listaProveedores[t].clase == "alimentacion"){
			alimentacionTotal = alimentacionTotal + listaProveedores[t].gasto;
		}
		if (listaProveedores[t].clase == "limpieza"){
			limpiezaTotal = limpiezaTotal + listaProveedores[t].gasto;
		}
		if (listaProveedores[t].clase == "informatica"){
			informaticaTotal = informaticaTotal + listaProveedores[t].gasto;
		}
	}
	cout << "Papeleria    " << papeleriaTotal << endl;
	cout << "Alimentacao  " << alimentacionTotal << endl;
	cout << "Limpieza     " << limpiezaTotal << endl;
	cout << "Informatica  " << informaticaTotal << endl;
}
