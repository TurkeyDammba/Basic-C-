
#include "ListaGrupos.h";
int main(){
	cout << "Introduce el nombre del archivo: \n";
	string arc;
	cin >> arc;
	tListaGrupos grupos;
	bool ok = true;

	cargar(grupos, arc, ok);
	if (!ok){
		cout << "No se encontro " << arc << endl;
	}
	else {
		for (int i = 0; i < grupos.cont; i++){
			ordenar(grupos.listaP[i]->listaAl);
		}
		mostrar(grupos);
		cout << "Introduzca un NIF\n";
		string nif;
		cin >> nif;
		string donde = buscar(grupos, nif, 0);
		if (donde == ""){
			cout << "HA MUERTO ESTUDIANDO MDL\n";
		}
		else {
			cout << "Se encuentra en el grupo: " << donde << "\n";
			destruir(grupos);
		}
	}

	system("PAUSE");
}