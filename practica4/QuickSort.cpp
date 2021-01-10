	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 3: Complejidades temporales polinomiales y no polinomiales.
		PROFESOR: Benjamín Luna Benoso
		FECHA: 27-11-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int p, int r){	//función partition (Divide el arreglo que se pasa como parametro en 2 sub arreglos)
	int x = A[r];	//ultima posición del vector (privote)
	int i = p-1;
	int aux;
	for(int j=p; j<=r-1; j++){	
		if(A[j] <= x){		//si A[j] es <= pivote
			i++;			//aumenta la posición de i, que servirá de auxiliar para conocer la nueva posición de pivote
			aux = A[i];		//intercambiamos A[i] con A[j]
			A[i] = A[j];
			A[j] = aux;
		}
	}
	aux = A[i+1];	//intercambiamos al final el valor de A[i+1] con A[r] que significa que ahora pivote está en esa posición
	A[i+1] = A[r];
	A[r] = aux;
	return i+1;		//regresamos la posición de pivote
}

void quickSort(vector<int> &A, int p, int n){ //Función quickSort, la cual se divide recursivamente en 2 subarreglos hasta tener tamaño 1
	if(p<n){		//mientras el arreglo sea de tamaño mayor que 1
		int q = partition(A, p, n);		//obten el nuevo arreglo partition y la posición de pivote
		quickSort(A, q+1, n);		//ahora ordena para el subarreglo de la derecha
		quickSort(A, p, q-1);		//ahora ordena para el subarreglo de la izquierda
	}
}

int main(){
	int n;
	cout << "input size of vector: ";
	cin >> n;
	vector<int> A(n);
	cout << "input vector: ";
	for (int i=0; i<n; i++){
		cin >> A[i];
	}

	quickSort(A, 0, n-1);	//llamada a la función quickSort, la cual ordena el arreglo

	for(int i=0; i<n; i++){	//Se manda a imprimir el arreglo ya ordenado
		cout << A[i] << " ";
	} cout << endl;
	return 0;
}