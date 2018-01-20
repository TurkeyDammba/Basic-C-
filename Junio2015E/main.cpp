#include "Mreceta.h";
int menu();
int main(){
	tLista lista;
	lista.cont = 0;
	string archivo;
	tListaRecetas listaR;
	tComponente comp;
	//cargamos los ingredientes
	cout << "Introduce nombre de archivo";
	cin >> archivo;
	carga(lista, archivo);
	listaR = crea();
	int opc = menu();
	while (opc != -1){
		switch (opc){
		case 0:{
				   destruirMEM(listaR, lista);
				   return 0;/*borrar memoria */}
		case 1:{
				   comp =leeComponente(lista);
				   insertarC(listaR,comp);
		}break;
		case 2: {
					muestraC(listaR);
		}break;
		}
		opc = menu();
	}

	system("PAUSE");
}
int menu(){
	int opc = -1;
	while (opc < 0 || opc > 2){
		cout << "------MENU DEL PROGRAMA----------\n";
		cout << "0.Salir \n" << "1.Anadir ingrediente\n" << "2. Mostrar receta\n";
		cin >> opc;
	}
	return opc;
}