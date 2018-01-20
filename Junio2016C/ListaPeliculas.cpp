#include "ListaPeliculas.h";

tLista vacia(){
	tLista vacia;
	vacia.cont = 0;
	return vacia;
}
void cargarLP(tLista &lista, string nombreArchivo){
	ifstream archivo;
	archivo.open(nombreArchivo);
	if (!archivo.is_open()){
		cout  << "ERROR ARCHIVO LOKOOOOOOOOO \n";
	}
	else {
		char auz;
		int numPelis;
		archivo >> numPelis;
		archivo.get(auz);
		for (int i = 0; i < numPelis; i++){
			lista.peliculas[i] = new tPelicula;
			cargar(*lista.peliculas[i], archivo);
			lista.cont++;
		}
		archivo.close();
	}

}
void mostarLP(const tLista &lista){
	for (int i = 0; i < lista.cont; i++){
		mostrar(*lista.peliculas[i]);
	}
}
void ordenarGenero(tLista &lista){
	int pos;
	tPeliPtr tmp;
		for (int i = 1; i< lista.cont; i++){
			pos = i;
			while (pos > 0 && lista.peliculas[pos - 1]->genero > lista.peliculas[pos]->genero){
				tmp = lista.peliculas[pos - 1];
				lista.peliculas[pos - 1] = lista.peliculas[pos];
				lista.peliculas[pos] = tmp;
					pos--;
			}
	}
}
void ordenarValoracion(tLista &lista){
	int pos;
	tPeliPtr tmp;
	for (int i = 1; i < lista.cont; i++){
		pos = i;
		while ((pos > 0) && (lista.peliculas[pos - 1]->valoracion > lista.peliculas[pos]->valoracion)){
			tmp = lista.peliculas[pos];
			lista.peliculas[pos] = lista.peliculas[pos - 1];
			lista.peliculas[pos - 1] = tmp;
			pos--;
		}
	}
}
tLista filtrarPorActor(const tLista &lista, string actor){
	tLista nueva = vacia();
	int  esta;
	for (int i = 0; i < lista.cont; i++){
		esta = buscar(lista.peliculas[i]->reparto, actor);
		if (esta != -1){
			nueva.peliculas[nueva.cont] = lista.peliculas[i];
			nueva.cont++;
		}
	}
	return nueva;
}
void destruirLP(tLista &lista){
	for (int i = 0; i < lista.cont; i++){
		delete lista.peliculas[i];
	}
}