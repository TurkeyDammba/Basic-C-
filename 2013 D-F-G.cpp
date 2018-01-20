#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
const int CENTINELA = -1;
int menu();
void generar(int elementos, int maximo);
void recorrer();
int productocifras(int num);
bool esRavenclaw(int num);
void buscar();
int main(){
	int objetos = 0;
	int mayor = 0;
	int opcion = 0;
	opcion = menu();
	while (opcion != 4){
		switch (opcion){
		case 0: {return 0; } break;
		case 1: {
					cout << "Introduce el numero de elementos"
						<< "que deba tener la secuencia y el maximo entero" << endl;
					cin >> objetos;
					cin >> mayor;
					generar(objetos, mayor);
		} break;
		case 2: {recorrer(); } break;
		case 3: {buscar(); }  break;
		}
		opcion = menu();
	}
}

int menu(){
	int opcion = -1;
	while (opcion < 0 || opcion > 3){
		cout << "--------------MENU DEL PROGRAMA--------------\n"
			<< "1. Generar la secuencia\n"
			<< "2. Procesar la secuencia\n"
			<< "3. Buscar la secuencia\n"
			<< "0. Salir del programa\n";
		cin >> opcion;
	}

	return opcion;

}
void generar(int elementos, int maximo){
	ofstream datos;
	datos.open("datos.txt");
	int num = 1;
	int cont = 1;
	while (num < maximo && cont <= elementos ){
		datos << num << endl;
		num = num +397; // para generar enteros aleatorios
		cont++;
	}
	datos << CENTINELA;
	datos.close();
	menu();
}
void recorrer(){
	ifstream datos2;
	datos2.open("datos2.txt");
	if (!datos2.is_open()){ cout << "No se ha generado la secuencia\n"; }
	int num = 0;
	datos2 >> num;
	while (num != -1){
		esRavenclaw(num);
		cout << num;
		if (esRavenclaw(num) == true){ cout << "Si es de Ravenclaw\n"; }
		else{ cout << "No es de Ravenclaw\n"; }
		datos2 >> num;
	}
	datos2.close();
}
int productocifras(int unidad){
	int producto = 1;
	int cifra = 0;
	while (unidad > 0){
		cifra = unidad % 10;
		producto = producto *cifra;
		unidad = unidad / 10;
	}
	
	return producto;
}
bool esRavenclaw(int objeto){
	int valor = productocifras(objeto);
	int valorAct = 0;
	while (valor > 9){
		valor = productocifras(valor);
	}
	if (valor == 8){ return true; }
	else { return false; }
}
void buscar(){
	ifstream datos;
	datos.open("datos2.txt");
	if (!datos.is_open()){ cout << "No se ha generado la secuencia\n"; }
	int errorUsuario = 0;
	cout << "Introduce el error: \n";
	cin >> errorUsuario;
	int suma = 0;
	int num = 0;
	int num2 = 0;
	bool encontrado = false;
	while (encontrado == false){
		suma = suma + num;
		datos >> num;
		if (suma >  num- errorUsuario && suma >  num + errorUsuario){ encontrado = true; }

	}

	if (encontrado == true){ cout << num << "suma" << suma << endl; }
	datos.close();
	menu();
}