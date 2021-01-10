	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: MergeSort
		PROFESOR: Benjamín Luna Benoso
		FECHA: 02-12-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/


#include "merge.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void MergeSort(int *A, int p, int r){ 
	if (p<r){ 
		int q=(p+r)/2; 
		MergeSort(A,p,q); 
		MergeSort(A,q+1,r); 
		Merge(A,p,q,r); 
	} 
} 

int main(){ 
	int num,i,cadena[50];
	printf("Ingrese la longitud de la cadena:\n");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		cout<<"Ingrese el elemento "<<i+1<<": ";	
		cin>>cadena[i];
	}
	
	MergeSort(cadena,0,num-1); 	
	printf("\nArreglado \n"); 
	imprimeCad(cadena, num); 
	return 1; 
} 
