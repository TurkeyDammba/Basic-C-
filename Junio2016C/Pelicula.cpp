#include "Pelicula.h";

void cargar(tPelicula &pelicula, ifstream &archivo){
	char aux;
	getline(archivo, pelicula.titulo);
	getline(archivo, pelicula.director);
	getline(archivo, pelicula.genero);
	archivo >> pelicula.valoracion;
	archivo.get(aux);
	int numActores = 0;
	archivo >> numActores;
	archivo.get(aux);
	cargarR(pelicula.reparto, archivo, numActores);
}
bool interviene(const tPelicula &pelicula, string actor){
	bool encontrado = aparece(pelicula.reparto, actor, 0,pelicula.reparto.cont);
	return encontrado;
}
void mostrar(const tPelicula &pelicula){
	cout << "Titulo:   " << pelicula.titulo << endl;
	cout << "Director:   " << pelicula.director << endl;
	cout << "Genero:   " << pelicula.genero << endl;
	cout << "Valoracion:   " << pelicula.valoracion << endl;
	cout << "----\n";
}