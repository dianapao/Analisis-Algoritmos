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
#include "perfecto.h"
using namespace std;

int MostrarPerfectos(int n){
	int cont=0;
	int aux=1;
	cout<<"Numeros perfectos: \n";
	while(cont!=n){
		if(perfecto(aux)==1){
			cont++;
			cout<<aux<<", ";
		}
		aux++;
	}
	return 1;
}

int main(){
	int n;
	cout<<"Ingrese n\n";
	cin>>n;
	MostrarPerfectos(n);
}