
#include "Reparto.h";
void cargarR(tReparto &reparto, ifstream &archivo, int numActores){
	reparto.cont = 0;
	for (int i = 0; i < numActores; i++){
		getline(archivo,reparto.actores[i]);
		reparto.cont++;
	}
}
bool aparece(const tReparto &reparto, string actor, int ini,int fin){
	bool encontrado = false;
	int pos= -1;
	if (ini <= fin){
		int mitad= (ini+ fin)/2;
		if (actor == reparto.actores[mitad]){
			pos= mitad;
		}
		else if (actor < reparto.actores[mitad]){
			pos= aparece(reparto, actor, ini, mitad-1);
		}
		else{
			pos = aparece(reparto, actor, mitad + 1, fin);
		}
	}
	if (reparto.actores[pos] == actor){
		encontrado = true;
	}
	return encontrado;
}
int buscar(const tReparto &reparto, string nombre){
	//dado un nombre devuelve pos
	int pos = -1;
	for (int i = 0; i < reparto.cont; i++){
		if (nombre == reparto.actores[i]){
			pos = i;
		}
	}
	return pos;
}
