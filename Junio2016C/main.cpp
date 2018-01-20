#include "ListaPeliculas.h";
int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tLista lista = vacia();
	cout << "Introduce el nombre del archivo: \n";
	string n;
	cin >> n;
	cargarLP(lista,n);

	cout << "Lista por actor\n";
	string actor;
	cin >> actor;
	tLista nueva = filtrarPorActor(lista, actor);
	if (nueva.cont == 0){
		cout << "Error no existe tal actor\n";
	}
	else {
		ordenarValoracion(nueva);
		mostarLP(nueva);
	}
	destruirLP(lista);
	system("PAUSE");
}