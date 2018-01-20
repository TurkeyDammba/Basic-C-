#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int NPO = 8;
const int NPN = 2;

typedef struct {
	string nombre;
	double peso;
	double precio;
}tproducto;
typedef tproducto tArrayproducto[NPO];
typedef struct {
	string nombre;
	double cantidad;
}tcompra;
typedef tcompra tArraycompra[NPN];

void leerFichero(tArrayproducto &listaProducto, bool &ok);
void muestraLista(tArrayproducto &listaProducto);
void guardarFichero(tArrayproducto &listaProducto);
void leerCesta(tArraycompra &listaCesta);
int buscarProducto(tArrayproducto &listaProducto, string buscado);
void realizarCompra(tArrayproducto &listaProducto, tArraycompra &listaCesta);
void muestraAgotados(tArrayproducto &listaProducto);
int menu();

int main(){
	tArrayproducto listaProductos;
	bool exito;
	leerFichero(listaProductos, exito);
	if (exito == false){ cout << "Error"; }
	else{
		muestraLista(listaProductos);
	}

	system("PAUSE");

}
void leerFichero(tArrayproducto &listaProducto, bool &ok){
	ifstream archivo;
	tproducto producto;
	char c;
	int i = 0;
	archivo.open("almacen.txt");
	if (!archivo.is_open()){ ok = false; }
	else{
		getline(archivo, producto.nombre);
		while ((producto.nombre != "XXX") && (i < NPO)){
			archivo >> producto.peso;
			archivo >> producto.precio;
			listaProducto[i] = producto;
			i++;
			archivo.get(c);
			getline(archivo, producto.nombre);
		}
		if (i < NPO){ ok = false; }
	}
	archivo.close();
}
void muestraLista(tArrayproducto &listaProducto){
	for (int i = 0; i < NPO; i++){
		cout << listaProducto[i].nombre << "   "
			<< listaProducto[i].peso << "   "
			<< listaProducto[i].precio << endl;
	}
}
