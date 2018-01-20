#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//CONSTANTES GLOBALES
const int NUM_FILAS = 8;
const int NUM_COLUMNAS = 10;

typedef enum tCasilla{Vacia,O,S};
typedef tCasilla tMatriz[NUM_FILAS][NUM_COLUMNAS];
typedef struct {
	string jugador;
	int marcador;
}tJugador;


//SUPORGRAMAS
void inicializar(tMatriz &tablero);
void pedirjugada(tMatriz &tablero);
void mostrar(const tMatriz &tablero);
int hacerJugada(const tMatriz &tablero, int fila, int columna, char ficha);

int main(){
	tMatriz tablero;
	inicializar(tablero);
	int turno = 0;
	tJugador jugador1;
	tJugador jugador2;
	jugador1.marcador = 0;
	jugador2.marcador = 0;
	cout << "Nombre de J1:\n";
	cin >> jugador1.jugador;
	cout << "Nombre de J2:\n";
	cin >> jugador2.jugador;
	int fila;
	int columna;
	bool tFicha;
	char ficha;
	bool ganador = false;
	while (ganador == false){
		cout << "Turno de :";
		if (turno % 2 == 0){
			cout << jugador1.jugador << endl;
			pedirjugada(tablero);
			mostrar(tablero);
			cout << "Introduce jugada (fila, columna, ficha):\n";
			cin >> fila;
			fila = fila + 1;
			cin >> columna;
			columna = columna + 1;
			while (tFicha == false){
				cout << "Introduce tipo de fichar: \n";
				cin >> ficha;
				if (ficha != 'O' && ficha != 'S'){
					tFicha = false;
				}
				else {
					tFicha = true;
				}
			}
			switch (ficha){
			case 'O': {tablero[fila][columna] = O; }break;
			case 'S': {tablero[fila][columna] = S; }break;
			}
			jugador1.marcador = jugador1.marcador +hacerJugada(tablero, fila, columna, ficha);
			turno++;
		}
		else {
			cout << jugador2.jugador << endl;
			pedirjugada(tablero);
			mostrar(tablero);
			cout << "Introduce jugada (fila, columna, ficha):\n";
			cin >> fila;
			fila = fila + 1;
			cin >> columna;
			columna = columna + 1;
			while (tFicha == false){
				cout << "Introduce tipo de fichar: \n";
				cin >> ficha;
				if (ficha != 'O' && ficha != 'S'){
					tFicha = false;
				}
				else {
					tFicha = true;
				}
			}
			switch (ficha){
			case 'O': {tablero[fila][columna] = O; }break;
			case 'S': {tablero[fila][columna] = S; }break;
			}
			jugador2.marcador = jugador2.marcador + hacerJugada(tablero, fila, columna, ficha);
			turno++;
		}
		if (turno > 9 && jugador1.marcador > jugador2.marcador) {
			cout << "Vencedor:" << jugador1.jugador;
		}
		else if(turno > 9 && jugador1.marcador < jugador2.marcador) {
			cout << "Vencedor:" << jugador2.jugador;
		}
		else if (turno > 9 && jugador1.marcador > jugador2.marcador) {
			cout << "EMPATE:";
		}
	}
	system("PAUSE");
}

void inicializar(tMatriz &tablero){
	for (int i = 0; i < NUM_FILAS; i++){
		for (int t = 0; t < NUM_COLUMNAS; t++){
			tablero[i][t] = Vacia;
		}
	}
}
void pedirjugada(tMatriz &tablero){
	bool valido = false;
	bool tFicha = false;
	int columna;
	int fila;
	char ficha;
	while (tFicha == false){
		cout << "Introduce tipo de fichar: \n";
		cin >> ficha;
		if (ficha != 'O' && ficha != 'S'){
			tFicha = false;
		}
		else {
			tFicha = true;
		}
	}

	while (valido == false){
		cout << "Introduce la fila a colocar ficha (entre 1-8):\n";
		cin >> fila;
		fila = fila + 1;
		cout << "Introduce la columna a colocar ficha(entre1-10):\n";
		cin >> columna;
		columna = columna + 1;
		if (tablero[fila][columna] != Vacia){
			valido = false;
		}
		else {
			switch (ficha){
			case 'O': {tablero[fila][columna] = O; }break;
			case 'S': {tablero[fila][columna] = S; }
			}
			valido = true;
		}
	}
}
void mostrar(const tMatriz &tablero){
	for (int i = 0; i < NUM_FILAS; i++){
		for (int t = 0; t < NUM_COLUMNAS; t++){
			if (tablero[i][t] == Vacia){
				cout << "| ";
			}
			if (tablero[i][t] == O){
				cout << "|O";
				if (tablero[i][t] == O){
					cout << "|S";
				}
			}
		}
	
		cout << "\n";
	}
}
int hacerJugada(const tMatriz &tablero, int fila, int columna,char ficha){
	int numVeces = 0;
	//Si la ficha seleccionada es una "S"
	if (ficha == S){
		//1)ARRIBA O ABAJO
		if (fila + 1 < NUM_FILAS && fila - 1 >= 0){
			if (tablero[fila + 1][columna] == O && tablero[fila - 1][columna] == O){
				numVeces++;
			}
		}
		//1)DEREC O IZQ
		if (columna + 1 < NUM_COLUMNAS && columna - 1 >= 0){
			if (tablero[fila][columna + 1] == O && tablero[fila][columna - 1] == O){
				numVeces++;
			}
		}
		//1)ARRIBA Y DEREC && ABAJO IZQ
		if ((fila + 1 < NUM_FILAS && fila - 1 >= 0) && (columna + 1 < NUM_COLUMNAS && columna - 1 >= 0)){
			if (tablero[fila + 1][columna + 1] == O && tablero[fila - 1][columna - 1] == O){
				numVeces++;
			}
		}
		//1)DEREC O IZQ
		if ((fila + 1 < NUM_FILAS && fila - 1 >= 0) && (columna + 1 < NUM_COLUMNAS && columna - 1 >= 0)){
			if (tablero[fila + 1][columna - 1] == O && tablero[fila - 1][columna + 1] == O){
				numVeces++;
			}
		}
	}
	else{ //ficha es "O"
		// ARRIBA
		if (fila + 2 < NUM_FILAS){
			if (tablero[fila + 1][columna] == S && tablero[fila + 2][columna] == O){
				numVeces++;
			}
		}
		// ABAJO
		if (fila - 2 >= 0){
			if (tablero[fila - 1][columna] == S && tablero[fila - 2][columna] == O){
				numVeces++;
			}
		}
		// IZQ
		if (columna - 2 >= 0){
			if (tablero[fila][columna + -1] == S && tablero[fila][columna + -2] == O){
				numVeces++;
			}
		}
		//DEREC
		if (columna + 2 < NUM_COLUMNAS){
			if (tablero[fila][columna + 1] == S && tablero[fila][columna + 2] == O){
				numVeces++;
			}
		}
		//ARRIBA-DEREC
		if (columna + 2 < NUM_COLUMNAS && fila + 2 < NUM_FILAS){
			if (tablero[fila + 1][columna + 1] == S && tablero[fila + 2][columna + 2] == O){
				numVeces++;
			}
		}
		//ARRIBA-IZQ
		if (columna -2  < NUM_COLUMNAS && fila + 2 < NUM_FILAS){
			if (tablero[fila + 1][columna + -1] == S && tablero[fila + 2][columna + -2] == O){
				numVeces++;
			}
		}
		//ABAJO-DEREC
		if (columna + 2 < NUM_COLUMNAS && fila - 2 < NUM_FILAS){
			if (tablero[fila - 1][columna + 1] == S && tablero[fila - 2][columna + 2] == O){
				numVeces++;
			}
		}
		//ABAJO-IZQ
		if (columna - 2 < NUM_COLUMNAS && fila - 2 < NUM_FILAS){
			if (tablero[fila - 1][columna - 1] == S && tablero[fila - 2][columna - 2] == O){
				numVeces++;
			}
		}
		return numVeces;
	}
}
