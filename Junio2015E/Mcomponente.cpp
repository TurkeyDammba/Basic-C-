#include "Mcomponente.h";

tComponente leeComponente(tLista &listaIngr){
	tComponente actual;
	string nombre;
	nombre = selectIngred(listaIngr);
	actual.puntero = new tIngrediente;
	int pos = buscar(listaIngr, nombre, 0, listaIngr.cont - 1);
	if (pos == -1){
		cout << "Ingrediente no encontrado\n";
	}
	else {
		actual.puntero = listaIngr.tArray[pos];
		cout << "Cuantos gramos";
		cin >> actual.gramos;
	}
	return actual;
}
void muestra(tComponente &actual){
	cout << actual.gramos << "  "<< actual.puntero->nombre << "\n";
}