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
		FECHA: 02/12/2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/

#include <stdio.h>
#include <stdlib.h>

void Merge(int *A, int p, int q, int r) { 
	int n1=q-p+1; 
	int n2=r-q; 
	int L[n1],R[n2]; 
	int i,j,k;
	
	for (i=0;i<n1;i++){ 
		L[i]= A[p+i]; 
	}
	for (j=0;j<n2;j++){
		R[j]= A[q+1+j]; 
	}

	i=0;	
	j=0;
	for(k=p;k<r;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}else{
			A[k]=R[j];
			j++;
		}
	}

//pa' que i y j lleguen a n1 y n2 respectivamente
	while(i<n1){ 
		A[k]=L[i]; 
		i++; 
		k++; 
	} 
	while(j<n2){ 
		A[k]=R[j]; 
		j++; 
		k++; 
	} 
	
} 

void imprimeCad(int A[], int tam) { 
	int i; 
	for (i=0;i<tam;i++){ 
		printf("%d ", A[i]); 
	}
	printf("\n"); 
} 
