
#include "ListaTemas.h";
bool cargarL(tListaTemas &listaT){
	ifstream archivo;
	cout << "Introduce el nombre del archivo: \n";
	string nombreArchivo;
	cin >> nombreArchivo;
	archivo.open(nombreArchivo);
	if (!archivo.is_open()){
		return false;
	}
	else {
		char aux;
		listaT.contador = 0;
		int cantidad;
		archivo >> cantidad;
		archivo.get(aux);
		temaPtr actual = new tTema;
		for (int i = 0; i < cantidad; i++){
			getline(archivo, actual->titulo);
			getline(archivo, actual->interprete);
			archivo >> actual->seg;
			listaT.arrayTemas[listaT.contador] = actual;
			archivo.get(aux);
			listaT.contador++;
			actual = new tTema;
		}
		archivo.close();
		return true;
	}
}
void destruir(tListaTemas &listaT){
	delete[] listaT.arrayTemas;
	listaT.contador = 0;
}