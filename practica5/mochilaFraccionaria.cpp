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
		FECHA: 10-12-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/
#include<bits/stdc++.h>
using namespace std;
//Esta función partition ordena de forma ascendente
int partition(vector<pair<double,int>> &A, int p, int r){	//función partition (Divide el arreglo que se pasa como parametro en 2 sub arreglos)
	double x = A[r].first;	//primer valor de la ultima posición del vector (privote)
	int i = p-1;
	double aux;
	int auxIndice;
	for(int j=p; j<=r-1; j++){	
		if(A[j].first >= x){		//si el 1er valor de A[j] es >= pivote
			i++;			//aumenta la posición de i, que servirá de auxiliar para conocer la nueva posición de pivote
			aux = A[i].first;		//intercambiamos A[i] con A[j] tanto en su primero como segundo valor
			auxIndice = A[i].second;
			A[i].first = A[j].first;
			A[i].second = A[j].second;
			A[j].first = aux;
			A[j].second = auxIndice;
		}
	}
	aux = A[i+1].first;	//intercambiamos al final el valor de A[i+1] con A[r] que significa que ahora pivote está en esa posición
	auxIndice = A[i+1].second;
	A[i+1].first = A[r].first;
	A[i+1].second = A[r].second;
	A[r].first = aux;
	A[r].second = auxIndice;
	return i+1;		//regresamos la posición de pivote
}

void quickSort(vector<pair<double,int>> &A, int p, int n){ //Función quickSort, la cual se divide recursivamente en 2 subarreglos hasta tener tamaño 1
	if(p<n){		//mientras el arreglo sea de tamaño mayor que 1
		int q = partition(A, p, n);		//obten el nuevo arreglo partition y la posición de pivote
		quickSort(A, q+1, n);		//ahora ordena para el subarreglo de la derecha
		quickSort(A, p, q-1);		//ahora ordena para el subarreglo de la izquierda
	}
}

vector<pair<double, int>> sortSeleccion(vector<int> b, vector<int> w){		//funcion para ordernar el que tenga mas valor x unidad de peso
	int n = b.size();	
	vector<pair<double,int>> x;		//en este vector se va a almacenar la el valor x unidad de peso en el orden que viene
	for(int i=0; i<n; i++){
		double BW = double(b[i])/double(w[i]);
		x.push_back( make_pair(BW, i) );
	}
	quickSort(x,0,n-1);		//se ordena de manera ascendente para escoger al que tenga mayor valor x unidad de peso
    return x; 
}

//función que regresa el indice en donde originalmente se encuentra en los vectores de entrada (objeto Xi).
int seleccion(vector<pair<double,int>> valorPorPeso, int i){	
	return valorPorPeso[i].second;
}

vector<double> mochilaFraccionaria(vector<int> b, vector<int> w, int p){
	vector<pair<double,int>> valorPorPeso;		//vector para obtener la seleccion valor x unidad de peso ordenada en forma decreciente
	valorPorPeso = sortSeleccion(b,w);
	int n = b.size();
	vector<double> x(n,0);		//vector que regresará el porcentaje que se ocupo del objeto Xi
	int s=0, i=0, k;
	while(s<p && i<n){		//mientras no se llene la mochila y aún haya objetos por escoger 
		k = seleccion(valorPorPeso, i);		//deuelve la posición del objeto Xi seleccionado
		i++;
		if( (s+w[k] )<= p){		//si el peso es menor que el limite
			s += w[k];
			x[k] = 1;		//ponemos que se ocupo 100% del objeto Xi
		}else{
			x[k] = (double((p-s)))/double(w[k]);  //Marcamos el porcentaje fraccionable que se ocupo del objeto Xi
			s = p;	//Indicamos que la mochila se llenó
		}
	}
	return x;
}

int main(){
	int n, p;
	cout << "Ingresa el peso maximo de la mochila: "; cin >> p;
	cout << "Input la cantidad de objetos: "; cin >> n;
	cout << "Ingresa los n Objetos; primero su valor y despues su peso: " << endl;
	vector<int> b(n);
	vector<int> w(n);
	for(int i=0; i<n; i++){
		cin >> b[i];
		cin >> w[i];
	}
    
    cout << endl << "Output:" << endl;
    vector<double> x;
    x = mochilaFraccionaria(b,w,p);
    for(int i=0; i<n; i++){
    	cout << x[i] << "   ";
    } cout << endl;

	return 0;
}