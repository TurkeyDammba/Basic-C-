#include "ListaDias.h";
int main(){
	string archivo;
	bool ok = true;
	tListaDias listaD;
	cout << "Introduce el nombre del archivo: \n";
	cin >> archivo;
	carga(listaD, archivo, ok);
	if (ok == false){
		cout << "ERROR \n";
	}
	else {
		muestra(listaD);
	}
	system("PAUSE");
}