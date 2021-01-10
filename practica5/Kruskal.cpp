	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 5: Algoritmos Greedy
		PROFESOR: Benjamín Luna Benoso
		FECHA: 11/12/2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/

#include <iostream>
using namespace std;

class Arco {
public:
	int origen, destino, longitud;
};

class Grafo {
public:
	int num_nodos, num_arcos;
	Arco* arco;
};

class ConexoDestino{
public:
	int componente;
	int rango;
};

Grafo *CrearGrafo(int nodo, int arco){
	Grafo *grafo = new Grafo;
	grafo->num_nodos = nodo;
	grafo->num_arcos = arco;
	grafo->arco=new Arco[arco];
	return grafo;
}

Grafo *peticiones(){
	int NodoOrigen, NodoDestino, arco, num_nodos=0, num_arcos=0, i=0;
	cout<<"Ingrese el numero de nodos a ocupar\n";
	cin>>num_nodos;
	cout<<"Ingrese el numero de arcos a ocupar\n";
	cin>>num_arcos;

	Grafo *grafo=CrearGrafo(num_nodos,num_arcos);
	while(num_arcos>0){
		cout<<"Ingrese el Nodo de origen: ";	cin>>NodoOrigen;
		cout<<"Ingrese el Nodo de destino: ";	cin>>NodoDestino;	
		cout<<"Ingrese el arco: ";				cin>>arco;

		grafo->arco[i].origen=NodoOrigen;
		grafo->arco[i].destino=NodoDestino;
		grafo->arco[i].longitud=arco;
		num_arcos--;
		i++;
	}
	return grafo;
}

void imprimir(Arco resultado[], int num_soluciones){
	cout<<"Grafo minimo\n";
	for (int i = 0; i < num_soluciones; ++i){
	cout <<"Nodo Origen: "<<resultado[i].origen<<"; nodo destino: "<<resultado[i].destino<<"; longitud: "<<resultado[i].longitud<<"\n";
	}
}

int encontrar(ConexoDestino conexo[], int indice){
	if (conexo[indice].componente != indice)												//puntero->atributo
		conexo[indice].componente=encontrar(conexo, conexo[indice].componente);				//(*puntero).atributo
	return conexo[indice].componente;
}

void unir(ConexoDestino conexo[], int u, int v){
	int raizU = encontrar(conexo, u);
	int raizV = encontrar(conexo, v);
	if (conexo[raizU].rango < conexo[raizV].rango)		//Se queda con el mayor rango
		conexo[raizU].componente = raizV;
	else if (conexo[raizU].rango > conexo[raizV].rango)
		conexo[raizV].componente = raizU;
	else{
		conexo[raizV].componente = raizU;
		conexo[raizU].rango++;
	}
}

int comparar(const void* a, const void* b){		//Comparación de 2 arcos de acuerdo con su longitud
	Arco* a1 = (Arco*)a;
	Arco* b1 = (Arco*)b;
	return a1->longitud > b1->longitud;
}

void Kruskal(Grafo* grafo, int nodos){
	Arco resultado[nodos]; 
	int num_soluciones = 0; 
	int arcos_seleccionados=0;

	qsort(grafo->arco, grafo->num_arcos, sizeof(grafo->arco[0]),comparar);		
		//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
		//base   -> De donde se parte
		//nitems -> Número de elementos
		//size   -> tamaño en bits de cada elemento en el arreglo
		//compar -> función que compara 2 elementos

	ConexoDestino* conexo = new ConexoDestino[(nodos * sizeof(ConexoDestino))];

	// Creación de la fila de prioridad
	for (int j=0;j<nodos;j++){
		conexo[j].componente = j;
		conexo[j].rango=0;
	}
	
	while (num_soluciones<nodos-1 && arcos_seleccionados<grafo->num_arcos){
		Arco arco_actual = grafo->arco[arcos_seleccionados++];
		int u = encontrar(conexo, arco_actual.origen);
		int v = encontrar(conexo, arco_actual.destino);
		if (u!=v) {																// si u!=v, entonces no causa un ciclo el arco actual
			resultado[num_soluciones++]=arco_actual;
			unir(conexo,u,v);
		}
	}
	 imprimir(resultado, num_soluciones);
}

int main(){
	Grafo *grafo;
	grafo=peticiones();
	Kruskal(grafo,grafo->num_nodos);
	return 1;
}

