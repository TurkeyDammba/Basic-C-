#include "listaIngr.h";


void carga(tLista &listIngr, string nombreArchivo){
	ifstream archivo;
	archivo.open(nombreArchivo);
	if (!archivo.is_open()){
		cout << "ERROR EN EL ARCHIVO";
	}
	else {
		tIngrPtr actual;
		actual = new tIngrediente;
		listIngr.cont = 0;
		char c;
		archivo >> actual->calorias;
		while (listIngr.cont < MAX && actual->calorias != -1){
			archivo.get(c);
			getline(archivo,actual->nombre);
			listIngr.tArray[listIngr.cont] = actual;
			actual = new tIngrediente;
			listIngr.cont++;
			archivo >> actual->calorias;
		}
		//tras cargar todos los alimentos ordenmos la lista
		for (int i = 1; i< listIngr.cont; i++){
			int pos = i;
			while (pos > 0 && listIngr.tArray[pos - 1]->nombre > listIngr.tArray[pos]->nombre){
				tIngrPtr tmp = listIngr.tArray[pos - 1];
				listIngr.tArray[pos - 1] = listIngr.tArray[pos];
				listIngr.tArray[pos] = tmp;
				pos--;
			}
		}
	}
}

void insertar(tLista &listaIngr){
	tIngrPtr nuevo = new tIngrediente;
	cout << "Nombre: ";
	cin >> nuevo->nombre;
	cout << "Calorias: ";
	cin >> nuevo->calorias;
	if (listaIngr.cont < MAX){
		//buscamos hueco
		int pos = -1;
		for (int i = 0; i < listaIngr.cont; i++){
			if (listaIngr.tArray[i] > nuevo){
				pos = i - 1; //devuelve la pos donde deberia estar
			}
		}
		//abrimos hueco
		for (int i = pos; i < listaIngr.cont; i++){
			listaIngr.tArray[i+1] = listaIngr.tArray[i];
		}
		listaIngr.cont++;
		//introducimos nuevo ingrdiente
		listaIngr.tArray[pos] = nuevo;
	}
}

string selectIngred(const tLista &listIngr){
	for (int i = 0; i < listIngr.cont; i++){
		cout << i+1 << "-" << listIngr.tArray[i]->nombre << "  " << listIngr.tArray[i]->calorias << "\n";
	}
	cout << "Introduce un numero";
	int numero = 0;
	cin >> numero;
	while (numero < 0 && numero > listIngr.cont){
		cout << "Numero no valido, reintroduzca \n";
		cin >> numero;
	}
	return listIngr.tArray[numero - 1]->nombre;
}

int buscar(const tLista &listIngr, string nombre, int ini, int fin){
	int pos=-1;
	if (ini <= fin)
	{
		int mitad= (ini+ fin)/2;
		if (nombre == listIngr.tArray[mitad]->nombre){
			pos = mitad;
	}
		else if (nombre < listIngr.tArray[mitad]->nombre){
			pos= buscar(listIngr, nombre, ini, mitad-1);
		}
		else{
			pos= buscar(listIngr, nombre, mitad+1, fin);
		}
	}
	return pos;
}

void destruirL(tLista &listaIngr){
	listaIngr.cont =0;
	delete[] listaIngr.tArray;
}