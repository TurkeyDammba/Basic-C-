#include "ListaGrupos.h";

void cargar(tListaGrupos &listaG, string nomArchivo, bool &ok){
	ifstream archivo;
	archivo.open(nomArchivo);
	if (!archivo.is_open()){
		ok = false;
	}
	else {
		tGrupoPtr actual = new tGrupo;
		tListaEstudiantes aux;
		listaG.cont = 0;
		char c;
		archivo >> actual->ident;
		archivo.get(c);
		int i = 0;

		while (actual->ident != "XXX"  && i < MAXG){
			cargar(archivo, aux);
			actual->listaAl = aux;
			listaG.listaP[i] = actual;
			actual = new tGrupo;
			listaG.cont++;
			archivo >> actual->ident;
			i++;
		}
	}
}
void mostrar(const tListaGrupos &listaG){
	for (int i = 0; i < listaG.cont; i++){
		cout << "----------------------------\n";
		cout << "Grupo: " << listaG.listaP[i]->ident << endl;
		mostrar(listaG.listaP[i]->listaAl);
	}
}
string buscar(const tListaGrupos &listaG, string nif, int pos){
	string loc = "";
	bool encontrado = false;
	int i = pos;
	while(!encontrado && i <listaG.cont){
		int j = 0;
		while (!encontrado && j < listaG.listaP[i]->listaAl.cont){
			encontrado =buscar(listaG.listaP[i]->listaAl, nif);
			if (encontrado){
				loc = listaG.listaP[i]->ident;
			}
			else {
				pos = pos++;
				buscar(listaG, nif, pos);
			}
			j++;
		}
		i++;
	}
	return loc;
}
void destruir(tListaGrupos &listaG){
	for (int i = 0; i < listaG.cont; i++){
		destruir(listaG.listaP[i]->listaAl);
		delete listaG.listaP[i];
	}
}
