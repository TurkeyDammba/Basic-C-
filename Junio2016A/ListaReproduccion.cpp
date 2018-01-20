
#include "ListaReproduccion.h";
#include <ctime>
#include <stdlib.h>;
tListaRep nueva(string nombre, int cap){
	tListaRep nueva;
	nueva.nombre = nombre;
	nueva.arrayD = new tElemento[cap];
	nueva.cap = cap;
	nueva.cont = 0; 
	return  nueva;
}

void insertar(tListaRep &listaR, tElemento elemento){
	if (listaR.cont >= listaR.cap){
		cout << "ERROR , LISTA LLENA\n";
	}
	else {
		listaR.arrayD[listaR.cont] = elemento;
	}
}

bool buscar(const tListaRep &listaR, string titulo, int pos){
	bool encontrado = false;
	for (int i = pos; i < listaR.cont; i++){
		if (listaR.arrayD[i].puntero->titulo == titulo){
			encontrado = true;
		}
	}
	return encontrado;
}

void mostrarL(const tListaRep &listaR){
	int total = 0;
	cout << "Nombre de la lista: " << listaR.nombre << endl;
	for (int i = 0; i < listaR.cont; i++){
		mostrar(*listaR.arrayD[i].puntero);
		total = total + listaR.arrayD[i].puntero->seg;
	}
	cout << "TOTAL TIEMPO: " << total << endl;;
}

void modificarOrden(tListaRep &listaR, int org, int dest){
	//crearmos un array analogo, copiamos los elementos de atras adelante
	tElemento *nuevo= new tElemento[listaR.cont]; // array dinamico
	for (int i = 0; i < listaR.cont; i++){
		int j = listaR.cont - 1;
		nuevo[j] = listaR.arrayD[i];
		j--;
	}

	//copiamos el array creado en el anterior y lo borramos

	for (int i = 0; i < listaR.cont; i++){
		listaR.arrayD[i] = nuevo[i];
	}
	
	delete[] nuevo;
}

void creaListaRep(tListaRep & listaR, const tListaTemas &listaT){
	int num;
	//usamos numeros aleatorios para seleccionar temas
	for (int i = 0; i < listaR.cap; i++){
		num = rand()%listaT.contador;
		tElemento actual;
		actual.puntero = listaT.arrayTemas[num];
		actual.valoracion = rand() % 10;
		listaR.arrayD[i] = actual;
		listaR.cont++;
	}
}

void destruir(tListaRep &lista){
	delete[] lista.arrayD;
	lista.cont = 0;
	lista.cap = 0;
	lista.nombre = "";
}