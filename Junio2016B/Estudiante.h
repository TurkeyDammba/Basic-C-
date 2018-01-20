#ifndef Estudiante_h
#define Estudiante_h
//BIBLIOTECAS A UTILIZAR
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//ESTRUCTURAS
typedef struct{
	string nombre;
	string nif;
	string fecha;
	double nota;
}tEstudiante;

//PROTOTIPOS
void cargarE(ifstream &archivo, tEstudiante &estudiante);
void mostrar(const tEstudiante &estudiante);
#endif