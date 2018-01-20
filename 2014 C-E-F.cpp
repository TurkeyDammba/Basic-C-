#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_PLAYERS = 6;

typedef struct{
	string nombre;
	string codigo;
	int partidos;
	int minutos;
	int goles;
}tjugador;
typedef tjugador tArrayjugadoro[NUM_PLAYERS];
typedef struct {
	tArrayjugadoro jugadoro;
	int contado;
}tlistaJ;

void cargar(tlistaJ &listajugadoro, bool &ok);
void muestra(tlistaJ &listajugadoro);
int menu();
void filtrarLista(tlistaJ &listajugadoro);
void actualizarJugador(tlistaJ &listajugadoro);
int buscarGoleador(tlistaJ &listajugadoro);
void consultarMaxGoleador(tlistaJ &listajugadoro);

int main(){
	tlistaJ listajugadoro;
	int opcion = 0;
	bool exito;
	cargar(listajugadoro, exito);
	if (exito == false){
		cout << "Archivo no valido\n";
		return 0;
	}

	opcion = menu();
	while(opcion != -1){
		switch (opcion){
		case 0: {return 0; }break;
		case 1: {filtrarLista(listajugadoro); }break;
		case 2: {actualizarJugador(listajugadoro);
			muestra(listajugadoro);
		}break;
		case 3: {consultarMaxGoleador(listajugadoro); }break;
		}
		opcion = menu();
	}


}


int menu(){
	int opcion = -1;
	while (opcion < 0 || opcion >3){
		cout << "--------------------MENU DEL PROGRAMA--------------\n"
			<< "1. Filtrar lista\n"
			<< "2. Actualizar jugador\n"
			<< "3. Consultar maximo goleador\n"
			<< "0. Salir\n";
		cin >> opcion;
	}
	return opcion;
}
void cargar(tlistaJ &listajugadoro, bool &ok){
	ifstream players;
	tjugador personaje;
	listajugadoro.contado = 0;
	char aux;
	int i = 0;
	ok = true;
	players.open("players.txt");
	if (!players.is_open()){
		cout << "Error. Archivo inexistente\n";
		ok = false;
		}
	else{
		
		players >> personaje.nombre;
		while ((personaje.nombre != "XXX") && (i < NUM_PLAYERS)){
			players >> personaje.codigo;
			players >> personaje.partidos;
			players >> personaje.minutos;
			players >> personaje.goles;
			players.get(aux);
			listajugadoro.jugadoro[i] = personaje;
			if (listajugadoro.jugadoro[i].partidos < 0 || listajugadoro.jugadoro[i].minutos < 0
				|| listajugadoro.jugadoro[i].goles < 0){
				ok = false;
			}
			if (listajugadoro.jugadoro[i].minutos / 90 > listajugadoro.jugadoro[i].partidos){
				ok = false;
			}
			if ((listajugadoro.jugadoro[i].minutos > 0) && (listajugadoro.jugadoro[i].partidos = 0)){
				ok = false;
			}
			if ((listajugadoro.jugadoro[i].goles > 0) && (listajugadoro.jugadoro[i].partidos = 0)){
				ok = false;
			}
			i++;
			listajugadoro.contado++;
			players >> personaje.nombre;
		}
		if (listajugadoro.contado < NUM_PLAYERS){ ok = false; }
	}
	players.close();
}
void muestra(tlistaJ &listajugadoro){
	for (int i = 0; i < NUM_PLAYERS; i++){
		cout << listajugadoro.jugadoro[i].nombre << "   " << listajugadoro.jugadoro[i].codigo << "   "
			<< listajugadoro.jugadoro[i].partidos << "   " << listajugadoro.jugadoro[i].minutos << "   "
			<< listajugadoro.jugadoro[i].goles << endl;
	}
}
void filtrarLista(tlistaJ &listajugadoro){
	string clase;
	cout << "Introduzca las siglas del euipo que desee:\n";
	cin >> clase;
	for (int i = 0; i < NUM_PLAYERS; i++){
		if (listajugadoro.jugadoro[i].codigo == clase){
			cout << listajugadoro.jugadoro[i].nombre << endl;
		}
		if (clase == "TODOS"){
			cout << listajugadoro.jugadoro[i].nombre << endl;
		}
		if (clase != "ATM" || clase != "RMA" || clase != "BCN" || clase != "RBF"){
		}
	}
}
void actualizarJugador(tlistaJ &listajugadoro){
	int nuevoGol;
	int nuevominuto;
	string nombre;
	bool encontrado = false;
	bool error = false;
	cout << "Introduce el nombre del hugador a actualizar:\n";
	cin >> nombre;
	cout << "Introduce los minutos :\n";
	cin >> nuevominuto;
	cout << "Introduce el numero de goles:\n";
	cin >> nuevoGol;
	for (int i = 0; i < NUM_PLAYERS; i++){
		if (listajugadoro.jugadoro[i].nombre != nombre){
			encontrado = false;
		}
		else{
			if (nuevoGol < 0 || nuevominuto < 0){
				error = false;
			}
			else{
				error = true;
				listajugadoro.jugadoro[i].goles = listajugadoro.jugadoro[i].goles + nuevoGol; 
				listajugadoro.jugadoro[i].minutos = listajugadoro.jugadoro[i].minutos + nuevominuto;
			}
		}
	}
	if (encontrado = false){ cout << "Error, jugador no encontradop\n"; }
	if (error = false){ cout << "Datos erroneos"; }
}
void consultarMaxGoleador(tlistaJ &listajugadoro){
	int posicion = 0;
	posicion =buscarGoleador(listajugadoro);
	for (int i = 0; i < NUM_PLAYERS; i++){
		if (listajugadoro.jugadoro[i].goles >= listajugadoro.jugadoro[posicion].goles){
			cout << listajugadoro.jugadoro[i].nombre << "  "
				<< listajugadoro.jugadoro[i].codigo << "  "
				<< listajugadoro.jugadoro[i].partidos << "  "
				<< listajugadoro.jugadoro[i].minutos << "  "
				<< listajugadoro.jugadoro[i].goles << "  \n";
				
		}
	}
}
int buscarGoleador(tlistaJ &listajugadoro){
	int actual= 0;
	for (int i = 0; i < NUM_PLAYERS; i++){
		if (listajugadoro.jugadoro[i].goles > actual){ actual = i; }
	}
	return actual;
}
