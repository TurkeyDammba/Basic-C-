/*
Apellidos: Morcillo Salgado
Nombre: Borja
DNI: 70271734H
Puesto: 208
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int N = 10;//par y positivo

typedef struct {
	string eqp;
	int puntos;
}tParticipante;

typedef tParticipante tLParticipantes[N];

typedef struct{
	string eqp1;
	string eqp2;
	int gol1;
	int gol2;
}tPartido;

typedef tPartido tLPartidos[N / 2];

// PROTOTIPOS  
int menu();
bool cargarLiga(tLParticipantes &participantes);
bool cargarJornada(tLPartidos &partidos, tLParticipantes const participantes);
void mostrarLiga(tLParticipantes const participantes);
void mostrarJornada(tLPartidos const partidos);
int buscarEqp(string eqp, tLParticipantes const participantes);
void actualizarLiga(tLPartidos const partidos, tLParticipantes &participantes);
void mostrarPrimero(tLParticipantes const participantes);
void guardarLiga(tLParticipantes const participantes);

// PROGRAMA PRINCIPAL
int main() {
	tLParticipantes participantes;
	tLPartidos partidos;
	bool clasifCargada = false;
	bool jornadaCargada = false;
	int opc;
	do
	{
		opc = menu();

		if (opc != 0)
		{
			switch (opc){//codigo de cada una de las opciones
			case 1: { 
				if (cargarLiga(participantes)){
					clasifCargada = true;
				} else {
					cout << "no se puede cargar liga.txt\n";
				}
			break; } //carga de datos de la clasificacion

			case 2: { 
				if (clasifCargada){//Necesario para la comprobacion de equipos repetidos
					if (cargarJornada(partidos, participantes)){
						jornadaCargada = true;
					} else {
						cout << "no se puede cargar la jornada\n";
					}
				} else {
					cout << "Clasificacion no cargada\n";
				}
			break; } //carga de datos de la jornada

			case 3: { 
				if (clasifCargada){
					mostrarLiga(participantes);
				} else { 
					cout << "Clasificacion no cargada\n"; 
				}
			break; } //mostrar en pantalla la clasificacion

			case 4: {
				if (jornadaCargada){
					mostrarJornada(partidos);
				} else {
					cout << "Jornada no cargada\n";
				}
			break; } //mostrar en pantalla la jornada

			case 5: { 
				if (jornadaCargada && clasifCargada){
					actualizarLiga(partidos, participantes);
				} else {
					cout << "Jornada o clasificacion no cargada\n";
				}
			break; } //actualizar la clasificacion con la jornada

			case 6: { 
				if (clasifCargada){
					mostrarPrimero(participantes);
				} else {
					cout << "Clasificacion no cargada\n";
				}
			break; } //mostrar el primer clasificado

			case 7: {
				if (clasifCargada){
					guardarLiga(participantes);
				} else {
					cout << "Clasificacion no cargada\n";
				}
			break; } //guardar en un fichero la clasificacion actual

			default: { cout << "No deberia suceder esto nunca\n"; };
			}
		}
		cout << "Pulsa una tecla para continuar...\n";
		cin.get();
	} while (opc != 0);

	cout << "Adios" << endl;
	cin.get();

	return 0;
}

// CODIGO DE LOS SUBPROGRAMAS
int menu(){
	int opc;
	do {
		system("cls");
		cout << "Introduzca un numero entre 0 y 7:\n";
		cout << "1.Cargar clasificacion.\n";
		cout << "2.Cargar jornada.\n";
		cout << "3.Mostrar clasificacion.\n";
		cout << "4.Mostrar jornada.\n";
		cout << "5.Actualizar clasificacion.\n";
		cout << "6.Mostrar primero en la clasificacion.\n";
		cout << "7.Guardar clasificacion.\n";
		cout << "0.Salir.\n";
		cin.clear(); cin.sync();
		cin >> opc;
	} while (!cin.fail() && opc < 0 && opc > 7);
	cin.sync();
	return opc;
}

bool cargarLiga(tLParticipantes &participantes){
	bool ok = false;
	ifstream file;
	file.open("liga.txt");
	if (file.is_open()){
		for (int i = 0; i < N; i++){
			file >> participantes[i].eqp;
			file >> participantes[i].puntos;
		}
		ok = true;
		file.close();
	}
	return ok;
}

bool cargarJornada(tLPartidos &partidos, tLParticipantes const participantes){
	bool ok = false;
	ifstream file;
	file.open("jornada.txt");
	if (file.is_open()){
		//Asignaremos las veces que aparece cada equipo a las posiciones
		//del array contadorApariciones
		int contadorApariciones[N];
		for (int i = 0; i < N; i++){
			contadorApariciones[i] = 0;
		}

		for (int i = 0; i < N/2; i++){
			file >> partidos[i].eqp1;
			int posEqp1 = buscarEqp(partidos[i].eqp1, participantes);
			contadorApariciones[posEqp1]++;
			file >> partidos[i].gol1;

			file >> partidos[i].eqp2;
			int posEqp2 = buscarEqp(partidos[i].eqp2, participantes);
			contadorApariciones[posEqp2]++;
			file >> partidos[i].gol2;

			if (contadorApariciones[posEqp2] > 1 || contadorApariciones[posEqp1] > 1){
				cout << "Error! hay equipos repetidos en la jornada\n";
				return false;
			}
		}
		ok = true;
	} else {
		cout << "Imposible abrir jornada.txt\n";
	}
	return ok;
}

void mostrarLiga(tLParticipantes const participantes){
	int max_longitud = 8;
	int max_puntos = 3;
	cout << "CLASIFICACION: \n\n";
	for (int i = 0; i < N; i++) {
		cout << left << setw(max_longitud) << participantes[i].eqp << " | ";
		cout << setw(max_puntos) << participantes[i].puntos << "\n";
	}
}

void mostrarJornada(tLPartidos const partidos){
	int max_longitud = 8;
	int max_goles = 2;
	for (int i = 0; i < N/2; i++) {
		cout << "PARTIDO " << i+1 << "\n";
		cout << right << setw(max_longitud) << partidos[i].eqp1 << " vs ";
		cout << left << setw(max_longitud) << partidos[i].eqp2 << "\n";
		cout << "Resulado: " << right << setw(max_goles) << partidos[i].gol1 << "-";
		cout << left << partidos[i].gol2 << "\n\n";
	}
}

int buscarEqp(string eqp, tLParticipantes const participantes){
	int pos = -1;
	int i = -1;
	do {
		i++;
		if (participantes[i].eqp == eqp){
			pos = i;
		}
	} while (pos == -1 && i < N);
	return pos;
}

void actualizarLiga(tLPartidos const partidos, tLParticipantes &participantes){
	for (int i = 0; i < N / 2; i++){
		int eqp1 = buscarEqp(partidos[i].eqp1, participantes);
		int eqp2 = buscarEqp(partidos[i].eqp2, participantes);

		if (partidos[i].gol1 == partidos[i].gol2){
			participantes[eqp1].puntos++;
			participantes[eqp2].puntos++;
		} else if (partidos[i].gol1 > partidos[i].gol2){
			participantes[eqp1].puntos = participantes[eqp1].puntos + 3;
		} else {
			participantes[eqp2].puntos = participantes[eqp2].puntos + 3;
		}
	}
}

void mostrarPrimero(tLParticipantes const participantes){
	string primero;
	int maxPuntos = 0;
	for (int i = 0; i < N; i++){
		if (maxPuntos < participantes[i].puntos){
			maxPuntos = participantes[i].puntos;
			primero = participantes[i].eqp;
		}
	}
	cout << "El primer equipo en la clasificacion es: " << primero << "\n";
}

void guardarLiga(tLParticipantes const participantes){
	ofstream file;
	file.open("liga.txt");
	if (file.is_open()){
		for (int i = 0; i < N; i++){
			file << participantes[i].eqp << " ";
			file << participantes[i].puntos << "\n";
		}
		file.close();
	} else {
		cout << "Error al abrir liga.txt\n";
	}
}