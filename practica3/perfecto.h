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
		FECHA: 08-11-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/

#include <iostream>
using namespace std;

int perfecto(int n){
	int suma=0;
	int aux=1;
	while(aux!=n){
		if(n%aux == 0){
			suma=suma+aux;
		}
		aux++;
	}
	if(suma==n){
		return 1;
	}else{
		return 0;
	}
}
