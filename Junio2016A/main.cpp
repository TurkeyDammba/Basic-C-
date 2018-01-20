#include "ListaReproduccion.h";
int main(){
	tListaTemas listaT;
	//1)cargamos los archivos en la lista
	bool cargado = cargarL(listaT);
	if (cargado == false){
		cout << "Error en el archivo, adios\n";
	}
	else {
		//2)Solicitamos datos y creamos listaRep
		cout << "Introduce el nombre de la nueva lista(una palabra): \n";
		string newName;
		cin >> newName;
		cout << "Introduce el numero temas: \n";
		int num;
		cin >> num;
		tListaRep listaR;
		listaR = nueva(newName, num);

		creaListaRep(listaR, listaT);
		mostrarL(listaR);
		//funcion aleatoria
		//eliminamos memoria
		//destruir(listaT);
		destruir(listaR);
	}
	system("PAUSE");

}