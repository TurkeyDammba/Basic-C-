#include "ListaEstudiantes.h";

void cargar(ifstream &archivo, tListaEstudiantes &listaE){
	int numEs = 0;
	char aux;
	archivo >> numEs;
	archivo.get(aux);
	tEstudiante actual;
	listaE.cont = 0;
	listaE.estudiantes = new tEstudiante[numEs];
	for (int i = 0; i < numEs; i++){
		cargarE(archivo, listaE.estudiantes[i]);
		listaE.cont++;
	}
}
void ordenar(tListaEstudiantes &listaE){
	bool inter = true;
	int i = 0;
	while (i < listaE.cont && inter){
		inter = false;
		for (int j = listaE.cont - 1; j > i; j--){
			if (listaE.estudiantes[j].nif <listaE.estudiantes[j - 1].nif){
				tEstudiante tmp = listaE.estudiantes[j];
				listaE.estudiantes[j] = listaE.estudiantes[j - 1];
				listaE.estudiantes[j - 1] = tmp;
				inter = true;
			}
		}
		if (inter){
			i++;
		}
	}
}
bool buscar(const tListaEstudiantes &listaE, string nif){
	bool encontrado = false;
	int pos = 0;
	int ini = 0;
	int fin = listaE.cont - 1;
	while (ini <= fin && !encontrado){
		int mit = ini + fin / 2;
		if (listaE.estudiantes[mit].nif == nif){
			pos = mit;
			encontrado = true;
		}
		else if (listaE.estudiantes[mit].nif < nif){
			ini = mit + 1;
		}
		else if (listaE.estudiantes[mit].nif > nif){
			fin = mit - 1;
		}
	}
	return encontrado;
}
void insertar(tListaEstudiantes &listaE, tEstudiante actual){
	if (listaE.cont < MAXE){
		int i = 0;
		int pos = -1;
		while (i < listaE.cont && pos != -1){
			if (listaE.estudiantes[i].nif < actual.nif){
				pos = i;
			}
		}
		//lo ha encontrado hacemos hueco
		listaE.cont++;
		for (int i = listaE.cont; i > pos; i--){
			listaE.estudiantes[i-1] = listaE.estudiantes[i];
		}
		listaE.estudiantes[pos] = actual;
	}
	else {
		cout << "No hay espacio\n";
	}

}
void mostrar(const tListaEstudiantes &listaE){
	for (int i = 0; i < listaE.cont; i++){
		mostrar(listaE.estudiantes[i]);
	}
}
void destruir(tListaEstudiantes &listaE){
	delete[]listaE.estudiantes;
}