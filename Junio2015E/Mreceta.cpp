#include "Mreceta.h";

tListaRecetas crea(){
	tListaRecetas lista;
	lista.cont = 0;
	lista.cap = 20;
	lista.componentes = new tComponente[MAXC];
	return lista;
}

void insertarC(tListaRecetas &listaR, tComponente comp){
	if (listaR.cont >= listaR.cap){
		cout << "Imposoble, receta llena \n";
	}
	else {

		listaR.componentes[listaR.cont] = comp;
		listaR.cont++;
	}
}

void muestraC(const tListaRecetas &listaR){
	double total = 0;
	for (int i = 0; i < listaR.cont; i++){
		cout << listaR.componentes[i].gramos << "  " <<
			listaR.componentes[i].puntero->nombre << endl;
		total = total + (listaR.componentes[i].puntero->calorias * listaR.componentes[i].gramos);
	}
	cout << "Total Calorias:" << total << endl;
	
}

void destruirMEM(tListaRecetas &listaR, tLista &listaIngr){
	for (int i = 0; i < listaIngr.cont; i++){
		delete listaIngr.tArray[i];
	}
	delete[] listaR.componentes;
}