#include "Estudiante.h";

void cargarE(ifstream &archivo, tEstudiante &estudiante){
	char aux;
	getline(archivo, estudiante.nombre);
	archivo >> estudiante.nif;
	archivo >> estudiante.fecha;
	archivo >> estudiante.nota;
	archivo.get(aux);
}
void mostrar(const tEstudiante &estudiante){
	cout << estudiante.nif << "  -  " << estudiante.fecha <<
		" -  " << setw(3) << estudiante.nombre << endl;
}